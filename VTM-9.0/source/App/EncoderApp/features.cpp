#include "features.h"

ofstream features::file_features;
ofstream features::file_target;
ofstream features::file_pixel;
double   features::frameWidth;
double   features::frameHeight;
int      features::qp;
string   features::videoName;
int      features::previousCTUsize;
int      features::maxWidth;
int      features::maxHeight;
int      features::current_x;
int      features::current_y;
int***   features::CTUFrame;
int      features::tlMaxDepth[2];
int      features::tMaxDepth[2];
int      features::trMaxDepth[2];
int      features::lMaxDepth[2];
int      features::previousMaxDepth[2];
int      features::averageDepth[2];
int      features::modeDepth[2];
int      features::highestDepth[2];
double   features::interIMVRDCost;
double   features::interRDCost;
double   features::affineMergeRDCost;
double   features::cachedResultRDCost;
double   features::mergeRDCost;
double   features::mergeGeoRDCost;
double   features::intraRDCost;
unsigned short  features::CTUPixel[128][128];

features::features(string m_videoName, int m_iQP, double m_iSourceWidth, double m_iSourceHeight)
{ 
  videoName             = m_videoName;
  qp                    = m_iQP;
  frameWidth            = m_iSourceWidth;
  frameHeight           = m_iSourceHeight;

  previousCTUsize       = 0;
  maxWidth              = ceil(frameWidth/128);
  maxHeight             = ceil(frameHeight/128);
  current_x             = 0;
  current_y             = 0;

  tlMaxDepth[0]         = -1;
  tMaxDepth[0]          = -1;
  trMaxDepth[0]         = -1;
  lMaxDepth[0]          = -1;
  previousMaxDepth[0]   = -1;
  averageDepth[0]       = -1;
  modeDepth[0]          = -1;
  highestDepth[0]       = -1; 

  tlMaxDepth[1]         = -1;
  tMaxDepth[1]          = -1;
  trMaxDepth[1]         = -1;
  lMaxDepth[1]          = -1;
  previousMaxDepth[1]   = -1;
  averageDepth[1]       = -1;
  modeDepth[1]          = -1;
  highestDepth[1]       = -1; 

  interIMVRDCost        = MAX_DOUBLE;
  interRDCost           = MAX_DOUBLE;
  affineMergeRDCost     = MAX_DOUBLE;
  cachedResultRDCost    = MAX_DOUBLE;
  mergeRDCost           = MAX_DOUBLE;
  mergeGeoRDCost        = MAX_DOUBLE;
  intraRDCost           = MAX_DOUBLE;

  createFile();
  CTUFrame              = initCTUFrame();
}

void features::createFile()
{
  //file_features.open("features/dataset_" + videoName + "_" + to_string(qp) + "_features.csv", ios::app);
  //file_target.open("target/dataset_" + videoName + "_" + to_string(qp) + "_target.csv", ios::app);
  file_pixel.open("pixel/dataset_" + videoName + "_" + to_string(qp) + "_pixel.csv", ios::app);

  /*file_features << "videoname,paramQP,frameWidth,frameHeight,CU_width,CU_height,topLeft_x,topLeft_y,bottomRight_x,bottomRight_y,"
                << "depth,qtdepth,mtdepth,qp,predMode,skip,mmvdSkip,affine,affineType,colorTransform,geoFlag,bdpcmMode,"
                << "bdpcmModeChroma,imv,rootCbf,mipFlag,modeType,modeTypeSeries,splitSeries,cost,dist,fracBits,baseQP,prevQP,"
                << "currQP,lumaCost,POC,opts,maxCostAllowed,tlMaxQTDepth,tMaxQTDepth,trMaxQTDepth,lMaxQTDepth,previousMaxQTDepth,averageQTDepth,modeQTDepth,highestQTDepth,"
                << "tlMaxMTDepth,tMaxMTDepth,trMaxMTDepth,lMaxMDepth,previousMaxMTDepth,averageMTDepth,modeMTDepth,highestMTDepth,interIMVRDCost,"
                << "interRDCost,affineMergeRDCost,cachedResultRDCost,mergeRDCost,mergeGeoRDCost,intraRDCost,splitType" << endl; */

  file_pixel << "videoname,paramQP,frameWidth,frameHeight,CU_width,CU_height,topLeft_x,topLeft_y,bottomRight_x,bottomRight_y,qtdepth,mtdepth,"
             << "variance,mean,gradientH,gradientV,ratioGrad,quarterVariance1,quarterVariance2,quarterVariance3,quarterVariance4,quarterMean1,quarterMean2,"
             << "quarterMean3,quarterMean4,quarterGradH1,quarterGradV1,quarterGradH2,quarterGradV2,quarterGradH3,quarterGradV3,quarterGradH4,quarterGradV4,"
             << "ratioGrad1,ratioGrad2,ratioGrad3,ratioGrad4" << endl;

  //file_target << "videoname,paramQP,frameWidth,frameHeight,CU_width,CU_height,topLeft_x,topLeft_y,bottomRight_x,bottomRight_y,POC,qtdepth,mtdepth,"
  //            << "PartSplit,RDCost" << endl;
}


