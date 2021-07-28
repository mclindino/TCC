#include "s4_HORZ_SPLIT.h"
int predict_0_s4_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[27] <= 4768.0) {
        if (features[12] <= 335.5800018310547) {
            if (features[20] <= 32688.0) {
                classes[0] = 0; 
                classes[1] = 4; 
            } else {
                if (features[2] <= 34.5) {
                    classes[0] = 0; 
                    classes[1] = 3; 
                } else {
                    classes[0] = 1; 
                    classes[1] = 0; 
                }
            }
        } else {
            if (features[28] <= 21.130000114440918) {
                if (features[6] <= 112.0) {
                    if (features[2] <= 34.5) {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    }
                } else {
                    classes[0] = 0; 
                    classes[1] = 3; 
                }
            } else {
                classes[0] = 2; 
                classes[1] = 0; 
            }
        }
    } else {
        if (features[24] <= 471.9250030517578) {
            if (features[31] <= 488.82049560546875) {
                classes[0] = 10; 
                classes[1] = 0; 
            } else {
                if (features[26] <= 3088.0) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                } else {
                    classes[0] = 3; 
                    classes[1] = 0; 
                }
            }
        } else {
            if (features[7] <= 207.0) {
                classes[0] = 0; 
                classes[1] = 2; 
            } else {
                if (features[12] <= 489.30149841308594) {
                    if (features[2] <= 29.5) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    }
                } else {
                    if (features[2] <= 29.5) {
                        classes[0] = 5; 
                        classes[1] = 0; 
                    } else {
                        if (features[23] <= 256042.0) {
                            classes[0] = 0; 
                            classes[1] = 2; 
                        } else {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        }
                    }
                }
            }
        }
    }
    int class_idx = 0;
    int class_val = classes[0];
    int i;
    for (i = 1; i < 2; i++) {
        if (classes[i] > class_val) {
            class_idx = i;
            class_val = classes[i];
        }
    }
    return class_idx;
}

int predict_1_s4_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[32] <= 15.5) {
        if (features[28] <= 0.11773204989731312) {
            if (features[27] <= 60160.0) {
                classes[0] = 4; 
                classes[1] = 0; 
            } else {
                if (features[2] <= 34.5) {
                    classes[0] = 2; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 1; 
                }
            }
        } else {
            if (features[22] <= 0.9975990355014801) {
                if (features[27] <= 928.0) {
                    classes[0] = 1; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 9; 
                }
            } else {
                if (features[18] <= 353.67999267578125) {
                    classes[0] = 3; 
                    classes[1] = 0; 
                } else {
                    if (features[17] <= 416302.0) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        if (features[21] <= 60224.0) {
                            if (features[2] <= 24.5) {
                                classes[0] = 1; 
                                classes[1] = 0; 
                            } else {
                                classes[0] = 0; 
                                classes[1] = 6; 
                            }
                        } else {
                            if (features[2] <= 34.5) {
                                if (features[2] <= 29.5) {
                                    classes[0] = 1; 
                                    classes[1] = 0; 
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 3; 
                                }
                            } else {
                                classes[0] = 2; 
                                classes[1] = 0; 
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (features[21] <= 63376.0) {
            classes[0] = 7; 
            classes[1] = 0; 
        } else {
            classes[0] = 0; 
            classes[1] = 1; 
        }
    }
    int class_idx = 0;
    int class_val = classes[0];
    int i;
    for (i = 1; i < 2; i++) {
        if (classes[i] > class_val) {
            class_idx = i;
            class_val = classes[i];
        }
    }
    return class_idx;
}

int predict_2_s4_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[14] <= 2016.0) {
        classes[0] = 5; 
        classes[1] = 0; 
    } else {
        if (features[14] <= 61760.0) {
            if (features[31] <= 511.625) {
                if (features[15] <= 3952.0) {
                    if (features[2] <= 34.5) {
                        if (features[20] <= 3456.0) {
                            classes[0] = 4; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 6; 
                        }
                    } else {
                        if (features[8] <= 79.0) {
                            classes[0] = 6; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        }
                    }
                } else {
                    if (features[17] <= 428276.0) {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    } else {
                        if (features[18] <= 330.7519989013672) {
                            if (features[2] <= 34.5) {
                                classes[0] = 1; 
                                classes[1] = 0; 
                            } else {
                                classes[0] = 0; 
                                classes[1] = 1; 
                            }
                        } else {
                            classes[0] = 0; 
                            classes[1] = 11; 
                        }
                    }
                }
            } else {
                classes[0] = 1; 
                classes[1] = 0; 
            }
        } else {
            classes[0] = 4; 
            classes[1] = 0; 
        }
    }
    int class_idx = 0;
    int class_val = classes[0];
    int i;
    for (i = 1; i < 2; i++) {
        if (classes[i] > class_val) {
            class_idx = i;
            class_val = classes[i];
        }
    }
    return class_idx;
}

int predict_3_s4_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[34] <= 0.7291780114173889) {
        if (features[12] <= 412.4949951171875) {
            if (features[14] <= 61760.0) {
                classes[0] = 0; 
                classes[1] = 13; 
            } else {
                classes[0] = 2; 
                classes[1] = 0; 
            }
        } else {
            if (features[2] <= 32.0) {
                classes[0] = 11; 
                classes[1] = 0; 
            } else {
                if (features[28] <= 0.038642000406980515) {
                    classes[0] = 2; 
                    classes[1] = 0; 
                } else {
                    if (features[27] <= 2704.0) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 7; 
                    }
                }
            }
        }
    } else {
        classes[0] = 6; 
        classes[1] = 0; 
    }
    int class_idx = 0;
    int class_val = classes[0];
    int i;
    for (i = 1; i < 2; i++) {
        if (classes[i] > class_val) {
            class_idx = i;
            class_val = classes[i];
        }
    }
    return class_idx;
}

