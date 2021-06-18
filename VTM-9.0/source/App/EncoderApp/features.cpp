#include "features.h"

ofstream features::file_features;
ofstream features::file_target;
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
int      features::CTUPixel[128][128];
int      features::pixelHeight;
int      features::pixelWidth;

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
  CTUFrame            = initCTUFrame();
}

void features::createFile()
{
  file_features.open("dataset_" + videoName + "_" + to_string(qp) + "_features.csv", ios::app);
  file_target.open("dataset_" + videoName + "_" + to_string(qp) + "_target.csv", ios::app);

  file_features << "videoname,paramQP,frameWidth,frameHeight,CU_width,CU_height,topLeft_x,topLeft_y,bottomRight_x,bottomRight_y,"
                << "depth,qtdepth,mtdepth,qp,predMode,skip,mmvdSkip,affine,affineType,colorTransform,geoFlag,bdpcmMode,"
                << "bdpcmModeChroma,imv,rootCbf,mipFlag,modeType,modeTypeSeries,splitSeries,cost,dist,fracBits,baseQP,prevQP,"
                << "currQP,lumaCost,POC,opts,maxCostAllowed,tlMaxQTDepth,tMaxQTDepth,trMaxQTDepth,lMaxQTDepth,previousMaxQTDepth,averageQTDepth,modeQTDepth,highestQTDepth,"
                << "tlMaxMTDepth,tMaxMTDepth,trMaxMTDepth,lMaxMDepth,previousMaxMTDepth,averageMTDepth,modeMTDepth,highestMTDepth,interIMVRDCost,"
                << "interRDCost,affineMergeRDCost,cachedResultRDCost,mergeRDCost,mergeGeoRDCost,intraRDCost,splitType" << endl;


  file_target << "videoname,paramQP,frameWidth,frameHeight,CU_width,CU_height,topLeft_x,topLeft_y,bottomRight_x,bottomRight_y,POC,qtdepth,mtdepth,"
              << "PartSplit,RDCost" << endl;
}


void features::extract_features(CodingUnit* cu, CodingStructure* cs, EncTestMode currTestMode)
{
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

void features::extractCUPixel(CodingStructure* cs)
{
  int xTL = cs->area.Y().topLeft().x;
  int yTL = cs->area.Y().topLeft().y;
  int xBR = cs->area.Y().bottomRight().x;
  int yBR = cs->area.Y().bottomRight().y;
  
  int height = 0;
  int width = 0;

  for(int y = yTL; y <= yBR; y++)
  {
    for(int x = xTL; x <= xBR; x++)
    {
      CTUPixel[height][width] = cs->picture->getTrueOrigBuf().Y().at(x,y);
      width++;
    }
    height++;
    width = 0;
  }

  pixelHeight  = yBR - yTL;
  pixelWidth   = xBR - xTL;
}
