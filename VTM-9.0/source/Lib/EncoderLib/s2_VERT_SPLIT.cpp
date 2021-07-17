#include "s2_VERT_SPLIT.h"
int predict_0_s2_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[15] <= 445.280029296875) {
        if (features[6] <= 0.5) {
            classes[0] = 0; 
            classes[1] = 124; 
        } else {
            classes[0] = 17; 
            classes[1] = 0; 
        }
    } else {
        if (features[24] <= 0.8841298520565033) {
            if (features[24] <= 0.10151352174580097) {
                if (features[7] <= 1.0) {
                    classes[0] = 3; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 2; 
                }
            } else {
                classes[0] = 0; 
                classes[1] = 8; 
            }
        } else {
            if (features[6] <= 0.5) {
                if (features[5] <= 1.5) {
                    if (features[10] <= 11967.68017578125) {
                        classes[0] = 3; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 23; 
                    }
                } else {
                    classes[0] = 12; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 102; 
                classes[1] = 0; 
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

int predict_1_s2_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[15] <= 437.33372497558594) {
        if (features[8] <= 28768.2109375) {
            if (features[0] <= 36.945180892944336) {
                classes[0] = 0; 
                classes[1] = 113; 
            } else {
                if (features[24] <= 1.037664771080017) {
                    if (features[9] <= 436.97265625) {
                        if (features[9] <= 390.65087890625) {
                            classes[0] = 2; 
                            classes[1] = 0; 
                        } else {
                            if (features[10] <= 50688.0) {
                                if (features[7] <= 1.0) {
                                    classes[0] = 3; 
                                    classes[1] = 0; 
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 1; 
                                }
                            } else {
                                classes[0] = 1; 
                                classes[1] = 0; 
                            }
                        }
                    } else {
                        if (features[6] <= 0.5) {
                            classes[0] = 0; 
                            classes[1] = 3; 
                        } else {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        }
                    }
                } else {
                    classes[0] = 6; 
                    classes[1] = 0; 
                }
            }
        } else {
            if (features[7] <= 1.0) {
                classes[0] = 4; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 1; 
            }
        }
    } else {
        if (features[1] <= 126.67211532592773) {
            if (features[22] <= 58316.609375) {
                if (features[10] <= 12855.58642578125) {
                    if (features[7] <= 1.0) {
                        classes[0] = 4; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    }
                } else {
                    classes[0] = 0; 
                    classes[1] = 13; 
                }
            } else {
                classes[0] = 10; 
                classes[1] = 0; 
            }
        } else {
            if (features[10] <= 36043.8798828125) {
                if (features[24] <= 4.196111440658569) {
                    if (features[6] <= 0.5) {
                        classes[0] = 0; 
                        classes[1] = 9; 
                    } else {
                        classes[0] = 8; 
                        classes[1] = 0; 
                    }
                } else {
                    classes[0] = 27; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 87; 
                classes[1] = 0; 
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

int predict_2_s2_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[6] <= 0.5) {
        if (features[22] <= 51983.203125) {
            if (features[11] <= 5518.35791015625) {
                if (features[24] <= 4.298765659332275) {
                    classes[0] = 0; 
                    classes[1] = 7; 
                } else {
                    classes[0] = 8; 
                    classes[1] = 0; 
                }
            } else {
                if (features[9] <= 546.8883056640625) {
                    if (features[29] <= 1775.5) {
                        if (features[11] <= 61712.0) {
                            classes[0] = 0; 
                            classes[1] = 151; 
                        } else {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        }
                    } else {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    }
                } else {
                    classes[0] = 2; 
                    classes[1] = 0; 
                }
            }
        } else {
            classes[0] = 10; 
            classes[1] = 0; 
        }
    } else {
        classes[0] = 114; 
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

int predict_3_s2_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[3] <= 190.62503814697266) {
        if (features[12] <= 0.5398088991641998) {
            if (features[1] <= 72.39016342163086) {
                if (features[2] <= 0.8709589242935181) {
                    classes[0] = 24; 
                    classes[1] = 0; 
                } else {
                    if (features[0] <= 29.90347957611084) {
                        classes[0] = 0; 
                        classes[1] = 3; 
                    } else {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    }
                }
            } else {
                classes[0] = 0; 
                classes[1] = 4; 
            }
        } else {
            if (features[4] <= 159.0) {
                if (features[13] <= 1626335.4375) {
                    if (features[7] <= 1.0) {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 14; 
                    }
                } else {
                    if (features[0] <= 36.90323257446289) {
                        classes[0] = 0; 
                        classes[1] = 83; 
                    } else {
                        if (features[1] <= 32.0) {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        }
                    }
                }
            } else {
                classes[0] = 1; 
                classes[1] = 0; 
            }
        }
    } else {
        if (features[23] <= 19698.642578125) {
            if (features[11] <= 2904.675048828125) {
                if (features[23] <= 5712.0) {
                    classes[0] = 10; 
                    classes[1] = 0; 
                } else {
                    if (features[7] <= 1.0) {
                        classes[0] = 5; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 7; 
                    }
                }
            } else {
                if (features[2] <= 20.99822235107422) {
                    classes[0] = 49; 
                    classes[1] = 0; 
                } else {
                    if (features[4] <= 123.79197311401367) {
                        classes[0] = 0; 
                        classes[1] = 2; 
                    } else {
                        classes[0] = 21; 
                        classes[1] = 0; 
                    }
                }
            }
        } else {
            if (features[22] <= 40522.099609375) {
                classes[0] = 0; 
                classes[1] = 25; 
            } else {
                if (features[6] <= 0.5) {
                    if (features[22] <= 57305.921875) {
                        classes[0] = 0; 
                        classes[1] = 5; 
                    } else {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    }
                } else {
                    classes[0] = 33; 
                    classes[1] = 0; 
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

int predict_4_s2_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[8] <= 11709.81201171875) {
        if (features[6] <= 0.5) {
            if (features[5] <= 1.6319671869277954) {
                if (features[23] <= 2960.0) {
                    classes[0] = 1; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 31; 
                }
            } else {
                classes[0] = 15; 
                classes[1] = 0; 
            }
        } else {
            classes[0] = 112; 
            classes[1] = 0; 
        }
    } else {
        if (features[4] <= 159.0) {
            if (features[9] <= 475.0404510498047) {
                if (features[6] <= 0.5) {
                    classes[0] = 0; 
                    classes[1] = 119; 
                } else {
                    classes[0] = 3; 
                    classes[1] = 0; 
                }
            } else {
                if (features[0] <= 24.5) {
                    classes[0] = 0; 
                    classes[1] = 2; 
                } else {
                    classes[0] = 6; 
                    classes[1] = 0; 
                }
            }
        } else {
            classes[0] = 5; 
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

int predict_5_s2_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[19] <= 906481.03125) {
        if (features[0] <= 36.945180892944336) {
            if (features[7] <= 1.0) {
                classes[0] = 3; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 141; 
            }
        } else {
            classes[0] = 5; 
            classes[1] = 0; 
        }
    } else {
        if (features[0] <= 30.613672256469727) {
            if (features[17] <= 51944.83203125) {
                classes[0] = 20; 
                classes[1] = 0; 
            } else {
                if (features[2] <= 0.8709589242935181) {
                    if (features[21] <= 541.9130859375) {
                        classes[0] = 7; 
                        classes[1] = 0; 
                    } else {
                        if (features[0] <= 24.5) {
                            if (features[7] <= 1.0) {
                                classes[0] = 1; 
                                classes[1] = 0; 
                            } else {
                                classes[0] = 0; 
                                classes[1] = 2; 
                            }
                        } else {
                            classes[0] = 2; 
                            classes[1] = 0; 
                        }
                    }
                } else {
                    if (features[6] <= 0.5) {
                        classes[0] = 0; 
                        classes[1] = 28; 
                    } else {
                        classes[0] = 10; 
                        classes[1] = 0; 
                    }
                }
            }
        } else {
            classes[0] = 75; 
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

int predict_6_s2_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[19] <= 911933.5) {
        if (features[0] <= 36.945180892944336) {
            if (features[14] <= 39055.162109375) {
                if (features[23] <= 49331.865234375) {
                    classes[0] = 0; 
                    classes[1] = 91; 
                } else {
                    if (features[16] <= 18416.0) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 21; 
                    }
                }
            } else {
                if (features[13] <= 1950364.0) {
                    if (features[6] <= 0.5) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    }
                } else {
                    classes[0] = 2; 
                    classes[1] = 0; 
                }
            }
        } else {
            if (features[17] <= 60208.0) {
                classes[0] = 10; 
                classes[1] = 0; 
            } else {
                if (features[6] <= 0.5) {
                    classes[0] = 0; 
                    classes[1] = 3; 
                } else {
                    classes[0] = 1; 
                    classes[1] = 0; 
                }
            }
        }
    } else {
        if (features[2] <= 0.8709589242935181) {
            if (features[22] <= 13472.0) {
                if (features[6] <= 0.5) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                } else {
                    classes[0] = 4; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 52; 
                classes[1] = 0; 
            }
        } else {
            if (features[6] <= 0.5) {
                if (features[0] <= 31.93603801727295) {
                    if (features[25] <= 1012141.34375) {
                        if (features[13] <= 2024577.8125) {
                            classes[0] = 0; 
                            classes[1] = 11; 
                        } else {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        }
                    } else {
                        classes[0] = 0; 
                        classes[1] = 19; 
                    }
                } else {
                    if (features[1] <= 256.0) {
                        classes[0] = 7; 
                        classes[1] = 0; 
                    } else {
                        if (features[25] <= 890590.0) {
                            classes[0] = 0; 
                            classes[1] = 2; 
                        } else {
                            classes[0] = 2; 
                            classes[1] = 0; 
                        }
                    }
                }
            } else {
                classes[0] = 63; 
                classes[1] = 0; 
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

int predict_7_s2_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[24] <= 1.0774677991867065) {
        if (features[25] <= 905889.375) {
            if (features[0] <= 36.821590423583984) {
                classes[0] = 0; 
                classes[1] = 48; 
            } else {
                if (features[6] <= 0.5) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                } else {
                    classes[0] = 3; 
                    classes[1] = 0; 
                }
            }
        } else {
            if (features[6] <= 0.5) {
                if (features[22] <= 57305.921875) {
                    classes[0] = 0; 
                    classes[1] = 84; 
                } else {
                    if (features[5] <= 1.5) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        classes[0] = 3; 
                        classes[1] = 0; 
                    }
                }
            } else {
                classes[0] = 37; 
                classes[1] = 0; 
            }
        }
    } else {
        if (features[2] <= 10.52878475189209) {
            classes[0] = 59; 
            classes[1] = 0; 
        } else {
            if (features[8] <= 3538.78662109375) {
                if (features[6] <= 0.5) {
                    if (features[24] <= 6.092178821563721) {
                        classes[0] = 0; 
                        classes[1] = 5; 
                    } else {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    }
                } else {
                    classes[0] = 41; 
                    classes[1] = 0; 
                }
            } else {
                if (features[23] <= 43260.728515625) {
                    classes[0] = 0; 
                    classes[1] = 9; 
                } else {
                    classes[0] = 2; 
                    classes[1] = 0; 
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

int predict_8_s2_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[15] <= 445.280029296875) {
        if (features[12] <= 0.24256490170955658) {
            if (features[22] <= 10192.0) {
                if (features[7] <= 1.0) {
                    classes[0] = 2; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 2; 
                }
            } else {
                classes[0] = 7; 
                classes[1] = 0; 
            }
        } else {
            if (features[6] <= 0.5) {
                classes[0] = 0; 
                classes[1] = 119; 
            } else {
                classes[0] = 11; 
                classes[1] = 0; 
            }
        }
    } else {
        if (features[6] <= 0.5) {
            if (features[5] <= 1.527217447757721) {
                classes[0] = 0; 
                classes[1] = 25; 
            } else {
                classes[0] = 11; 
                classes[1] = 0; 
            }
        } else {
            classes[0] = 117; 
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

int predict_9_s2_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[8] <= 12270.38525390625) {
        if (features[5] <= 1.527217447757721) {
            if (features[6] <= 0.5) {
                if (features[0] <= 33.7191104888916) {
                    if (features[24] <= 6.092178821563721) {
                        classes[0] = 0; 
                        classes[1] = 28; 
                    } else {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    }
                } else {
                    classes[0] = 2; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 38; 
                classes[1] = 0; 
            }
        } else {
            classes[0] = 94; 
            classes[1] = 0; 
        }
    } else {
        if (features[6] <= 0.5) {
            if (features[8] <= 28859.9921875) {
                if (features[0] <= 36.945180892944336) {
                    classes[0] = 0; 
                    classes[1] = 109; 
                } else {
                    if (features[14] <= 14282.07177734375) {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 2; 
                    }
                }
            } else {
                if (features[0] <= 24.5) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                } else {
                    classes[0] = 2; 
                    classes[1] = 0; 
                }
            }
        } else {
            classes[0] = 15; 
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

int predict_s2_VERT_SPLIT (float features[]) {
    int n_classes = 2;
    int classes[n_classes];
    int i;
    for (i = 0; i < n_classes; i++) {
        classes[i] = 0;
    }

    classes[predict_0_s2_VERT_SPLIT(features)]++;
    classes[predict_1_s2_VERT_SPLIT(features)]++;
    classes[predict_2_s2_VERT_SPLIT(features)]++;
    classes[predict_3_s2_VERT_SPLIT(features)]++;
    classes[predict_4_s2_VERT_SPLIT(features)]++;
    classes[predict_5_s2_VERT_SPLIT(features)]++;
    classes[predict_6_s2_VERT_SPLIT(features)]++;
    classes[predict_7_s2_VERT_SPLIT(features)]++;
    classes[predict_8_s2_VERT_SPLIT(features)]++;
    classes[predict_9_s2_VERT_SPLIT(features)]++;

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
