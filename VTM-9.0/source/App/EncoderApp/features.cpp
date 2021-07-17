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
unsigned short features::CTUPixel[128][128];
int            features::rf_paramQP;
int            features::rf_CU_width;
int            features::rf_CU_height;
int            features::rf_topLeft_x;
int            features::rf_topLeft_y;
int            features::rf_bottomRight_x;
int            features::rf_bottomRight_y;
int            features::rf_POC;
int            features::rf_qtdepth;
int            features::rf_mtdepth;
double         features::rf_variance;
double         features::rf_mean;
unsigned short features::rf_gradientH;
unsigned short features::rf_gradientV;
double         features::rf_ratioGrad;
int            features::rf_sum;
double         features::rf_quarter1Var;
double         features::rf_quarter1Mean;
unsigned short features::rf_quarter1GradH;
unsigned short features::rf_quarter1GradV;
double         features::rf_quarter1RatioGrad;
int            features::rf_quarter1Sum;
double         features::rf_quarter2Var;
double         features::rf_quarter2Mean;
unsigned short features::rf_quarter2GradH;
unsigned short features::rf_quarter2GradV;
double         features::rf_quarter2RatioGrad;
int            features::rf_quarter2Sum;
double         features::rf_quarter3Var;
double         features::rf_quarter3Mean;
unsigned short features::rf_quarter3GradH;
unsigned short features::rf_quarter3GradV;
double         features::rf_quarter3RatioGrad;
int            features::rf_quarter3Sum;
double         features::rf_quarter4Var;
double         features::rf_quarter4Mean;
unsigned short features::rf_quarter4GradH;
unsigned short features::rf_quarter4GradV;
double         features::rf_quarter4RatioGrad;
int            features::rf_quarter4Sum;

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
  file_features.open("features/dataset_" + videoName + "_" + to_string(qp) + "_features.csv", ios::app);
  file_target.open("target/dataset_" + videoName + "_" + to_string(qp) + "_target.csv", ios::app);

  file_features << "videoname,paramQP,frameWidth,frameHeight,CU_width,CU_height,topLeft_x,topLeft_y,bottomRight_x,bottomRight_y,"
                << "depth,qtdepth,mtdepth,qp,predMode,skip,mmvdSkip,affine,affineType,colorTransform,geoFlag,bdpcmMode,"
                << "bdpcmModeChroma,imv,rootCbf,mipFlag,modeType,modeTypeSeries,splitSeries,cost,dist,fracBits,baseQP,prevQP,"
                << "currQP,lumaCost,POC,opts,maxCostAllowed,tlMaxQTDepth,tMaxQTDepth,trMaxQTDepth,lMaxQTDepth,previousMaxQTDepth,averageQTDepth,modeQTDepth,highestQTDepth,"
                << "tlMaxMTDepth,tMaxMTDepth,trMaxMTDepth,lMaxMDepth,previousMaxMTDepth,averageMTDepth,modeMTDepth,highestMTDepth,interIMVRDCost,"
                << "interRDCost,affineMergeRDCost,cachedResultRDCost,mergeRDCost,mergeGeoRDCost,intraRDCost,splitType" << endl;

  file_target << "videoname,paramQP,frameWidth,frameHeight,CU_width,CU_height,topLeft_x,topLeft_y,bottomRight_x,bottomRight_y,POC,qtdepth,mtdepth,"
             << "splitType,RDCost" << endl;
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

void features::extractTarget(CodingStructure* cs, CodingUnit* cu, EncTestMode currTestMode)
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

string features::enumToString(int value)
{
  switch (value)
  {
  case 1:
    return "QUAD_SPLIT";
    break;
  case 2:
    return "BI_HORZ_SPLIT";
    break;
  case 3:
    return "BI_VERT_SPLIT";
    break;
  case 4:
    return "TRI_HORZ_SPLIT";
    break;
  case 5:
    return "TRI_VERT_SPLIT";
    break;

  default:
    return "ERROR";
    break;
  }
}