void features::extractFeatures(CodingUnit* cu, CodingStructure* cs, EncTestMode currTestMode)
{
  interIMVRDCost                        = (interIMVRDCost     == MAX_DOUBLE)    ? -1 : interIMVRDCost;
  interRDCost                           = (interRDCost        == MAX_DOUBLE)    ? -1 : interRDCost;
  affineMergeRDCost                     = (affineMergeRDCost  == MAX_DOUBLE)    ? -1 : affineMergeRDCost;
  cachedResultRDCost                    = (cachedResultRDCost == MAX_DOUBLE)    ? -1 : cachedResultRDCost;
  mergeRDCost                           = (mergeRDCost        == MAX_DOUBLE)    ? -1 : mergeRDCost;
  mergeGeoRDCost                        = (mergeGeoRDCost     == MAX_DOUBLE)    ? -1 : mergeGeoRDCost;
  intraRDCost                           = (intraRDCost        == MAX_DOUBLE)    ? -1 : intraRDCost;

  file_features                         <<
  videoName                             << "," <<
  qp                                    << "," <<
  frameWidth                            << "," <<        
  frameHeight                           << "," <<         
  int(cu->lwidth())                     << "," <<
  int(cu->lheight())                    << "," <<
  int(cu->Y().topLeft().x)              << "," <<
  int(cu->Y().topLeft().y)              << "," << 
  int(cu->Y().bottomRight().x)          << "," <<
  int(cu->Y().bottomRight().y)          << "," <<
  int(cu->depth)                        << "," <<
  int(cu->qtDepth)                      << "," <<
  int(cu->mtDepth)                      << "," <<
  int(cu->qp)                           << "," <<
  int(cu->predMode)                     << "," <<
  cu->skip                              << "," <<
  cu->mmvdSkip                          << "," <<
  cu->affine                            << "," <<
  cu->affineType                        << "," <<
  cu->colorTransform                    << "," <<
  cu->geoFlag                           << "," <<
  cu->bdpcmMode                         << "," <<
  cu->bdpcmModeChroma                   << "," <<
  int(cu->imv)                          << "," <<
  cu->rootCbf                           << "," <<
  cu->mipFlag                           << "," <<
  int(cu->modeType)                     << "," <<
  int(cu->modeTypeSeries)               << "," <<
  int(cu->splitSeries)                  << "," <<
  int(cs->cost)                         << "," <<
  int(cs->dist)                         << "," <<
  int(cs->fracBits)                     << "," << 
  int(cs->baseQP)                       << "," <<
  int(*cs->prevQP)                      << "," <<  
  int(*cs->currQP)                      << "," <<
  int(cs->lumaCost)                     << "," <<
  int(cs->picture->getPOC())            << "," <<
  int(currTestMode.opts)                << "," <<
  int(currTestMode.maxCostAllowed)      << "," << 
  tlMaxDepth[QT]                        << "," <<
  tMaxDepth[QT]                         << "," <<
  trMaxDepth[QT]                        << "," <<
  lMaxDepth[QT]                         << "," <<
  previousMaxDepth[QT]                  << "," <<
  averageDepth[QT]                      << "," <<
  modeDepth[QT]                         << "," <<
  highestDepth[QT]                      << "," <<
  tlMaxDepth[MT]                        << "," <<
  tMaxDepth[MT]                         << "," <<
  trMaxDepth[MT]                        << "," <<
  lMaxDepth[MT]                         << "," <<
  previousMaxDepth[MT]                  << "," <<
  averageDepth[MT]                      << "," <<
  modeDepth[MT]                         << "," <<
  highestDepth[MT]                      << "," <<
  interIMVRDCost                        << "," << 
  interRDCost                           << "," <<
  affineMergeRDCost                     << "," <<
  cachedResultRDCost                    << "," << 
  mergeRDCost                           << "," <<
  mergeGeoRDCost                        << "," <<
  intraRDCost                           << "," <<
  int(getPartSplit( currTestMode ))     << endl;

  interIMVRDCost                        = MAX_DOUBLE;
  interRDCost                           = MAX_DOUBLE;
  affineMergeRDCost                     = MAX_DOUBLE;
  cachedResultRDCost                    = MAX_DOUBLE;
  mergeRDCost                           = MAX_DOUBLE;
  mergeGeoRDCost                        = MAX_DOUBLE;
  intraRDCost                           = MAX_DOUBLE;

}

