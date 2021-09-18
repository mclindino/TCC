#include "features.h"

ofstream features::file_features;
ofstream features::file_target;
ofstream features::file_pixel;
ofstream features::check_file;
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
double features::f_paramQP;
double features::f_CU_width;
double features::f_CU_height;
double features::f_topLeft_x;
double features::f_topLeft_y;
double features::f_bottomRight_x;
double features::f_bottomRight_y;
double features::f_POC;
double features::f_qtdepth;
double features::f_mtdepth;
double features::f_variance;
double features::f_mean;
double features::f_gradientH;
double features::f_gradientV;
double features::f_ratioGrad;
double features::f_sum;
double features::f_quarter1Var;
double features::f_quarter1Mean;
double features::f_quarter1GradH;
double features::f_quarter1GradV;
double features::f_quarter1RatioGrad;
double features::f_quarter1Sum;
double features::f_quarter2Var;
double features::f_quarter2Mean;
double features::f_quarter2GradH;
double features::f_quarter2GradV;
double features::f_quarter2RatioGrad;
double features::f_quarter2Sum;
double features::f_quarter3Var;
double features::f_quarter3Mean;
double features::f_quarter3GradH;
double features::f_quarter3GradV;
double features::f_quarter3RatioGrad;
double features::f_quarter3Sum;
double features::f_quarter4Var;
double features::f_quarter4Mean;
double features::f_quarter4GradH;
double features::f_quarter4GradV;
double features::f_quarter4RatioGrad;
double features::f_quarter4Sum;
double features::f_HIVar;
double features::f_HIMean;
double features::f_HIRatio;
double features::f_VIVar;
double features::f_VIMean;
double features::f_VIRatio;
double features::f_DiffInconsVar;
double features::f_DiffInconsMean;
double features::f_DiffInconsRatio;
double features::f_HIVIVar;
double features::f_HIVIMean;
double features::f_HIVIRatioGrad;

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

  //createFile();
  CTUFrame              = initCTUFrame();
}