void features::extractCUPixel(CodingStructure* cs, PartSplit split, Partitioner* partitioner)
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

  double var = variance(0, 0, pixelWidth-1, pixelHeight-1, sum);
  int n = (pixelHeight * pixelWidth);
  double mean = (double) sum / (double) n;
  vector<unsigned short> grads = gradients(0, 0, pixelWidth-1, pixelHeight-1);
  double ratioGrads = (double) grads[0] / (double) grads[1];
  vector<double> quarters = quarterCU(0, 0, pixelWidth-1, pixelHeight-1, split);

  rf_paramQP            = qp;
  rf_CU_width           = pixelWidth;
  rf_CU_height          = pixelHeight;
  rf_topLeft_x          = xTL;
  rf_topLeft_y          = yTL;
  rf_bottomRight_x      = xBR;
  rf_bottomRight_y      = yBR;
  rf_POC                = int(cs->picture->getPOC());
  rf_qtdepth            = int(partitioner->currQtDepth);
  rf_mtdepth            = int(partitioner->currMtDepth);
  rf_variance           = var;
  rf_mean               = mean;
  rf_gradientH          = grads[0];
  rf_gradientV          = grads[1];
  rf_ratioGrad          = ratioGrads;
  rf_sum                = sum;
  rf_quarter1Var        = quarters[0];
  rf_quarter1Mean       = quarters[1];
  rf_quarter1GradH      = quarters[2];
  rf_quarter1GradV      = quarters[3];
  rf_quarter1RatioGrad  = quarters[4];
  rf_quarter1Sum        = quarters[5];
  rf_quarter2Var        = quarters[6];
  rf_quarter2Mean       = quarters[7];
  rf_quarter2GradH      = quarters[8];
  rf_quarter2GradV      = quarters[9];
  rf_quarter2RatioGrad  = quarters[10];
  rf_quarter2Sum        = quarters[11];
  
  if ((split == CU_TRIH_SPLIT) || (split == CU_TRIV_SPLIT) || (split == CU_QUAD_SPLIT))
  {
    rf_quarter3Var        = quarters[12];
    rf_quarter3Mean       = quarters[13];
    rf_quarter3GradH      = quarters[14];
    rf_quarter3GradV      = quarters[15];
    rf_quarter3RatioGrad  = quarters[16];
    rf_quarter3Sum        = quarters[17];

    if(split == CU_QUAD_SPLIT)
    {
      rf_quarter4Var        = quarters[18];
      rf_quarter4Mean       = quarters[19];
      rf_quarter4GradH      = quarters[20];
      rf_quarter4GradV      = quarters[21];
      rf_quarter4RatioGrad  = quarters[22];
      rf_quarter4Sum        = quarters[23];
    }
  }
}

float* features::getFeaturesRF(int type)
{
  float* features;
  
  if (type == 1)
  {
    features = (float *) malloc(sizeof(float) * 34);
    features[0] = rf_paramQP;
    features[1] = rf_CU_width;
    features[2] = rf_CU_height;
    features[3] = rf_topLeft_x;
    features[4] = rf_topLeft_y;
    features[5] = rf_bottomRight_x;
    features[6] = rf_bottomRight_y;
    features[7] = rf_POC;
    features[8] = rf_qtdepth;
    features[9] = rf_mtdepth;
    features[10] = rf_variance;
    features[11] = rf_mean;
    features[12] = rf_gradientH;
    features[13] = rf_gradientV;
    features[14] = rf_ratioGrad;
    features[15] = rf_sum;
    features[16] = rf_quarter1Var;
    features[17] = rf_quarter1Mean;
    features[18] = rf_quarter1GradH;
    features[19] = rf_quarter1GradV;
    features[20] = rf_quarter1RatioGrad;
    features[21] = rf_quarter1Sum;
    features[22] = rf_quarter2Var;
    features[23] = rf_quarter2Mean;
    features[24] = rf_quarter2GradH;
    features[25] = rf_quarter2GradV;
    features[26] = rf_quarter2RatioGrad;
    features[27] = rf_quarter2Sum;
    features[28] = rf_quarter3Var;
    features[29] = rf_quarter3Mean;
    features[30] = rf_quarter3GradH;
    features[31] = rf_quarter3GradV;
    features[32] = rf_quarter3RatioGrad;
    features[33] = rf_quarter3Sum;
  }
  else if(type == 2)
  {
    features = (float *) malloc(sizeof(float) * 32);
    features[0] = rf_paramQP;
    features[1] = rf_topLeft_x;
    features[2] = rf_topLeft_y;
    features[3] = rf_bottomRight_x;
    features[4] = rf_bottomRight_y;
    features[5] = rf_POC;
    features[6] = rf_qtdepth;
    features[7] = rf_mtdepth;
    features[8] = rf_variance;
    features[9] = rf_mean;
    features[10] = rf_gradientH;
    features[11] = rf_gradientV;
    features[12] = rf_ratioGrad;
    features[13] = rf_sum;
    features[14] = rf_quarter1Var;
    features[15] = rf_quarter1Mean;
    features[16] = rf_quarter1GradH;
    features[17] = rf_quarter1GradV;
    features[18] = rf_quarter1RatioGrad;
    features[19] = rf_quarter1Sum;
    features[20] = rf_quarter2Var;
    features[21] = rf_quarter2Mean;
    features[22] = rf_quarter2GradH;
    features[23] = rf_quarter2GradV;
    features[24] = rf_quarter2RatioGrad;
    features[25] = rf_quarter2Sum;
    features[26] = rf_quarter3Var;
    features[27] = rf_quarter3Mean;
    features[28] = rf_quarter3GradH;
    features[29] = rf_quarter3GradV;
    features[30] = rf_quarter3RatioGrad;
    features[31] = rf_quarter3Sum;
  }

  pixelFeaturesZero();
  return features;

}