void features::extractTarget(CodingStructure* cs, CodingUnit* cu, EncTestMode currTestMode, bool before)
{
  if (before)
  {
    file_features                     <<
    videoName                         << "," <<
    qp                                << "," <<
    frameWidth                        << "," <<        
    frameHeight                       << "," <<         
    int(cu->lwidth())                 << "," <<
    int(cu->lheight())                << "," <<
    int(cu->Y().topLeft().x)          << "," <<
    int(cu->Y().topLeft().y)          << "," << 
    int(cu->Y().bottomRight().x)      << "," <<
    int(cu->Y().bottomRight().y)      << "," <<
    int(cs->picture->getPOC())        << "," <<
    int(cu->qtDepth)                  << "," <<
    int(cu->mtDepth)                  << "," <<
    int(getPartSplit(currTestMode))   << "," <<
    int(cs->cost)                     << endl;
  }

  else
  {
    file_target                       <<
    videoName                         << "," <<
    qp                                << "," <<
    frameWidth                        << "," <<        
    frameHeight                       << "," <<         
    int(cu->lwidth())                 << "," <<
    int(cu->lheight())                << "," <<
    int(cu->Y().topLeft().x)          << "," <<
    int(cu->Y().topLeft().y)          << "," << 
    int(cu->Y().bottomRight().x)      << "," <<
    int(cu->Y().bottomRight().y)      << "," <<
    int(cs->picture->getPOC())        << "," <<
    int(cu->qtDepth)                  << "," <<
    int(cu->mtDepth)                  << "," <<
    int(getPartSplit(currTestMode))   << "," <<
    int(cs->cost)                     << endl;
  }
}

int*** features::initCTUFrame()
{

  int*** auxCTUFrame = new int**[4];
  for (int i = 0; i < 4; i++) auxCTUFrame[i] = new int*[maxHeight];
  
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < maxHeight; j++)
    {
      auxCTUFrame[i][j] = new int[maxWidth];
    }
  }

  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < maxHeight; j++)
    {
      for(int k = 0; k < maxWidth; k++)
      {
        auxCTUFrame[i][j][k] = -1;
      }
    }
  }

  return auxCTUFrame;
}

void features::ctuDepth(CodingStructure* cs)
{
  int maxQT = 0;
  int maxMT = 0;

  int currentQT = 0;
  int currentMT = 0;

  for(int i = previousCTUsize; i < cs->cus.size(); i++)
  {
    if (cs->cus[i]->chType == CHANNEL_TYPE_LUMA)
    {
        currentQT = cs->cus[i]->qtDepth;
        currentMT = cs->cus[i]->mtDepth;

        maxQT = (currentQT > maxQT) ? currentQT : maxQT;
        maxMT = (currentMT > maxMT) ? currentMT : maxMT;
    }
  }

  CTUFrame[CURRENT_QT_DEPTH][current_y][current_x] = maxQT;
  CTUFrame[CURRENT_MT_DEPTH][current_y][current_x] = maxMT;


  previousCTUsize = cs->cus.size();

  current_x++;
  if (current_x == maxWidth)
  {
    current_x = 0;
    current_y++;
    if (current_y == maxHeight)
    {
        current_y = 0;
        previousCTUsize = 0;
        updateCTUFrame();
    }    
  }
  neighbors();
}

void features::updateCTUFrame()
{
  for(int i = 0; i < maxHeight; i++)
  {
    for(int j = 0; j < maxWidth; j++)
    {
      CTUFrame[PAST_QT_DEPTH][i][j]     = CTUFrame[CURRENT_QT_DEPTH][i][j];
      CTUFrame[CURRENT_QT_DEPTH][i][j]  = -1;

      CTUFrame[PAST_MT_DEPTH][i][j]     = CTUFrame[CURRENT_MT_DEPTH][i][j];
      CTUFrame[CURRENT_MT_DEPTH][i][j]  = -1;
    }
  }
}