void features::createFile()
{
  file_features.open("features/dataset_" + videoName + "_" + to_string(qp) + "_features.csv", ios::app);
  file_target.open("target/dataset_" + videoName + "_" + to_string(qp) + "_target.csv", ios::app);
  check_file.open("s2.csv", ios::app);
  
  /*file_features << "videoname,paramQP,frameWidth,frameHeight,CU_width,CU_height,topLeft_x,topLeft_y,bottomRight_x,bottomRight_y,"
                << "depth,qtdepth,mtdepth,qp,predMode,skip,mmvdSkip,affine,affineType,colorTransform,geoFlag,bdpcmMode,"
                << "bdpcmModeChroma,imv,rootCbf,mipFlag,modeType,modeTypeSeries,splitSeries,cost,dist,fracBits,baseQP,prevQP,"
                << "currQP,lumaCost,POC,opts,maxCostAllowed,tlMaxQTDepth,tMaxQTDepth,trMaxQTDepth,lMaxQTDepth,previousMaxQTDepth,averageQTDepth,modeQTDepth,highestQTDepth,"
                << "tlMaxMTDepth,tMaxMTDepth,trMaxMTDepth,lMaxMDepth,previousMaxMTDepth,averageMTDepth,modeMTDepth,highestMTDepth,interIMVRDCost,"
                << "interRDCost,affineMergeRDCost,cachedResultRDCost,mergeRDCost,mergeGeoRDCost,intraRDCost,splitType" << endl; */

  file_features << "videoname,cost,frameWidth,frameHeight,paramQP,CU_width,CU_height,topLeft_x,topLeft_y,bottomRight_x,bottomRight_y,POC,qtdepth,mtdepth,splitType,"
                << "variance,mean,gradientH,gradientV,ratioGrad,sum,quarter1Var,quarter1Mean,quarter1GradH,quarter1GradV,quarter1RatioGrad,quarter1Sum,"
                << "quarter2Var,quarter2Mean,quarter2GradH,quarter2GradV,quarter2RatioGrad,quarter2Sum,"
                << "quarter3Var,quarter3Mean,quarter3GradH,quarter3GradV,quarter3RatioGrad,quarter3Sum,"
                << "quarter4Var,quarter4Mean,quarter4GradH,quarter4GradV,quarter4RatioGrad,quarter4Sum" << endl;

  file_target << "videoname,paramQP,frameWidth,frameHeight,CU_width,CU_height,topLeft_x,topLeft_y,bottomRight_x,bottomRight_y,POC,qtdepth,mtdepth" << endl;
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

void features::extractTarget(CodingStructure* cs, CodingUnit* cu) //, EncTestMode currTestMode)
{
  file_target                       <<
  videoName                         << "," <<
  int(*cs->currQP)                  << "," <<
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
  int(cu->mtDepth)                  << endl;

  //int(getPartSplit(currTestMode))   << "," <<
  //cs->cost                          << endl;

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

void features::extractCUPixel(CodingStructure* cs, PartSplit split, Partitioner* partitioner)//, CodingUnit* cu)
{
  int xTL = partitioner->currArea().Y().topLeft().x;
  int yTL = partitioner->currArea().Y().topLeft().y;
  int xBR = partitioner->currArea().Y().bottomRight().x;
  int yBR = partitioner->currArea().Y().bottomRight().y;
  
  int height  = 0;
  int width   = 0;
  int sum     = 0;
  int pixelHeight = yBR - yTL + 1;
  int pixelWidth  = xBR - xTL + 1;

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

  double var  = variance(0, 0, pixelWidth-1, pixelHeight-1, sum);
  int n       = (pixelHeight * pixelWidth);
  double mean = (double) sum / (double) n;
  
  vector<unsigned short> grads = gradients(0, 0, pixelWidth-1, pixelHeight-1);
  double ratioGrads            = (grads[1] != 0) ? (double) grads[0] / (double) grads[1] : -1;
  vector<double> quarters      = quarterCU(0, 0, pixelWidth-1, pixelHeight-1, split);
  
  f_paramQP           = *(cs->currQP);
  f_CU_width          = partitioner->currArea().lwidth();
  f_CU_height         = partitioner->currArea().lheight();
  f_topLeft_x         = xTL;
  f_topLeft_y         = yTL;
  f_bottomRight_x     = xBR;
  f_bottomRight_y     = yBR;
  f_POC               = cs->picture->getPOC();
  f_qtdepth           = partitioner->currQtDepth;
  f_mtdepth           = partitioner->currMtDepth;
  f_variance          = var;
  f_mean              = mean;
  f_gradientH         = grads[0];
  f_gradientV         = grads[1];
  f_ratioGrad         = ratioGrads;
  f_sum               = sum;
  f_quarter1Var       = quarters[0];
  f_quarter1Mean      = quarters[1];
  f_quarter1GradH     = quarters[2];
  f_quarter1GradV     = quarters[3];
  f_quarter1RatioGrad = quarters[4];
  f_quarter1Sum       = quarters[5];
  f_quarter2Var       = quarters[6];
  f_quarter2Mean      = quarters[7];
  f_quarter2GradH     = quarters[8];
  f_quarter2GradV     = quarters[9];
  f_quarter2RatioGrad = quarters[10];
  f_quarter2Sum       = quarters[11];

  if(split == CU_QUAD_SPLIT)
  {
    f_quarter3Var       = quarters[12];
    f_quarter3Mean      = quarters[13];
    f_quarter3GradH     = quarters[14];
    f_quarter3GradV     = quarters[15];
    f_quarter3RatioGrad = quarters[16];
    f_quarter3Sum       = quarters[17];
    f_quarter4Var       = quarters[18];
    f_quarter4Mean      = quarters[19];
    f_quarter4GradH     = quarters[20];
    f_quarter4GradV     = quarters[21];
    f_quarter4RatioGrad = quarters[22];
    f_quarter4Sum       = quarters[23];

    f_HIVar     = abs(f_quarter1Var - f_quarter2Var) + abs(f_quarter3Var - f_quarter4Var);
    f_HIMean    = abs(f_quarter1Mean - f_quarter2Mean) + abs(f_quarter3Mean - f_quarter4Mean);
    f_HIRatio   = abs(f_quarter1RatioGrad - f_quarter2RatioGrad) + abs(f_quarter3RatioGrad - f_quarter4RatioGrad);

    f_VIVar     = abs(f_quarter1Var - f_quarter3Var) + abs(f_quarter2Var - f_quarter4Var);
    f_VIMean    = abs(f_quarter1Mean - f_quarter3Mean) + abs(f_quarter2Mean - f_quarter4Mean);
    f_VIRatio   = abs(f_quarter1RatioGrad - f_quarter3RatioGrad) + abs(f_quarter2RatioGrad - f_quarter4RatioGrad);

    f_DiffInconsVar   = abs(f_HIVar - f_VIVar);
    f_DiffInconsMean  = abs(f_HIMean - f_VIMean);
    f_DiffInconsRatio = abs(f_HIRatio - f_VIRatio);
  }

  else if((split == CU_HORZ_SPLIT) || (split == CU_VERT_SPLIT))
  {
    f_quarter3Var       = -1;
    f_quarter3Mean      = -1;
    f_quarter3GradH     = -1;
    f_quarter3GradV     = -1;
    f_quarter3RatioGrad = -1;
    f_quarter3Sum       = -1;
    f_quarter4Var       = -1;
    f_quarter4Mean      = -1;
    f_quarter4GradH     = -1;
    f_quarter4GradV     = -1;
    f_quarter4RatioGrad = -1;
    f_quarter4Sum       = -1;

    f_HIVIVar   = abs(f_quarter1Var - f_quarter2Var);
    f_HIVIMean  = abs(f_quarter1Mean - f_quarter2Mean);
    f_HIVIRatioGrad = abs(f_quarter1RatioGrad - f_quarter2RatioGrad);
  }
  
  else if((split == CU_TRIV_SPLIT) || (split == CU_TRIH_SPLIT))
  {
    f_quarter3Var       = quarters[12];
    f_quarter3Mean      = quarters[13];
    f_quarter3GradH     = quarters[14];
    f_quarter3GradV     = quarters[15];
    f_quarter3RatioGrad = quarters[16];
    f_quarter3Sum       = quarters[17];
    f_quarter4Var       = -1;
    f_quarter4Mean      = -1;
    f_quarter4GradH     = -1;
    f_quarter4GradV     = -1;
    f_quarter4RatioGrad = -1;
    f_quarter4Sum       = -1;

    f_HIVIVar   = abs(f_quarter1Var - 2*f_quarter2Var) + abs(2*f_quarter2Var - f_quarter3Var);
    f_HIVIMean  = abs(f_quarter1Mean - 2*f_quarter2Mean) + abs(2*f_quarter2Mean - f_quarter3Mean);
    f_HIVIRatioGrad = abs(f_quarter1RatioGrad - 2*f_quarter2RatioGrad) + abs(2*f_quarter2RatioGrad - f_quarter3RatioGrad);
  }
  
  /*file_features << 
  videoName << "," <<
  cs->cost << "," <<
  frameWidth << "," <<
  frameHeight << "," <<
  int(*cs->currQP) << "," <<
  f_CU_width << "," <<
  f_CU_height << "," <<
  f_topLeft_x << "," <<
  f_topLeft_y << "," <<
  f_bottomRight_x << "," <<
  f_bottomRight_y << "," <<
  f_POC << "," <<
  f_qtdepth << "," <<
  f_mtdepth << "," <<
  split << "," <<
  f_variance << "," <<
  f_mean << "," <<
  f_gradientH << "," <<
  f_gradientV << "," <<
  f_ratioGrad << "," <<
  f_sum << "," <<
  f_quarter1Var << "," <<
  f_quarter1Mean << "," <<
  f_quarter1GradH << "," <<
  f_quarter1GradV << "," <<
  f_quarter1RatioGrad << "," <<
  f_quarter1Sum << "," <<
  f_quarter2Var << "," <<
  f_quarter2Mean << "," <<
  f_quarter2GradH << "," <<
  f_quarter2GradV << "," <<
  f_quarter2RatioGrad << "," <<
  f_quarter2Sum << "," <<
  f_quarter3Var << "," <<
  f_quarter3Mean << "," <<
  f_quarter3GradH << "," <<
  f_quarter3GradV << "," <<
  f_quarter3RatioGrad << "," <<
  f_quarter3Sum << "," <<
  f_quarter4Var << "," <<
  f_quarter4Mean << "," <<
  f_quarter4GradH << "," <<
  f_quarter4GradV << "," <<
  f_quarter4RatioGrad << "," <<
  f_quarter4Sum << endl; */
}

int features::predictHORZSPLIT (Partitioner* partitioner)
{
 if(((partitioner->currArea().lheight() == 128) && (partitioner->currArea().lwidth() == 128)) )
  {
    float features_s0_horz[19];
    features_s0_horz[0] = f_paramQP;
    features_s0_horz[1] = f_variance;
    features_s0_horz[2] = f_mean;
    features_s0_horz[3] = f_gradientH;
    features_s0_horz[4] = f_gradientV;
    features_s0_horz[5] = f_ratioGrad;
    features_s0_horz[6] = f_sum;
    features_s0_horz[7] = f_quarter1Var;
    features_s0_horz[8] = f_quarter1Mean;
    features_s0_horz[9] = f_quarter1GradH;
    features_s0_horz[10] = f_quarter1GradV;
    features_s0_horz[11] = f_quarter1RatioGrad;
    features_s0_horz[12] = f_quarter1Sum;
    features_s0_horz[13] = f_quarter2Var;
    features_s0_horz[14] = f_quarter2Mean;
    features_s0_horz[15] = f_quarter2GradH;
    features_s0_horz[16] = f_quarter2GradV;
    features_s0_horz[17] = f_quarter2RatioGrad;
    features_s0_horz[18] = f_quarter2Sum;

    int decision = predict_s0_horz(features_s0_horz);
    fZeros();
    return decision;
  }
  else if(((partitioner->currArea().lheight() == 64) && (partitioner->currArea().lwidth() == 128)) ||
          ((partitioner->currArea().lheight() == 128) && (partitioner->currArea().lwidth() == 64)) )
  {
    float features_s1_horz[19];
    features_s1_horz[0] = f_paramQP;
    features_s1_horz[1] = f_variance;
    features_s1_horz[2] = f_mean;
    features_s1_horz[3] = f_gradientH;
    features_s1_horz[4] = f_gradientV;
    features_s1_horz[5] = f_ratioGrad;
    features_s1_horz[6] = f_sum;
    features_s1_horz[7] = f_quarter1Var;
    features_s1_horz[8] = f_quarter1Mean;
    features_s1_horz[9] = f_quarter1GradH;
    features_s1_horz[10] = f_quarter1GradV;
    features_s1_horz[11] = f_quarter1RatioGrad;
    features_s1_horz[12] = f_quarter1Sum;
    features_s1_horz[13] = f_quarter2Var;
    features_s1_horz[14] = f_quarter2Mean;
    features_s1_horz[15] = f_quarter2GradH;
    features_s1_horz[16] = f_quarter2GradV;
    features_s1_horz[17] = f_quarter2RatioGrad;
    features_s1_horz[18] = f_quarter2Sum;

    int decision = predict_s1_horz(features_s1_horz);
    fZeros();
    return decision;
  }
  
  else if(((partitioner->currArea().lheight() == 64) && (partitioner->currArea().lwidth() == 64)) ||
          ((partitioner->currArea().lheight() == 128) && (partitioner->currArea().lwidth() == 32)) ||
          ((partitioner->currArea().lheight() == 32) && (partitioner->currArea().lwidth() == 128)) )
  {
    float features_s2_horz[25];
    features_s2_horz[0] = f_paramQP;
    features_s2_horz[1] = f_variance;
    features_s2_horz[2] = f_mean;
    features_s2_horz[3] = f_gradientH;
    features_s2_horz[4] = f_gradientV;
    features_s2_horz[5] = f_ratioGrad;
    features_s2_horz[6] = f_sum;
    features_s2_horz[7] = f_quarter1Var;
    features_s2_horz[8] = f_quarter1Mean;
    features_s2_horz[9] = f_quarter1GradH;
    features_s2_horz[10] = f_quarter1GradV;
    features_s2_horz[11] = f_quarter1RatioGrad;
    features_s2_horz[12] = f_quarter1Sum;
    features_s2_horz[13] = f_quarter2Var;
    features_s2_horz[14] = f_quarter2Mean;
    features_s2_horz[15] = f_quarter2GradH;
    features_s2_horz[16] = f_quarter2GradV;
    features_s2_horz[17] = f_quarter2RatioGrad;
    features_s2_horz[18] = f_quarter2Sum;
    features_s2_horz[19] = f_quarter3Var;
    features_s2_horz[20] = f_quarter3Mean;
    features_s2_horz[21] = f_quarter3GradH;
    features_s2_horz[22] = f_quarter3GradV;
    features_s2_horz[23] = f_quarter3RatioGrad;
    features_s2_horz[24] = f_quarter3Sum;

    int decision = predict_s2_horz(features_s2_horz);
    fZeros();
    return decision;
  }

  else if(((partitioner->currArea().lheight() == 64) && (partitioner->currArea().lwidth() == 32)) ||
          ((partitioner->currArea().lheight() == 32) && (partitioner->currArea().lwidth() == 64)) ||
          ((partitioner->currArea().lheight() == 128) && (partitioner->currArea().lwidth() == 16)) ||
          ((partitioner->currArea().lheight() == 16) && (partitioner->currArea().lwidth() == 128))) 
  {
    float features_s3_horz[25];
    features_s3_horz[0] = f_paramQP;
    features_s3_horz[1] = f_variance;
    features_s3_horz[2] = f_mean;
    features_s3_horz[3] = f_gradientH;
    features_s3_horz[4] = f_gradientV;
    features_s3_horz[5] = f_ratioGrad;
    features_s3_horz[6] = f_sum;
    features_s3_horz[7] = f_quarter1Var;
    features_s3_horz[8] = f_quarter1Mean;
    features_s3_horz[9] = f_quarter1GradH;
    features_s3_horz[10] = f_quarter1GradV;
    features_s3_horz[11] = f_quarter1RatioGrad;
    features_s3_horz[12] = f_quarter1Sum;
    features_s3_horz[13] = f_quarter2Var;
    features_s3_horz[14] = f_quarter2Mean;
    features_s3_horz[15] = f_quarter2GradH;
    features_s3_horz[16] = f_quarter2GradV;
    features_s3_horz[17] = f_quarter2RatioGrad;
    features_s3_horz[18] = f_quarter2Sum;
    features_s3_horz[19] = f_quarter3Var;
    features_s3_horz[20] = f_quarter3Mean;
    features_s3_horz[21] = f_quarter3GradH;
    features_s3_horz[22] = f_quarter3GradV;
    features_s3_horz[23] = f_quarter3RatioGrad;
    features_s3_horz[24] = f_quarter3Sum;
    
    int decision = predict_s3_horz(features_s3_horz);
    fZeros();
    return decision;
  }

  else if(((partitioner->currArea().lheight() == 32) && (partitioner->currArea().lwidth() == 32)) ||
          ((partitioner->currArea().lheight() == 16) && (partitioner->currArea().lwidth() == 64)) ||
          ((partitioner->currArea().lheight() == 64) && (partitioner->currArea().lwidth() == 16)) ||
          ((partitioner->currArea().lheight() == 8) && (partitioner->currArea().lwidth() == 128)) ||
          ((partitioner->currArea().lheight() == 128) && (partitioner->currArea().lwidth() == 8)) )
  {
    float features_s4_horz[25];
    features_s4_horz[0] = f_paramQP;
    features_s4_horz[1] = f_variance;
    features_s4_horz[2] = f_mean;
    features_s4_horz[3] = f_gradientH;
    features_s4_horz[4] = f_gradientV;
    features_s4_horz[5] = f_ratioGrad;
    features_s4_horz[6] = f_sum;
    features_s4_horz[7] = f_quarter1Var;
    features_s4_horz[8] = f_quarter1Mean;
    features_s4_horz[9] = f_quarter1GradH;
    features_s4_horz[10] = f_quarter1GradV;
    features_s4_horz[11] = f_quarter1RatioGrad;
    features_s4_horz[12] = f_quarter1Sum;
    features_s4_horz[13] = f_quarter2Var;
    features_s4_horz[14] = f_quarter2Mean;
    features_s4_horz[15] = f_quarter2GradH;
    features_s4_horz[16] = f_quarter2GradV;
    features_s4_horz[17] = f_quarter2RatioGrad;
    features_s4_horz[18] = f_quarter2Sum;
    features_s4_horz[19] = f_quarter3Var;
    features_s4_horz[20] = f_quarter3Mean;
    features_s4_horz[21] = f_quarter3GradH;
    features_s4_horz[22] = f_quarter3GradV;
    features_s4_horz[23] = f_quarter3RatioGrad;
    features_s4_horz[24] = f_quarter3Sum;
    
    int decision = predict_s4_horz(features_s4_horz);
    fZeros();
    return decision;
  }

  else if(((partitioner->currArea().lheight() == 32) && (partitioner->currArea().lwidth() == 16)) ||
          ((partitioner->currArea().lheight() == 16) && (partitioner->currArea().lwidth() == 32)) ||
          ((partitioner->currArea().lheight() == 64) && (partitioner->currArea().lwidth() == 8)) ||
          ((partitioner->currArea().lheight() == 8) && (partitioner->currArea().lwidth() == 64)) )
  {
    float features_s5_horz[25];
    features_s5_horz[0] = f_paramQP;
    features_s5_horz[1] = f_variance;
    features_s5_horz[2] = f_mean;
    features_s5_horz[3] = f_gradientH;
    features_s5_horz[4] = f_gradientV;
    features_s5_horz[5] = f_ratioGrad;
    features_s5_horz[6] = f_sum;
    features_s5_horz[7] = f_quarter1Var;
    features_s5_horz[8] = f_quarter1Mean;
    features_s5_horz[9] = f_quarter1GradH;
    features_s5_horz[10] = f_quarter1GradV;
    features_s5_horz[11] = f_quarter1RatioGrad;
    features_s5_horz[12] = f_quarter1Sum;
    features_s5_horz[13] = f_quarter2Var;
    features_s5_horz[14] = f_quarter2Mean;
    features_s5_horz[15] = f_quarter2GradH;
    features_s5_horz[16] = f_quarter2GradV;
    features_s5_horz[17] = f_quarter2RatioGrad;
    features_s5_horz[18] = f_quarter2Sum;
    features_s5_horz[19] = f_quarter3Var;
    features_s5_horz[20] = f_quarter3Mean;
    features_s5_horz[21] = f_quarter3GradH;
    features_s5_horz[22] = f_quarter3GradV;
    features_s5_horz[23] = f_quarter3RatioGrad;
    features_s5_horz[24] = f_quarter3Sum;
    
    int decision = predict_s5_horz(features_s5_horz);
    fZeros();
    return decision;
  }

  else if(((partitioner->currArea().lheight() == 16) && (partitioner->currArea().lwidth() == 16)) ||
          ((partitioner->currArea().lheight() == 32) && (partitioner->currArea().lwidth() == 8)) ||
          ((partitioner->currArea().lheight() == 8) && (partitioner->currArea().lwidth() == 32)) )
  {
    float features_s6_horz[25];
    features_s6_horz[0] = f_paramQP;
    features_s6_horz[1] = f_variance;
    features_s6_horz[2] = f_mean;
    features_s6_horz[3] = f_gradientH;
    features_s6_horz[4] = f_gradientV;
    features_s6_horz[5] = f_ratioGrad;
    features_s6_horz[6] = f_sum;
    features_s6_horz[7] = f_quarter1Var;
    features_s6_horz[8] = f_quarter1Mean;
    features_s6_horz[9] = f_quarter1GradH;
    features_s6_horz[10] = f_quarter1GradV;
    features_s6_horz[11] = f_quarter1RatioGrad;
    features_s6_horz[12] = f_quarter1Sum;
    features_s6_horz[13] = f_quarter2Var;
    features_s6_horz[14] = f_quarter2Mean;
    features_s6_horz[15] = f_quarter2GradH;
    features_s6_horz[16] = f_quarter2GradV;
    features_s6_horz[17] = f_quarter2RatioGrad;
    features_s6_horz[18] = f_quarter2Sum;
    features_s6_horz[19] = f_quarter3Var;
    features_s6_horz[20] = f_quarter3Mean;
    features_s6_horz[21] = f_quarter3GradH;
    features_s6_horz[22] = f_quarter3GradV;
    features_s6_horz[23] = f_quarter3RatioGrad;
    features_s6_horz[24] = f_quarter3Sum;
    
    int decision = predict_s6_horz(features_s6_horz);
    fZeros();
    return decision;
  }
  else
  {
    return 1;
  }
}

int features::predictVERTSPLIT (Partitioner* partitioner, PartSplit split)
{
  if( (partitioner->currArea().lheight() == 128) && (partitioner->currArea().lwidth() == 128) )
  {
    float features_s0_vert[19];
    features_s0_vert[0] = f_paramQP;
    features_s0_vert[1] = f_variance;
    features_s0_vert[2] = f_mean;
    features_s0_vert[3] = f_gradientH;
    features_s0_vert[4] = f_gradientV;
    features_s0_vert[5] = f_ratioGrad;
    features_s0_vert[6] = f_sum;
    features_s0_vert[7] = f_quarter1Var;
    features_s0_vert[8] = f_quarter1Mean;
    features_s0_vert[9] = f_quarter1GradH;
    features_s0_vert[10] = f_quarter1GradV;
    features_s0_vert[11] = f_quarter1RatioGrad;
    features_s0_vert[12] = f_quarter1Sum;
    features_s0_vert[13] = f_quarter2Var;
    features_s0_vert[14] = f_quarter2Mean;
    features_s0_vert[15] = f_quarter2GradH;
    features_s0_vert[16] = f_quarter2GradV;
    features_s0_vert[17] = f_quarter2RatioGrad;
    features_s0_vert[18] = f_quarter2Sum;
    
    int decision =  predict_s0_vert(features_s0_vert);
    fZeros();
    return decision;
  }
  else if(((partitioner->currArea().lheight() == 128) && (partitioner->currArea().lwidth() == 64)) ||
          ((partitioner->currArea().lheight() == 64) && (partitioner->currArea().lwidth() == 128)) )
  {
    float features_s1_vert[19];
    features_s1_vert[0] = f_paramQP;
    features_s1_vert[1] = f_variance;
    features_s1_vert[2] = f_mean;
    features_s1_vert[3] = f_gradientH;
    features_s1_vert[4] = f_gradientV;
    features_s1_vert[5] = f_ratioGrad;
    features_s1_vert[6] = f_sum;
    features_s1_vert[7] = f_quarter1Var;
    features_s1_vert[8] = f_quarter1Mean;
    features_s1_vert[9] = f_quarter1GradH;
    features_s1_vert[10] = f_quarter1GradV;
    features_s1_vert[11] = f_quarter1RatioGrad;
    features_s1_vert[12] = f_quarter1Sum;
    features_s1_vert[13] = f_quarter2Var;
    features_s1_vert[14] = f_quarter2Mean;
    features_s1_vert[15] = f_quarter2GradH;
    features_s1_vert[16] = f_quarter2GradV;
    features_s1_vert[17] = f_quarter2RatioGrad;
    features_s1_vert[18] = f_quarter2Sum;
    
    int decision =  predict_s1_vert(features_s1_vert);
    fZeros();
    return decision;
  }
  else if(((partitioner->currArea().lheight() == 64) && (partitioner->currArea().lwidth() == 64)) ||
          ((partitioner->currArea().lheight() == 32) && (partitioner->currArea().lwidth() == 128)) ||
          ((partitioner->currArea().lheight() == 128) && (partitioner->currArea().lwidth() == 32))  )
  {

    float features_s2_vert[25];
    features_s2_vert[0] = f_paramQP;
    features_s2_vert[1] = f_variance;
    features_s2_vert[2] = f_mean;
    features_s2_vert[3] = f_gradientH;
    features_s2_vert[4] = f_gradientV;
    features_s2_vert[5] = f_ratioGrad;
    features_s2_vert[6] = f_sum;
    features_s2_vert[7] = f_quarter1Var;
    features_s2_vert[8] = f_quarter1Mean;
    features_s2_vert[9] = f_quarter1GradH;
    features_s2_vert[10] = f_quarter1GradV;
    features_s2_vert[11] = f_quarter1RatioGrad;
    features_s2_vert[12] = f_quarter1Sum;
    features_s2_vert[13] = f_quarter2Var;
    features_s2_vert[14] = f_quarter2Mean;
    features_s2_vert[15] = f_quarter2GradH;
    features_s2_vert[16] = f_quarter2GradV;
    features_s2_vert[17] = f_quarter2RatioGrad;
    features_s2_vert[18] = f_quarter2Sum;
    features_s2_vert[19] = f_quarter3Var;
    features_s2_vert[20] = f_quarter3Mean;
    features_s2_vert[21] = f_quarter3GradH;
    features_s2_vert[22] = f_quarter3GradV;
    features_s2_vert[23] = f_quarter3RatioGrad;
    features_s2_vert[24] = f_quarter3Sum;

    int decision = predict_s2_vert(features_s2_vert);
    fZeros();
    
    return decision;

  }
  else if(((partitioner->currArea().lheight() == 64) && (partitioner->currArea().lwidth() == 32)) ||
          ((partitioner->currArea().lheight() == 32) && (partitioner->currArea().lwidth() == 64)) ||
          ((partitioner->currArea().lheight() == 128) && (partitioner->currArea().lwidth() == 16)) ||
          ((partitioner->currArea().lheight() == 16) && (partitioner->currArea().lwidth() == 128))  )
  {
    float features_s3_vert[25];
    features_s3_vert[0] = f_paramQP;
    features_s3_vert[1] = f_variance;
    features_s3_vert[2] = f_mean;
    features_s3_vert[3] = f_gradientH;
    features_s3_vert[4] = f_gradientV;
    features_s3_vert[5] = f_ratioGrad;
    features_s3_vert[6] = f_sum;
    features_s3_vert[7] = f_quarter1Var;
    features_s3_vert[8] = f_quarter1Mean;
    features_s3_vert[9] = f_quarter1GradH;
    features_s3_vert[10] = f_quarter1GradV;
    features_s3_vert[11] = f_quarter1RatioGrad;
    features_s3_vert[12] = f_quarter1Sum;
    features_s3_vert[13] = f_quarter2Var;
    features_s3_vert[14] = f_quarter2Mean;
    features_s3_vert[15] = f_quarter2GradH;
    features_s3_vert[16] = f_quarter2GradV;
    features_s3_vert[17] = f_quarter2RatioGrad;
    features_s3_vert[18] = f_quarter2Sum;
    features_s3_vert[19] = f_quarter3Var;
    features_s3_vert[20] = f_quarter3Mean;
    features_s3_vert[21] = f_quarter3GradH;
    features_s3_vert[22] = f_quarter3GradV;
    features_s3_vert[23] = f_quarter3RatioGrad;
    features_s3_vert[24] = f_quarter3Sum;
        
    int decision =  predict_s3_vert(features_s3_vert);
    fZeros();
    return decision;
  }

  else if(((partitioner->currArea().lheight() == 32) && (partitioner->currArea().lwidth() == 32)) ||
          ((partitioner->currArea().lheight() == 16) && (partitioner->currArea().lwidth() == 64)) ||
          ((partitioner->currArea().lheight() == 64) && (partitioner->currArea().lwidth() == 16)) ||
          ((partitioner->currArea().lheight() == 8) && (partitioner->currArea().lwidth() == 128)) ||
          ((partitioner->currArea().lheight() == 128) && (partitioner->currArea().lwidth() == 8)) )
  {
    float features_s4_vert[25];
    features_s4_vert[0] = f_paramQP;
    features_s4_vert[1] = f_variance;
    features_s4_vert[2] = f_mean;
    features_s4_vert[3] = f_gradientH;
    features_s4_vert[4] = f_gradientV;
    features_s4_vert[5] = f_ratioGrad;
    features_s4_vert[6] = f_sum;
    features_s4_vert[7] = f_quarter1Var;
    features_s4_vert[8] = f_quarter1Mean;
    features_s4_vert[9] = f_quarter1GradH;
    features_s4_vert[10] = f_quarter1GradV;
    features_s4_vert[11] = f_quarter1RatioGrad;
    features_s4_vert[12] = f_quarter1Sum;
    features_s4_vert[13] = f_quarter2Var;
    features_s4_vert[14] = f_quarter2Mean;
    features_s4_vert[15] = f_quarter2GradH;
    features_s4_vert[16] = f_quarter2GradV;
    features_s4_vert[17] = f_quarter2RatioGrad;
    features_s4_vert[18] = f_quarter2Sum;
    features_s4_vert[19] = f_quarter3Var;
    features_s4_vert[20] = f_quarter3Mean;
    features_s4_vert[21] = f_quarter3GradH;
    features_s4_vert[22] = f_quarter3GradV;
    features_s4_vert[23] = f_quarter3RatioGrad;
    features_s4_vert[24] = f_quarter3Sum;
    
    int decision =  predict_s4_vert(features_s4_vert);
    fZeros();
    return decision;
  }

  else if(((partitioner->currArea().lheight() == 32) && (partitioner->currArea().lwidth() == 16)) ||
          ((partitioner->currArea().lheight() == 16) && (partitioner->currArea().lwidth() == 32)) ||
          ((partitioner->currArea().lheight() == 64) && (partitioner->currArea().lwidth() == 8)) ||
          ((partitioner->currArea().lheight() == 8) && (partitioner->currArea().lwidth() == 64)) )
  {
    float features_s5_vert[25];
    features_s5_vert[0] = f_paramQP;
    features_s5_vert[1] = f_variance;
    features_s5_vert[2] = f_mean;
    features_s5_vert[3] = f_gradientH;
    features_s5_vert[4] = f_gradientV;
    features_s5_vert[5] = f_ratioGrad;
    features_s5_vert[6] = f_sum;
    features_s5_vert[7] = f_quarter1Var;
    features_s5_vert[8] = f_quarter1Mean;
    features_s5_vert[9] = f_quarter1GradH;
    features_s5_vert[10] = f_quarter1GradV;
    features_s5_vert[11] = f_quarter1RatioGrad;
    features_s5_vert[12] = f_quarter1Sum;
    features_s5_vert[13] = f_quarter2Var;
    features_s5_vert[14] = f_quarter2Mean;
    features_s5_vert[15] = f_quarter2GradH;
    features_s5_vert[16] = f_quarter2GradV;
    features_s5_vert[17] = f_quarter2RatioGrad;
    features_s5_vert[18] = f_quarter2Sum;
    features_s5_vert[19] = f_quarter3Var;
    features_s5_vert[20] = f_quarter3Mean;
    features_s5_vert[21] = f_quarter3GradH;
    features_s5_vert[22] = f_quarter3GradV;
    features_s5_vert[23] = f_quarter3RatioGrad;
    features_s5_vert[24] = f_quarter3Sum;

    int decision =  predict_s5_vert(features_s5_vert);
    fZeros();
    return decision;
  }

  else if(((partitioner->currArea().lheight() == 16) && (partitioner->currArea().lwidth() == 16)) ||
          ((partitioner->currArea().lheight() == 32) && (partitioner->currArea().lwidth() == 8)) ||
          ((partitioner->currArea().lheight() == 8) && (partitioner->currArea().lwidth() == 32)) )
  {
    float features_s6_vert[25];
    features_s6_vert[0] = f_paramQP;
    features_s6_vert[1] = f_variance;
    features_s6_vert[2] = f_mean;
    features_s6_vert[3] = f_gradientH;
    features_s6_vert[4] = f_gradientV;
    features_s6_vert[5] = f_ratioGrad;
    features_s6_vert[6] = f_sum;
    features_s6_vert[7] = f_quarter1Var;
    features_s6_vert[8] = f_quarter1Mean;
    features_s6_vert[9] = f_quarter1GradH;
    features_s6_vert[10] = f_quarter1GradV;
    features_s6_vert[11] = f_quarter1RatioGrad;
    features_s6_vert[12] = f_quarter1Sum;
    features_s6_vert[13] = f_quarter2Var;
    features_s6_vert[14] = f_quarter2Mean;
    features_s6_vert[15] = f_quarter2GradH;
    features_s6_vert[16] = f_quarter2GradV;
    features_s6_vert[17] = f_quarter2RatioGrad;
    features_s6_vert[18] = f_quarter2Sum;
    features_s6_vert[19] = f_quarter3Var;
    features_s6_vert[20] = f_quarter3Mean;
    features_s6_vert[21] = f_quarter3GradH;
    features_s6_vert[22] = f_quarter3GradV;
    features_s6_vert[23] = f_quarter3RatioGrad;
    features_s6_vert[24] = f_quarter3Sum;

    int decision =  predict_s6_vert(features_s6_vert);
    fZeros();
    return decision;
  } 
  else
  {
    return 1;
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
      double ratioGrads = (grads[1] != 0) ? (double) grads[0] / (double) grads[1] : -1;

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
      quarters.push_back(quarterSum);
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
      double ratioGrads = (grads[1] != 0) ? (double) grads[0] / (double) grads[1] : -1;

      quarter_yTL += quarterHeight;
      quarter_yBR += quarterHeight;

      block--;

      quarters.push_back(quarterVar);
      quarters.push_back(mean);
      quarters.push_back(grads[0]);
      quarters.push_back(grads[1]);
      quarters.push_back(ratioGrads);
      quarters.push_back(quarterSum);
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
      double ratioGrads = (grads[1] != 0) ? (double) grads[0] / (double) grads[1] : -1;

      quarter_xTL += quarterWidth;
      quarter_xBR += quarterWidth;

      block--;

      quarters.push_back(quarterVar);
      quarters.push_back(mean);
      quarters.push_back(grads[0]);
      quarters.push_back(grads[1]);
      quarters.push_back(ratioGrads);
      quarters.push_back(quarterSum);
    }
  }
  
  else if(split == CU_TRIH_SPLIT)
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
      double ratioGrads = (grads[1] != 0) ? (double) grads[0] / (double) grads[1] : -1;

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
      quarters.push_back(quarterSum);
    }
  }

  else if(split == CU_TRIV_SPLIT)
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
      double ratioGrads = (grads[1] != 0) ? (double) grads[0] / (double) grads[1] : -1;

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
      quarters.push_back(quarterSum);
    }
  }
  return quarters;
}