void features::pixelFeaturesZero()
{
  rf_paramQP            = -1;
  rf_CU_width           = -1;
  rf_CU_height          = -1;
  rf_topLeft_x          = -1;
  rf_topLeft_y          = -1;
  rf_bottomRight_x      = -1;
  rf_bottomRight_y      = -1;
  rf_POC                = -1;
  rf_qtdepth            = -1;
  rf_mtdepth            = -1;
  rf_variance           = -1;
  rf_mean               = -1;
  rf_gradientH          = -1;
  rf_gradientV          = -1;
  rf_ratioGrad          = -1;
  rf_sum                = -1;
  rf_quarter1Var        = -1;
  rf_quarter1Mean       = -1;
  rf_quarter1GradH      = -1;
  rf_quarter1GradV      = -1;
  rf_quarter1RatioGrad  = -1;
  rf_quarter1Sum        = -1;
  rf_quarter2Var        = -1;
  rf_quarter2Mean       = -1;
  rf_quarter2GradH      = -1;
  rf_quarter2GradV      = -1;
  rf_quarter2RatioGrad  = -1;
  rf_quarter2Sum        = -1;
  rf_quarter3Var        = -1;
  rf_quarter3Mean       = -1;
  rf_quarter3GradH      = -1;
  rf_quarter3GradV      = -1;
  rf_quarter3RatioGrad  = -1;
  rf_quarter3Sum        = -1;
  rf_quarter4Var        = -1;
  rf_quarter4Mean       = -1;
  rf_quarter4GradH      = -1;
  rf_quarter4GradV      = -1;
  rf_quarter4RatioGrad  = -1;
  rf_quarter4Sum        = -1;
}

int features::predictQUADSPLIT (CodingStructure* cs)
{
  /*int block_size = int(cs->area.lheight()) * int(cs->area.lwidth());

  switch (block_size)
  {
  case 16384:
    return predict_s0_QT_SPLIT(pixelFeatures);
    break;
  
  case 8192:
    return predict_s1_QT_SPLIT(pixelFeatures);
    break;
  
  case 4096:
    return predict_s2_QT_SPLIT(pixelFeatures);
    break;
  
  case 2048:
    return predict_s3_QT_SPLIT(pixelFeatures);
    break;
  
  case 1024:
    return predict_s4_QT_SPLIT(pixelFeatures);
    break;
  
  case 512:
    return predict_s5_QT_SPLIT(pixelFeatures);
    break;
  
  case 256:
    return predict_s6_QT_SPLIT(pixelFeatures);
    break;
  
  default:
    cout << "Nenhuma Tomada de Decisão" << endl;
    return 1;
    break;
  }
  */
 return 1;
}
int features::predictHORZSPLIT (CodingStructure* cs)
{
  int block_size = int(cs->area.lheight()) * int(cs->area.lwidth());
  float* pixelFeatures = getFeaturesRF(1);
  switch (block_size)
  {
  /*case 16384:
    return predict_s0_HORZ_SPLIT(pixelFeatures);
    break;
  
  case 8192:
    return predict_s1_HORZ_SPLIT(pixelFeatures);
    break;
  
  case 4096:
    return predict_s2_HORZ_SPLIT(pixelFeatures);
    break;
  
  case 2048:
    return predict_s3_HORZ_SPLIT(pixelFeatures);
    break;
  
  case 1024:
    return predict_s4_HORZ_SPLIT(pixelFeatures);
    break; */
  
  case 512:
    return predict_s5_HORZ_SPLIT(pixelFeatures);
    free(pixelFeatures);
    break;
  
  case 256:
    return predict_s6_HORZ_SPLIT(pixelFeatures);
    free(pixelFeatures);
    break;
  
  default:
    return 1;
    break;
  }
}
int features::predictVERTSPLIT (CodingStructure* cs)
{
  int block_size = int(cs->area.lheight()) * int(cs->area.lwidth());
  float* pixelFeatures = getFeaturesRF(1);
  switch (block_size)
  {
  /*case 16384:
    return predict_s0_QT_SPLIT(pixelFeatures);
    break;
  
  case 8192:
    return predict_s1_VERT_SPLIT(pixelFeatures);
    break;*/
  
  case 4096:
    pixelFeatures = getFeaturesRF(2);
    return predict_s2_VERT_SPLIT(pixelFeatures);
    free(pixelFeatures);
    break;
  
  case 2048:
    return predict_s3_VERT_SPLIT(pixelFeatures);
    free(pixelFeatures);
    break;
  
  case 1024:
    return predict_s4_VERT_SPLIT(pixelFeatures);
    break;
  
  case 512:
    return predict_s5_VERT_SPLIT(pixelFeatures);
    free(pixelFeatures);
    break;
  
  case 256:
    return predict_s6_VERT_SPLIT(pixelFeatures);
    free(pixelFeatures);
    break;
  
  default:
    return 1;
    break;
  }
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
    int quarterHeight = maxHeight / 4;
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
      int n = (quarter_yBR - quarter_yTL + 1) * (quarter_xBR - quarter_xTL + 1);
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
    int maxWidth  = (xBR - xTL + 1);
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
      int n = (quarter_yBR - quarter_yTL + 1) * (quarter_xBR - quarter_xTL + 1);
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