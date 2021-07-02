#include <iostream>
#include <fstream>
#include "Unit.h"
#include "CodingStructure.h"
#include "EncModeCtrl.h"
#include "UnitPartitioner.h" 
#include <algorithm>
#include <string.h>

using namespace std;

#define DATASET_EXTRACTION_FEATURES 0
#define DATASET_EXTRACTION_TARGET 0
#define DATASET_PIXEL 1

enum DepthCTUFrame
{
    PAST_QT_DEPTH       = 0,
    CURRENT_QT_DEPTH    = 1,
    PAST_MT_DEPTH       = 2,
    CURRENT_MT_DEPTH    = 3
};

enum DepthVector
{
    QT = 0,
    MT = 1
};

class features
{
private:
    static ofstream file_features;
    static ofstream file_target;
    
    /*Extract from EncAppCfg*/
    static string  videoName;
    static double  frameWidth;
    static double  frameHeight;
    static int     qp;

    /* Auxiliar Variables for Depths*/
    static int     previousCTUsize;
    static int     maxWidth;
    static int     maxHeight;
    static int     current_x;
    static int     current_y;
    static int***  CTUFrame;
    static int     tlMaxDepth[2];
    static int     tMaxDepth[2];
    static int     trMaxDepth[2];
    static int     lMaxDepth[2];
    static int     previousMaxDepth[2];
    static int     averageDepth[2];
    static int     modeDepth[2];
    static int     highestDepth[2]; 
    
    /* Auxiliar Variables for RD-Cost*/
    static double  interIMVRDCost;
    static double  interRDCost;
    static double  affineMergeRDCost;
    static double  cachedResultRDCost;
    static double  mergeRDCost;
    static double  mergeGeoRDCost;
    static double  intraRDCost;

    /* Auxiliar Variables for Pixel Features */
    static unsigned short CTUPixel[128][128];
    static int pixelHeight;
    static int pixelWidth;
    static int sum;

public:

    features                                (string m_videoName, int m_iQP, double m_iSourceWidth, double m_iSourceHeight);
    static void    createFile               ();
    static void    extract_features         (CodingUnit* cu, CodingStructure* cs, EncTestMode currTestMode);
    static void    ctuDepth                 (CodingStructure* cs);
    static int***  initCTUFrame             ();
    static void    updateCTUFrame           ();
    static void    neighbors                ();
    static int     checkAverage             (vector<int> depths);
    static int     checkMode                (vector<int> depths);
    static void    setInterIMVRDCost        (double m_interIMV);
    static void    setInterRDCost           (double m_inter);
    static void    setAffineMergeRDCost     (double m_affine);
    static void    setCachedResultRDCost    (double m_cached);
    static void    setMergeRDCost           (double m_merge);
    static void    setMergeGeoRDCost        (double m_geo);
    static void    setIntraRDCost           (double m_intra);
    static void    extractTarget            (CodingStructure* cs, CodingUnit* cu, EncTestMode currTestMode);
    static void    extractCUPixel           (CodingStructure* cs, PartSplit split);
    static double  variance                 ();
    static vector<double>  gradients        ();
    static vector<double>  quarterCU        (PartSplit split);
};