int predict_4_s4_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[27] <= 24224.0) {
        if (features[25] <= 433.2070007324219) {
            if (features[14] <= 56944.0) {
                classes[0] = 4; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 2; 
            }
        } else {
            if (features[18] <= 330.7519989013672) {
                if (features[8] <= 143.0) {
                    classes[0] = 3; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 3; 
                }
            } else {
                classes[0] = 0; 
                classes[1] = 9; 
            }
        }
    } else {
        if (features[15] <= 61264.0) {
            if (features[21] <= 35392.0) {
                if (features[29] <= 270964.0) {
                    if (features[2] <= 34.5) {
                        classes[0] = 5; 
                        classes[1] = 0; 
                    } else {
                        if (features[6] <= 48.0) {
                            classes[0] = 2; 
                            classes[1] = 0; 
                        } else {
                            if (features[16] <= 0.7680894332006574) {
                                classes[0] = 2; 
                                classes[1] = 0; 
                            } else {
                                classes[0] = 0; 
                                classes[1] = 1; 
                            }
                        }
                    }
                } else {
                    classes[0] = 0; 
                    classes[1] = 1; 
                }
            } else {
                classes[0] = 0; 
                classes[1] = 1; 
            }
        } else {
            classes[0] = 9; 
            classes[1] = 0; 
        }
    }
    int class_idx = 0;
    int class_val = classes[0];
    int i;
    for (i = 1; i < 2; i++) {
        if (classes[i] > class_val) {
            class_idx = i;
            class_val = classes[i];
        }
    }
    return class_idx;
}

int predict_5_s4_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[21] <= 5904.0) {
        if (features[14] <= 4496.0) {
            if (features[18] <= 419.35899353027344) {
                classes[0] = 1; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 1; 
            }
        } else {
            if (features[18] <= 3166.590087890625) {
                classes[0] = 14; 
                classes[1] = 0; 
            } else {
                if (features[2] <= 29.5) {
                    classes[0] = 1; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 1; 
                }
            }
        }
    } else {
        if (features[20] <= 64384.0) {
            if (features[28] <= 21.130000114440918) {
                if (features[15] <= 61488.0) {
                    classes[0] = 0; 
                    classes[1] = 6; 
                } else {
                    if (features[27] <= 64736.0) {
                        if (features[2] <= 34.5) {
                            classes[0] = 0; 
                            classes[1] = 2; 
                        } else {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        }
                    } else {
                        if (features[2] <= 34.5) {
                            classes[0] = 0; 
                            classes[1] = 5; 
                        } else {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        }
                    }
                }
            } else {
                if (features[14] <= 59600.0) {
                    classes[0] = 2; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 3; 
                }
            }
        } else {
            classes[0] = 4; 
            classes[1] = 0; 
        }
    }
    int class_idx = 0;
    int class_val = classes[0];
    int i;
    for (i = 1; i < 2; i++) {
        if (classes[i] > class_val) {
            class_idx = i;
            class_val = classes[i];
        }
    }
    return class_idx;
}

