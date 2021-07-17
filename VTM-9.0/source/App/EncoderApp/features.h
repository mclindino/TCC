#include <iostream>
#include <fstream>
#include "Unit.h"
#include "CodingStructure.h"
#include "EncModeCtrl.h"
#include "UnitPartitioner.h" 
#include <algorithm>
#include <string.h>

//Modelos
//#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s0_QT_SPLIT.h"
//#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s0_HORZ_SPLIT.h"
//#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s0_VERT_SPLIT.h"

//#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s1_QT_SPLIT.h"
//#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s1_HORZ_SPLIT.h"
//#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s1_VERT_SPLIT.h"

//#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s2_QT_SPLIT.h"
//#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s2_HORZ_SPLIT.h"
#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s2_VERT_SPLIT.h"

//#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s3_QT_SPLIT.h"
//#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s3_HORZ_SPLIT.h"
#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s3_VERT_SPLIT.h"

//#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s4_QT_SPLIT.h"
//#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s4_HORZ_SPLIT.h"
#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s4_VERT_SPLIT.h"

//#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s5_QT_SPLIT.h"
#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s5_HORZ_SPLIT.h"
#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s5_VERT_SPLIT.h"

//#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s6_QT_SPLIT.h"
#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s6_HORZ_SPLIT.h"
#include "/home/lindino/Documentos/TCC/v3.0/VTM-9.0/source/Lib/EncoderLib/s6_VERT_SPLIT.h"

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
    static int            rf_paramQP;
    static int            rf_CU_width;
    static int            rf_CU_height;
    static int            rf_topLeft_x;
    static int            rf_topLeft_y;
    static int            rf_bottomRight_x;
    static int            rf_bottomRight_y;
    static int            rf_POC;
    static int            rf_qtdepth;
    static int            rf_mtdepth;
    static double         rf_variance;
    static double         rf_mean;
    static unsigned short rf_gradientH;
    static unsigned short rf_gradientV;
    static double         rf_ratioGrad;
    static int            rf_sum;
    static double         rf_quarter1Var;
    static double         rf_quarter1Mean;
    static unsigned short rf_quarter1GradH;
    static unsigned short rf_quarter1GradV;
    static double         rf_quarter1RatioGrad;
    static int            rf_quarter1Sum;
    static double         rf_quarter2Var;
    static double         rf_quarter2Mean;
    static unsigned short rf_quarter2GradH;
    static unsigned short rf_quarter2GradV;
    static double         rf_quarter2RatioGrad;
    static int            rf_quarter2Sum;
    static double         rf_quarter3Var;
    static double         rf_quarter3Mean;
    static unsigned short rf_quarter3GradH;
    static unsigned short rf_quarter3GradV;
    static double         rf_quarter3RatioGrad;
    static int            rf_quarter3Sum;
    static double         rf_quarter4Var;
    static double         rf_quarter4Mean;
    static unsigned short rf_quarter4GradH;
    static unsigned short rf_quarter4GradV;
    static double         rf_quarter4RatioGrad;
    static int            rf_quarter4Sum;
		

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
    static string enumToString                      (int value);
    static int predictQUADSPLIT                     (CodingStructure* cs);
    static int predictHORZSPLIT                     (CodingStructure* cs);
    static int predictVERTSPLIT                     (CodingStructure* cs);
    static float* getFeaturesRF                     (int type);
    static void pixelFeaturesZero                   ();
};