void features::neighbors()
{
  tlMaxDepth[QT]        = (((current_y-1) >= 0) && ((current_x-1) >= 0))            ? CTUFrame[CURRENT_QT_DEPTH][current_y-1][current_x-1]  : -1;
  tMaxDepth[QT]         = ((current_y-1) >= 0)                                      ? CTUFrame[CURRENT_QT_DEPTH][current_y-1][current_x]    : -1;
  trMaxDepth[QT]        = (((current_y-1) >= 0) && ((current_x+1) <= (maxWidth-1))) ? CTUFrame[CURRENT_QT_DEPTH][current_y-1][current_x+1]  : -1;
  lMaxDepth[QT]         = ((current_x-1) >= 0)                                      ? CTUFrame[CURRENT_QT_DEPTH][current_y][current_x-1]    : -1;
  previousMaxDepth[QT]  = CTUFrame[PAST_QT_DEPTH][current_y][current_x];

  tlMaxDepth[MT]        = (((current_y-1) >= 0) && ((current_x-1) >= 0))            ? CTUFrame[CURRENT_MT_DEPTH][current_y-1][current_x-1]  : -1;
  tMaxDepth[MT]         = ((current_y-1) >= 0)                                      ? CTUFrame[CURRENT_MT_DEPTH][current_y-1][current_x]    : -1;
  trMaxDepth[MT]        = (((current_y-1) >= 0) && ((current_x+1) <= (maxWidth-1))) ? CTUFrame[CURRENT_MT_DEPTH][current_y-1][current_x+1]  : -1;
  lMaxDepth[MT]         = ((current_x-1) >= 0)                                      ? CTUFrame[CURRENT_MT_DEPTH][current_y][current_x-1]    : -1;
  previousMaxDepth[MT]  = CTUFrame[PAST_MT_DEPTH][current_y][current_x];

  vector<int> depthQT, depthMT;
  depthQT.insert(depthQT.end(), {tlMaxDepth[QT], tMaxDepth[QT], trMaxDepth[QT], lMaxDepth[QT], previousMaxDepth[QT]});
  depthMT.insert(depthMT.end(), {tlMaxDepth[MT], tMaxDepth[MT], trMaxDepth[MT], lMaxDepth[MT], previousMaxDepth[MT]});

  averageDepth[QT]  = checkAverage(depthQT);
  averageDepth[MT]  = checkAverage(depthMT);

  modeDepth[QT]     = checkMode(depthQT);
  modeDepth[MT]     = checkMode(depthMT);

  highestDepth[QT]  = *max_element(depthQT.begin(), depthQT.end());
  highestDepth[MT]  = *max_element(depthMT.begin(), depthMT.end());

  depthQT.clear();
  depthMT.clear();
}

int features::checkAverage(vector<int> depths)
{
  double average = 0;
  double real_size = 0;

  for(int i = 0; i < depths.size(); i++)
  {
    if(depths[i] != -1)
    {      
      average += depths[i];
      real_size++;
    }
  }

  average = (real_size == 0) ? -1 : round(average / real_size);
  return average;
}

int features::checkMode(vector<int> depths)
{
	vector<int> histogram(depths.size()+1,0);
	for( int i = 0; i < depths.size(); i++)
  {
    if(depths[i] != -1) ++histogram[ depths[i] ];
  }

  return max_element( histogram.begin(), histogram.end() ) - histogram.begin();
}

void features::setInterIMVRDCost(double m_interIMV)
{
  interIMVRDCost = (interIMVRDCost > m_interIMV) ? m_interIMV : interIMVRDCost;
}
void features::setInterRDCost(double m_inter)
{
  interRDCost = (interRDCost > m_inter) ? m_inter : interRDCost;
}
void features::setAffineMergeRDCost(double m_affine)
{
  affineMergeRDCost = (affineMergeRDCost > m_affine) ? m_affine : affineMergeRDCost;
}
void features::setCachedResultRDCost(double m_cached)
{
  cachedResultRDCost = (cachedResultRDCost > m_cached) ? m_cached : cachedResultRDCost;
}
void features::setMergeRDCost(double m_merge)
{
  mergeRDCost = (mergeRDCost > m_merge) ? m_merge : mergeRDCost;
}
void features::setMergeGeoRDCost(double m_geo)
{
  mergeGeoRDCost = (mergeGeoRDCost > m_geo) ? m_geo : mergeGeoRDCost;
}
void features::setIntraRDCost(double m_intra)
{
  intraRDCost = (intraRDCost > m_intra) ? m_intra : intraRDCost;
}