int predict_6_s4_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[29] <= 270964.0) {
        if (features[14] <= 62112.0) {
            if (features[22] <= 55.33730125427246) {
                if (features[24] <= 221.90750122070312) {
                    classes[0] = 0; 
                    classes[1] = 2; 
                } else {
                    if (features[31] <= 207.74200439453125) {
                        if (features[16] <= 474.316650390625) {
                            if (features[27] <= 3024.0) {
                                classes[0] = 4; 
                                classes[1] = 0; 
                            } else {
                                if (features[7] <= 367.0) {
                                    if (features[25] <= 455.4530029296875) {
                                        classes[0] = 1; 
                                        classes[1] = 0; 
                                    } else {
                                        if (features[12] <= 370.7169952392578) {
                                            if (features[2] <= 34.5) {
                                                classes[0] = 0; 
                                                classes[1] = 1; 
                                            } else {
                                                classes[0] = 1; 
                                                classes[1] = 0; 
                                            }
                                        } else {
                                            if (features[2] <= 32.0) {
                                                classes[0] = 2; 
                                                classes[1] = 0; 
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 2; 
                                            }
                                        }
                                    }
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 1; 
                                }
                            }
                        } else {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        }
                    } else {
                        classes[0] = 7; 
                        classes[1] = 0; 
                    }
                }
            } else {
                classes[0] = 0; 
                classes[1] = 2; 
            }
        } else {
            classes[0] = 11; 
            classes[1] = 0; 
        }
    } else {
        if (features[12] <= 354.1784973144531) {
            classes[0] = 1; 
            classes[1] = 0; 
        } else {
            classes[0] = 0; 
            classes[1] = 6; 
        }
    }
    int class_idx = 0;
    int class_val = classes[0];
    int i;
    for (i = 1; i < 2; i++) {
        if (classes[i] > class_val) {
            class_idx = i;
            class_val = classes[i];
        }
    }
    return class_idx;
}

int predict_7_s4_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[31] <= 511.625) {
        if (features[28] <= 37.200798988342285) {
            if (features[21] <= 1936.0) {
                if (features[6] <= 80.0) {
                    classes[0] = 3; 
                    classes[1] = 0; 
                } else {
                    if (features[2] <= 32.0) {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    }
                }
            } else {
                if (features[19] <= 516.75) {
                    if (features[16] <= 0.062168450094759464) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        if (features[29] <= 214294.0) {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        } else {
                            if (features[23] <= 263674.0) {
                                if (features[2] <= 34.5) {
                                    classes[0] = 0; 
                                    classes[1] = 5; 
                                } else {
                                    if (features[16] <= 0.5437224917113781) {
                                        classes[0] = 0; 
                                        classes[1] = 2; 
                                    } else {
                                        if (features[22] <= 5.585499942302704) {
                                            classes[0] = 2; 
                                            classes[1] = 0; 
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 1; 
                                        }
                                    }
                                }
                            } else {
                                if (features[2] <= 34.5) {
                                    classes[0] = 2; 
                                    classes[1] = 0; 
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 1; 
                                }
                            }
                        }
                    }
                } else {
                    classes[0] = 0; 
                    classes[1] = 4; 
                }
            }
        } else {
            if (features[12] <= 293.802001953125) {
                classes[0] = 0; 
                classes[1] = 2; 
            } else {
                if (features[2] <= 34.5) {
                    classes[0] = 0; 
                    classes[1] = 9; 
                } else {
                    classes[0] = 1; 
                    classes[1] = 0; 
                }
            }
        }
    } else {
        classes[0] = 5; 
        classes[1] = 0; 
    }
    int class_idx = 0;
    int class_val = classes[0];
    int i;
    for (i = 1; i < 2; i++) {
        if (classes[i] > class_val) {
            class_idx = i;
            class_val = classes[i];
        }
    }
    return class_idx;
}

