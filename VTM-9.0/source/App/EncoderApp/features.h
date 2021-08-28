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

#include "/home/lindino/Documentos/TCC/git/VTM-9.0/source/Lib/EncoderLib/s1_HORZ_SPLIT.h"
#include "/home/lindino/Documentos/TCC/git/VTM-9.0/source/Lib/EncoderLib/s1_VERT_SPLIT.h"

#include "/home/lindino/Documentos/TCC/git/VTM-9.0/source/Lib/EncoderLib/s2_QT_SPLIT.h"
#include "/home/lindino/Documentos/TCC/git/VTM-9.0/source/Lib/EncoderLib/s2_HORZ_SPLIT.h"
#include "/home/lindino/Documentos/TCC/git/VTM-9.0/source/Lib/EncoderLib/s2_VERT_SPLIT.h"

#include "/home/lindino/Documentos/TCC/git/VTM-9.0/source/Lib/EncoderLib/s3_HORZ_SPLIT.h"
#include "/home/lindino/Documentos/TCC/git/VTM-9.0/source/Lib/EncoderLib/s3_VERT_SPLIT.h"

#include "/home/lindino/Documentos/TCC/git/VTM-9.0/source/Lib/EncoderLib/s4_QT_SPLIT.h"
#include "/home/lindino/Documentos/TCC/git/VTM-9.0/source/Lib/EncoderLib/s4_HORZ_SPLIT.h"
#include "/home/lindino/Documentos/TCC/git/VTM-9.0/source/Lib/EncoderLib/s4_VERT_SPLIT.h"

#include "/home/lindino/Documentos/TCC/git/VTM-9.0/source/Lib/EncoderLib/s5_HORZ_SPLIT.h"
#include "/home/lindino/Documentos/TCC/git/VTM-9.0/source/Lib/EncoderLib/s5_VERT_SPLIT.h"

#include "/home/lindino/Documentos/TCC/git/VTM-9.0/source/Lib/EncoderLib/s6_QT_SPLIT.h"
#include "/home/lindino/Documentos/TCC/git/VTM-9.0/source/Lib/EncoderLib/s6_HORZ_SPLIT.h"
#include "/home/lindino/Documentos/TCC/git/VTM-9.0/source/Lib/EncoderLib/s6_VERT_SPLIT.h"


using namespace std;

#define DATASET_EXTRACTION_FEATURES 1
#define DATASET_EXTRACTION_TARGET 1
#define DATASET_PIXEL 0

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
    static ofstream check_file;
    
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
    static double f_paramQP;
    static double f_CU_width;
    static double f_CU_height;
    static double f_topLeft_x;
    static double f_topLeft_y;
    static double f_bottomRight_x;
    static double f_bottomRight_y;
    static double f_POC;
    static double f_qtdepth;
    static double f_mtdepth;
    static double f_variance;
    static double f_mean;
    static double f_gradientH;
    static double f_gradientV;
    static double f_ratioGrad;
    static double f_sum;
    static double f_quarter1Var;
    static double f_quarter1Mean;
    static double f_quarter1GradH;
    static double f_quarter1GradV;
    static double f_quarter1RatioGrad;
    static double f_quarter1Sum;
    static double f_quarter2Var;
    static double f_quarter2Mean;
    static double f_quarter2GradH;
    static double f_quarter2GradV;
    static double f_quarter2RatioGrad;
    static double f_quarter2Sum;
    static double f_quarter3Var;
    static double f_quarter3Mean;
    static double f_quarter3GradH;
    static double f_quarter3GradV;
    static double f_quarter3RatioGrad;
    static double f_quarter3Sum;
    static double f_quarter4Var;
    static double f_quarter4Mean;
    static double f_quarter4GradH;
    static double f_quarter4GradV;
    static double f_quarter4RatioGrad;
    static double f_quarter4Sum;
    static double f_HIVar;
    static double f_HIMean;
    static double f_HIRatio;
    static double f_VIVar;
    static double f_VIMean;
    static double f_VIRatio;
    static double f_DiffInconsVar;
    static double f_DiffInconsMean;
    static double f_DiffInconsRatio;
    static double f_HIVIVar;
    static double f_HIVIMean;
    static double f_HIVIRatioGrad;	

public:

    features                                        (string m_videoName, int m_iQP, double m_iSourceWidth, double m_iSourceHeight);
    static void    createFile                       ();
    static void    extractFeatures                  (CodingUnit* cu, CodingStructure* cs, EncTestMode currTestMode);
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
    static void    extractTarget                    (CodingStructure* cs, CodingUnit* cu); //, EncTestMode currTestMode);
    static void    extractCUPixel                   (CodingStructure* cs, PartSplit split, Partitioner* partitioner);//, CodingUnit* cu);
    static double  variance                         (int xTL, int yTL, int xBR, int yBR, int varSum);
    static vector<unsigned short>  gradients        (int xTL, int yTL, int xBR, int yBR);
    static vector<double>  quarterCU                (int xTL, int yTL, int xBR, int yBR, PartSplit split);
    //static int predictQUADSPLIT                     (Partitioner* partitioner);
    static int predictHORZSPLIT                     (Partitioner* partitioner);
    static int predictVERTSPLIT                     (Partitioner* partitioner, PartSplit split);
    static float* selectFeatures                    (int type);
    static void fZeros                              ();
};