void features::extractCUPixel(CodingStructure* cs, PartSplit split)
{
  int xTL = cs->area.Y().topLeft().x;
  int yTL = cs->area.Y().topLeft().y;
  int xBR = cs->area.Y().bottomRight().x;
  int yBR = cs->area.Y().bottomRight().y;
  
  int height = 0;
  int width = 0;
  int sum = 0;
  int pixelHeight = yBR - yTL + 1;
  int pixelWidth = xBR - xTL + 1;

  for(int y = yTL; y <= yBR; y++)
  {
    for(int x = xTL; x <= xBR; x++)
    {
      CTUPixel[height][width] = cs->picture->getTrueOrigBuf().Y().at(x,y);
      sum += CTUPixel[height][width];
      width++;
    }
    height++;
    width = 0;
  }

  double var = variance(xTL, yTL, xBR, yBR, sum);
  int n = (pixelHeight * pixelWidth);
  double mean = (double) sum / (double) n;
  vector<unsigned short> grads = gradients(xTL, yTL, xBR, yBR);
  double ratioGrads = (double) grads[0] / (double) grads[1];
  vector<double> quarters = quarterCU(xTL, yTL, xBR, yBR, split);

  var += 1; mean += 1; quarters[0] += 1; ratioGrads += 1;
  /*file_pixel                          <<
  videoName                             << "," <<
  qp                                    << "," <<
  frameWidth                            << "," <<        
  frameHeight                           << "," <<         
  int(cs->area.lwidth())                << "," <<
  int(cs->area.lheight())               << "," <<
  int(cs->area.Y().topLeft().x)         << "," <<
  int(cs->area.Y().topLeft().y)         << "," << 
  int(cs->area.Y().bottomRight().x)     << "," <<
  int(cs->area.Y().bottomRight().y)     << "," <<
  int(cs->cus[0]->qtDepth)              << "," <<
  int(cs->cus[0]->mtDepth)              << "," << 
  var                                   << "," << 
  mean                                  << "," << 
  grads[0]                              << "," << 
  grads[1]                              << "," << 
  ratioGrads                            << ",";

  if (split == CU_QUAD_SPLIT)
  {
    file_pixel <<
    quarters[0] << "," <<
    quarters[5] << "," <<
    quarters[10] << "," <<
    quarters[15] << "," <<
    quarters[1] << "," <<
    quarters[6] << "," <<
    quarters[11] << "," <<
    quarters[16] << "," <<
    quarters[2] << "," <<
    quarters[7] << "," <<
    quarters[12] << "," <<
    quarters[17] << "," <<
    quarters[3] << "," <<
    quarters[8] << "," <<
    quarters[13] << "," <<
    quarters[18] << "," <<
    quarters[4] << "," <<
    quarters[9] << "," <<
    quarters[14] << "," <<
    quarters[19] << endl;
  }

  else if ((split == CU_VERT_SPLIT) || (split == CU_HORZ_SPLIT))
  {
    file_features << 
    quarters[0] << "," <<
    quarters[5] << "," <<
    -1 << "," <<
    -1 << "," <<
    quarters[1] << "," <<
    quarters[6] << "," <<
    -1 << "," <<
    -1 << "," <<
    quarters[2] << "," <<
    quarters[7] << "," <<
    -1 << "," <<
    -1 << "," <<
    quarters[3] << "," <<
    quarters[8] << "," <<
    -1 << "," <<
    -1 << "," <<
    quarters[4] << "," <<
    quarters[9] << "," <<
    -1 << "," <<
    -1 << endl;
  }

  else if ((split == CU_TRIH_SPLIT) || (split == CU_TRIV_SPLIT))
  {
    file_pixel <<
    quarters[0] << "," <<
    quarters[5] << "," <<
    quarters[10] << "," <<
    -1 << "," <<
    quarters[1] << "," <<
    quarters[6] << "," <<
    quarters[11] << "," <<
    -1 << "," <<
    quarters[2] << "," <<
    quarters[7] << "," <<
    quarters[12] << "," <<
    -1 << "," <<
    quarters[3] << "," <<
    quarters[8] << "," <<
    quarters[13] << "," <<
    -1 << "," <<
    quarters[4] << "," <<
    quarters[9] << "," <<
    quarters[14] << "," <<
    -1 << endl;
  } */
  /*cout << "Atual: (" << xTL << "," << yTL << ") (" << xBR << "," << yBR << ") H:" << pixelHeight << " W:" << pixelWidth << endl;
  cout << "\tVariance: " << var << "\tMean: " << mean << "\tGrad(X): " << grads[0] << "\tGrads(Y): " << grads[1] << "\tRadioGrad: " << ratioGrads << endl;

  cout << "Split: " << split << endl;

  if(split == CU_QUAD_SPLIT)
  {
    cout << "\tsubQuarterTL: Var: " << quarters[0] << " Mean: " << quarters[1] << " GradX: " << quarters[2] << " GradY: " << quarters[3] << " RatioGrad: " << quarters[4]
        << "\n\tsubQuarterTR: Var: " << quarters[5] << " Mean: " << quarters[6] << " GradX: " << quarters[7] << " GradY: " << quarters[8] << " RatioGrad: " << quarters[9]
        << "\n\tsubQuarterBL: Var: " << quarters[10] << " Mean: " << quarters[11] << " GradX: " << quarters[12] << " GradY: " << quarters[13] << " RatioGrad: " << quarters[14]
        << "\n\tsubQuarterBR: Var: " << quarters[15] << " Mean: " << quarters[16] << " GradX: " << quarters[17] << " GradY: " << quarters[18] << " RatioGrad: " << quarters[19] << endl;
  } 

  else if(split == CU_HORZ_SPLIT)
  {
    cout << "\tsubQuarterT: Var: " << quarters[0] << " Mean: " << quarters[1] << " GradX: " << quarters[2] << " GradY: " << quarters[3] << " RatioGrad: " << quarters[4]
        << "\n\tsubQuarterB: Var: " << quarters[5] << " Mean: " << quarters[6] << " GradX: " << quarters[7] << " GradY: " << quarters[8] << " RatioGrad: " << quarters[9] << endl;
  }
  
  else if(split == CU_VERT_SPLIT)
  {
    cout << "\tsubQuarterR: Var: " << quarters[0] << " Mean: " << quarters[1] << " GradX: " << quarters[2] << " GradY: " << quarters[3] << " RatioGrad: " << quarters[4]
        << "\n\tsubQuarterL: Var: " << quarters[5] << " Mean: " << quarters[6] << " GradX: " << quarters[7] << " GradY: " << quarters[8] << " RatioGrad: " << quarters[9] << endl;
  }

  else if(split == CU_TRIH_SPLIT)
  {
    cout << "\tsubQuarterT: Var: " << quarters[0] << " Mean: " << quarters[1] << " GradX: " << quarters[2] << " GradY: " << quarters[3] << " RatioGrad: " << quarters[4]
        << "\n\tsubQuarterM: Var: " << quarters[5] << " Mean: " << quarters[6] << " GradX: " << quarters[7] << " GradY: " << quarters[8] << " RatioGrad: " << quarters[9]
        << "\n\tsubQuarterB: Var: " << quarters[10] << " Mean: " << quarters[11] << " GradX: " << quarters[12] << " GradY: " << quarters[13] << " RatioGrad: " << quarters[14] << endl;
  }

  else if(split == CU_TRIV_SPLIT)
  {
    cout << "\tsubQuarterL: Var: " << quarters[0] << " Mean: " << quarters[1] << " GradX: " << quarters[2] << " GradY: " << quarters[3] << " RatioGrad: " << quarters[4]
        << "\n\tsubQuarterM: Var: " << quarters[5] << " Mean: " << quarters[6] << " GradX: " << quarters[7] << " GradY: " << quarters[8] << " RatioGrad: " << quarters[9]
        << "\n\tsubQuarterR: Var: " << quarters[10] << " Mean: " << quarters[11] << " GradX: " << quarters[12] << " GradY: " << quarters[13] << " RatioGrad: " << quarters[14] << endl;
  }*/
}