int predict_8_s4_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[21] <= 34336.0) {
        if (features[13] <= 528.2734985351562) {
            if (features[2] <= 34.5) {
                classes[0] = 8; 
                classes[1] = 0; 
            } else {
                if (features[13] <= 506.32850646972656) {
                    if (features[18] <= 3166.590087890625) {
                        classes[0] = 7; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    }
                } else {
                    classes[0] = 0; 
                    classes[1] = 3; 
                }
            }
        } else {
            classes[0] = 0; 
            classes[1] = 3; 
        }
    } else {
        if (features[27] <= 64736.0) {
            if (features[2] <= 34.5) {
                classes[0] = 0; 
                classes[1] = 16; 
            } else {
                classes[0] = 2; 
                classes[1] = 0; 
            }
        } else {
            classes[0] = 2; 
            classes[1] = 0; 
        }
    }
    int class_idx = 0;
    int class_val = classes[0];
    int i;
    for (i = 1; i < 2; i++) {
        if (classes[i] > class_val) {
            class_idx = i;
            class_val = classes[i];
        }
    }
    return class_idx;
}

int predict_9_s4_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[8] <= 111.0) {
        if (features[14] <= 51472.0) {
            classes[0] = 10; 
            classes[1] = 0; 
        } else {
            if (features[23] <= 280884.0) {
                if (features[20] <= 63488.0) {
                    if (features[14] <= 61408.0) {
                        if (features[2] <= 29.5) {
                            classes[0] = 0; 
                            classes[1] = 2; 
                        } else {
                            classes[0] = 4; 
                            classes[1] = 0; 
                        }
                    } else {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    }
                } else {
                    if (features[15] <= 33152.0) {
                        classes[0] = 0; 
                        classes[1] = 2; 
                    } else {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    }
                }
            } else {
                classes[0] = 2; 
                classes[1] = 0; 
            }
        }
    } else {
        if (features[14] <= 2016.0) {
            classes[0] = 4; 
            classes[1] = 0; 
        } else {
            if (features[5] <= 208.0) {
                classes[0] = 0; 
                classes[1] = 6; 
            } else {
                if (features[20] <= 63200.0) {
                    if (features[28] <= 9.727885365486145) {
                        if (features[2] <= 34.5) {
                            classes[0] = 0; 
                            classes[1] = 2; 
                        } else {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        }
                    } else {
                        classes[0] = 0; 
                        classes[1] = 2; 
                    }
                } else {
                    if (features[23] <= 183274.0) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        if (features[2] <= 29.5) {
                            classes[0] = 2; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 2; 
                        }
                    }
                }
            }
        }
    }
    int class_idx = 0;
    int class_val = classes[0];
    int i;
    for (i = 1; i < 2; i++) {
        if (classes[i] > class_val) {
            class_idx = i;
            class_val = classes[i];
        }
    }
    return class_idx;
}

int predict_s4_HORZ_SPLIT (float features[]) {
    int n_classes = 2;
    int classes[n_classes];
    int i;
    for (i = 0; i < n_classes; i++) {
        classes[i] = 0;
    }

    classes[predict_0_s4_HORZ_SPLIT(features)]++;
    classes[predict_1_s4_HORZ_SPLIT(features)]++;
    classes[predict_2_s4_HORZ_SPLIT(features)]++;
    classes[predict_3_s4_HORZ_SPLIT(features)]++;
    classes[predict_4_s4_HORZ_SPLIT(features)]++;
    classes[predict_5_s4_HORZ_SPLIT(features)]++;
    classes[predict_6_s4_HORZ_SPLIT(features)]++;
    classes[predict_7_s4_HORZ_SPLIT(features)]++;
    classes[predict_8_s4_HORZ_SPLIT(features)]++;
    classes[predict_9_s4_HORZ_SPLIT(features)]++;

    int class_idx = 0;
    int class_val = classes[0];
    for (i = 1; i < n_classes; i++) {
        if (classes[i] > class_val) {
            class_idx = i;
            class_val = classes[i];
        }
    }
    return class_idx;
}