void features::fZeros()
{
  f_CU_width            = -1;
  f_CU_height           = -1;
  f_topLeft_x           = -1;
  f_topLeft_y           = -1;
  f_bottomRight_x       = -1;
  f_bottomRight_y       = -1;
  f_POC                 = -1;
  f_qtdepth             = -1;
  f_mtdepth             = -1;
  f_variance            = -1;
  f_mean                = -1;
  f_gradientH           = -1;
  f_gradientV           = -1;
  f_ratioGrad           = -1;
  f_sum                 = -1;
  f_quarter1Var         = -1;
  f_quarter1Mean        = -1;
  f_quarter1GradH       = -1;
  f_quarter1GradV       = -1;
  f_quarter1RatioGrad   = -1;
  f_quarter1Sum         = -1;
  f_quarter2Var         = -1;
  f_quarter2Mean        = -1;
  f_quarter2GradH       = -1;
  f_quarter2GradV       = -1;
  f_quarter2RatioGrad   = -1;
  f_quarter2Sum         = -1;
  f_quarter3Var         = -1;
  f_quarter3Mean        = -1;
  f_quarter3GradH       = -1;
  f_quarter3GradV       = -1;
  f_quarter3RatioGrad   = -1;
  f_quarter3Sum         = -1;
  f_quarter4Var         = -1;
  f_quarter4Mean        = -1;
  f_quarter4GradH       = -1;
  f_quarter4GradV       = -1;
  f_quarter4RatioGrad   = -1;
  f_quarter4Sum         = -1;
  f_HIVar               = -1;
  f_HIMean              = -1;
  f_HIRatio             = -1;
  f_VIVar               = -1;
  f_VIMean              = -1;
  f_VIRatio             = -1;
  f_DiffInconsVar       = -1;
  f_DiffInconsMean      = -1;
  f_DiffInconsRatio     = -1;
  f_HIVIVar             = -1;
  f_HIVIMean            = -1;
  f_HIVIRatioGrad           = -1;
}