double features::variance(int xTL, int yTL, int xBR, int yBR, int varSum)
{
  double var = 0;
  int varHeight  = yBR - yTL + 1;
  int varWidth   = xBR - xTL + 1;

  int n = (varHeight * varWidth);
  double mean = (double) varSum / (double) n;
  
  for(int i = yTL; i <= yBR; i++)
  {
    for(int j = xTL; j <= xBR; j++)
    {
      var += (CTUPixel[i][j] - mean) * (CTUPixel[i][j] - mean);
    }
  }
  
  return var / (double) n;
}

vector<unsigned short > features::gradients(int xTL, int yTL, int xBR, int yBR)
{
  double sobelX[3][3] = 
	{
		{-1, 0, 1},
		{-2, 0, 2},
		{-1, 0, 1}
	};

	double sobelY[3][3] = 
	{
		{-1, -2, -1},
		{0, 0, 0},
		{1, 2, 1}
	};

	unsigned short GX = 0;
	unsigned short GY = 0;

  int gradHeight  = yBR - yTL + 1;
  int gradWidth   = xBR - xTL + 1;

	//PADDING
	int heightPadding = gradHeight + 2;
	int widthPadding  = gradWidth + 2;
	unsigned short paddingImage[heightPadding][widthPadding] = {0};


	for(int i = yTL; i <= yBR; i++)
	{
		for(int j = xTL; j <= xBR; j++)
		{
			paddingImage[i+1-yTL][j+1-xTL] = CTUPixel[i][j];
			paddingImage[0][j+1-xTL] = CTUPixel[yTL][j];
			paddingImage[heightPadding - 1][j+1-xTL] = CTUPixel[yBR][j];
		}

		paddingImage[i+1-yTL][0] = CTUPixel[i][xTL];
		paddingImage[i+1-yTL][widthPadding - 1] = CTUPixel[i][xBR];
	}

	paddingImage[0][0] = CTUPixel[yTL][xTL];
	paddingImage[heightPadding - 1][0] = CTUPixel[yBR][xTL];
	paddingImage[0][widthPadding - 1] = CTUPixel[yTL][xBR];
	paddingImage[heightPadding - 1][widthPadding - 1] = CTUPixel[yBR][xBR];

  for(int i = 1; i < heightPadding - 1; i++)
  {
    for(int j = 1; j < widthPadding - 1; j++)
    {
      GX += (sobelX[0][0] * paddingImage[i-1][j-1])
          + (sobelX[0][1] * paddingImage[i-1][j])
          + (sobelX[0][2] * paddingImage[i-1][j+1])
          + (sobelX[1][0] * paddingImage[i][j-1])
          + (sobelX[1][1] * paddingImage[i][j])
          + (sobelX[1][2] * paddingImage[i][j+1])
          + (sobelX[2][0] * paddingImage[i+1][j-1])
          + (sobelX[2][1] * paddingImage[i+1][j])
          + (sobelX[2][2] * paddingImage[i+1][j+1]);

      GY += (sobelY[0][0] * paddingImage[i-1][j-1])
          + (sobelY[0][1] * paddingImage[i-1][j])
          + (sobelY[0][2] * paddingImage[i-1][j+1])
          + (sobelY[1][0] * paddingImage[i][j-1])
          + (sobelY[1][1] * paddingImage[i][j])
          + (sobelY[1][2] * paddingImage[i][j+1])
          + (sobelY[2][0] * paddingImage[i+1][j-1])
          + (sobelY[2][1] * paddingImage[i+1][j])
          + (sobelY[2][2] * paddingImage[i+1][j+1]);
    }
  }
  vector <unsigned short> grads;
  grads.push_back(GX);
  grads.push_back(GY);

  return grads;
}

