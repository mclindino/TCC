#include <iostream>
#include <fstream>
#include "Unit.h"
#include "CodingStructure.h"
#include "EncModeCtrl.h"
#include "UnitPartitioner.h" 
#include <algorithm>
#include <string.h>

//Modelos
#include "/home/lindino/Documentos/TCC/git/VTM-9.0/source/Lib/EncoderLib/s0_QT_SPLIT.h"
#include "/home/lindino/Documentos/TCC/git/VTM-9.0/source/Lib/EncoderLib/s0_HORZ_SPLIT.h"
#include "/home/lindino/Documentos/TCC/git/VTM-9.0/source/Lib/EncoderLib/s0_VERT_SPLIT.h"

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
    static ofstream file_pixel;

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
    static float rf_features[36];		

public:

    features                                        (string m_videoName, int m_iQP, double m_iSourceWidth, double m_iSourceHeight);
    static void    createFile                       ();
    static void    extractFeatures                 (CodingUnit* cu, CodingStructure* cs, EncTestMode currTestMode);
    static void    ctuDepth                         (CodingStructure* cs);
    static int***  initCTUFrame                     ();
    static void    updateCTUFrame                   ();
    static void    neighbors                        ();
    static int     checkAverage                     (vector<int> depths);
    static int     checkMode                        (vector<int> depths);
    static void    setInterIMVRDCost                (double m_interIMV);
    static void    setInterRDCost                   (double m_inter);
    static void    setAffineMergeRDCost             (double m_affine);
    static void    setCachedResultRDCost            (double m_cached);
    static void    setMergeRDCost                   (double m_merge);
    static void    setMergeGeoRDCost                (double m_geo);
    static void    setIntraRDCost                   (double m_intra);
    static void    extractTarget                    (CodingStructure* cs, CodingUnit* cu, EncTestMode currTestMode);
    static void    extractCUPixel                   (CodingStructure* cs, PartSplit split, Partitioner* partitioner);
    static double  variance                         (int xTL, int yTL, int xBR, int yBR, int varSum);
    static vector<unsigned short>  gradients        (int xTL, int yTL, int xBR, int yBR);
    static vector<double>  quarterCU                (int xTL, int yTL, int xBR, int yBR, PartSplit split);
    static int predictQUADSPLIT                     (CodingStructure* cs);
    static int predictHORZSPLIT                     (CodingStructure* cs);
    static int predictVERTSPLIT                     (CodingStructure* cs);
    static float* getFeaturesRF                     (int type);
    static void pixelFeaturesZero                   ();
};