vector<double> features::quarterCU(int xTL, int yTL, int xBR, int yBR, PartSplit split)
{
  vector<double> quarters;

  if(split == CU_QUAD_SPLIT)
  {
    int maxHeight = (yBR - yTL + 1);
    int maxWidth  = (xBR - xTL + 1);
    int quarterHeight = maxHeight / 2;
    int quarterWidth  = maxWidth / 2;
    int quarter_xTL = xTL;
    int quarter_yTL = yTL;
    int quarter_xBR = xBR - quarterWidth;
    int quarter_yBR = yBR - quarterHeight;
    int block = 4;

    while(block != 0)
    {
      int quarterSum = 0;
      for(int i = quarter_yTL; i <= quarter_yBR; i++)
      {
        for(int j = quarter_xTL; j <= quarter_xBR; j++)
        {
          quarterSum += CTUPixel[i][j];
        }
      }
      
      double quarterVar = variance(quarter_xTL, quarter_yTL, quarter_xBR, quarter_yBR, quarterSum);
      int n = (quarterHeight * quarterWidth);
      double mean = (double) quarterSum / (double) n;
      vector<unsigned short> grads = gradients(quarter_xTL, quarter_yTL, quarter_xBR, quarter_yBR);
      double ratioGrads = (double) grads[0] / (double) grads[1];

      quarter_xBR += quarterWidth;
      quarter_xTL += quarterWidth;

      if (quarter_xBR > maxWidth)
      {
        quarter_xBR = quarterWidth - 1;
        quarter_xTL = 0;
        quarter_yTL += quarterHeight;
        quarter_yBR += quarterHeight;
      }

      block--;

      quarters.push_back(quarterVar);
      quarters.push_back(mean);
      quarters.push_back(grads[0]);
      quarters.push_back(grads[1]);
      quarters.push_back(ratioGrads);
    }
  }
  else if(split == CU_HORZ_SPLIT)
  {
    int maxHeight = (yBR - yTL + 1);
    int maxWidth  = (xBR - xTL + 1);
    int quarterHeight = maxHeight / 2;
    int quarterWidth  = maxWidth;
    int quarter_xTL = xTL;
    int quarter_yTL = yTL;
    int quarter_xBR = xBR;
    int quarter_yBR = yBR - quarterHeight;
    int block = 2;

    while(block != 0)
    {
      int quarterSum = 0;
      for(int i = quarter_yTL; i <= quarter_yBR; i++)
      {
        for(int j = quarter_xTL; j <= quarter_xBR; j++)
        {
          quarterSum += CTUPixel[i][j];
        }
      }
      
      double quarterVar = variance(quarter_xTL, quarter_yTL, quarter_xBR, quarter_yBR, quarterSum);
      int n = (quarterHeight * quarterWidth);
      double mean = (double) quarterSum / (double) n;
      vector<unsigned short> grads = gradients(quarter_xTL, quarter_yTL, quarter_xBR, quarter_yBR);
      double ratioGrads = (double) grads[0] / (double) grads[1];

      quarter_yTL += quarterHeight;
      quarter_yBR += quarterHeight;

      block--;

      quarters.push_back(quarterVar);
      quarters.push_back(mean);
      quarters.push_back(grads[0]);
      quarters.push_back(grads[1]);
      quarters.push_back(ratioGrads);
    }
  }

  else if(split == CU_VERT_SPLIT)
  {
    int maxHeight = (yBR - yTL + 1);
    int maxWidth  = (xBR - xTL + 1);
    int quarterHeight = maxHeight;
    int quarterWidth  = maxWidth / 2;
    int quarter_xTL = xTL;
    int quarter_yTL = yTL;
    int quarter_xBR = xBR - quarterWidth;
    int quarter_yBR = yBR;
    int block = 2;

    while(block != 0)
    {
      int quarterSum = 0;
      for(int i = quarter_yTL; i <= quarter_yBR; i++)
      {
        for(int j = quarter_xTL; j <= quarter_xBR; j++)
        {
          quarterSum += CTUPixel[i][j];
        }
      }
      
      double quarterVar = variance(quarter_xTL, quarter_yTL, quarter_xBR, quarter_yBR, quarterSum);
      int n = (quarterHeight * quarterWidth);
      double mean = (double) quarterSum / (double) n;
      vector<unsigned short> grads = gradients(quarter_xTL, quarter_yTL, quarter_xBR, quarter_yBR);
      double ratioGrads = (double) grads[0] / (double) grads[1];

      quarter_xTL += quarterWidth;
      quarter_xBR += quarterWidth;

      block--;

      quarters.push_back(quarterVar);
      quarters.push_back(mean);
      quarters.push_back(grads[0]);
      quarters.push_back(grads[1]);
      quarters.push_back(ratioGrads);
    }
  }

  if(split == CU_TRIH_SPLIT)
  {
    int maxHeight = (yBR - yTL + 1);
    int maxWidth  = (xBR - xTL + 1);
    int quarterHeight = maxHeight / 4;
    int quarterWidth  = maxWidth;
    int quarter_xTL = xTL;
    int quarter_yTL = yTL;
    int quarter_xBR = xBR;
    int quarter_yBR = yBR - (3 * quarterHeight);
    int block = 3;

    while(block != 0)
    {
      int quarterSum = 0;
      for(int i = quarter_yTL; i <= quarter_yBR; i++)
      {
        for(int j = quarter_xTL; j <= quarter_xBR; j++)
        {
          quarterSum += CTUPixel[i][j];
        }
      }
      
      double quarterVar = variance(quarter_xTL, quarter_yTL, quarter_xBR, quarter_yBR, quarterSum);
      int n = (quarterHeight * quarterWidth);
      double mean = (double) quarterSum / (double) n;
      vector<unsigned short> grads = gradients(quarter_xTL, quarter_yTL, quarter_xBR, quarter_yBR);
      double ratioGrads = (double) grads[0] / (double) grads[1];

      if(block == 3)
      {
        quarter_yTL += quarterHeight;
        quarter_yBR += (2 * quarterHeight);
      }
      else if (block == 2)
      {
        quarter_yTL += (2 * quarterHeight);
        quarter_yBR += quarterHeight;
      }
      
      block--;

      quarters.push_back(quarterVar);
      quarters.push_back(mean);
      quarters.push_back(grads[0]);
      quarters.push_back(grads[1]);
      quarters.push_back(ratioGrads);
    }
  }

  if(split == CU_TRIV_SPLIT)
  {
    int maxHeight = (yBR - yTL + 1);
    int maxWidth  = (xBR - xTL + 1);
    int quarterHeight = maxHeight;
    int quarterWidth  = maxWidth / 4;
    int quarter_xTL = xTL;
    int quarter_yTL = yTL;
    int quarter_xBR = xBR - (3 * quarterWidth);
    int quarter_yBR = yBR;
    int block = 3;

    while(block != 0)
    {
      int quarterSum = 0;
      for(int i = quarter_yTL; i <= quarter_yBR; i++)
      {
        for(int j = quarter_xTL; j <= quarter_xBR; j++)
        {
          quarterSum += CTUPixel[i][j];
        }
      }
      
      double quarterVar = variance(quarter_xTL, quarter_yTL, quarter_xBR, quarter_yBR, quarterSum);
      int n = (quarterHeight * quarterWidth);
      double mean = (double) quarterSum / (double) n;
      vector<unsigned short> grads = gradients(quarter_xTL, quarter_yTL, quarter_xBR, quarter_yBR);
      double ratioGrads = (double) grads[0] / (double) grads[1];

      if(block == 3)
      {
        quarter_xTL += quarterWidth;
        quarter_xBR += (2 * quarterWidth);
      }
      else if (block == 2)
      {
        quarter_xTL += (2 * quarterWidth);
        quarter_xBR += quarterWidth;
      }
      
      block--;

      quarters.push_back(quarterVar);
      quarters.push_back(mean);
      quarters.push_back(grads[0]);
      quarters.push_back(grads[1]);
      quarters.push_back(ratioGrads);
    }
  }

  return quarters;

}