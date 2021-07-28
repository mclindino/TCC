#include "s2_HORZ_SPLIT.h"
int predict_0_s2_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[20] <= 40691.197265625) {
        if (features[21] <= 485.513671875) {
            if (features[14] <= 25996.421875) {
                classes[0] = 83; 
                classes[1] = 0; 
            } else {
                if (features[20] <= 14810.03857421875) {
                    classes[0] = 2; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 1; 
                }
            }
        } else {
            if (features[11] <= 54128.0) {
                if (features[19] <= 1043018.0) {
                    if (features[0] <= 29.5) {
                        classes[0] = 0; 
                        classes[1] = 2; 
                    } else {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    }
                } else {
                    if (features[18] <= 16.791666984558105) {
                        if (features[10] <= 52576.0) {
                            classes[0] = 37; 
                            classes[1] = 0; 
                        } else {
                            if (features[16] <= 61744.0) {
                                if (features[0] <= 32.0) {
                                    classes[0] = 0; 
                                    classes[1] = 1; 
                                } else {
                                    classes[0] = 2; 
                                    classes[1] = 0; 
                                }
                            } else {
                                classes[0] = 4; 
                                classes[1] = 0; 
                            }
                        }
                    } else {
                        if (features[0] <= 24.5) {
                            classes[0] = 3; 
                            classes[1] = 0; 
                        } else {
                            if (features[0] <= 29.5) {
                                classes[0] = 0; 
                                classes[1] = 1; 
                            } else {
                                classes[0] = 1; 
                                classes[1] = 0; 
                            }
                        }
                    }
                }
            } else {
                classes[0] = 0; 
                classes[1] = 1; 
            }
        }
    } else {
        if (features[6] <= 0.5) {
            classes[0] = 0; 
            classes[1] = 2; 
        } else {
            classes[0] = 3; 
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

int predict_1_s2_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[22] <= 63792.0) {
        if (features[16] <= 63792.0) {
            if (features[11] <= 8176.0) {
                if (features[12] <= 7.574531555175781) {
                    if (features[0] <= 29.5) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    }
                } else {
                    classes[0] = 23; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 110; 
                classes[1] = 0; 
            }
        } else {
            if (features[0] <= 32.0) {
                classes[0] = 0; 
                classes[1] = 1; 
            } else {
                classes[0] = 2; 
                classes[1] = 0; 
            }
        }
    } else {
        if (features[22] <= 64320.0) {
            if (features[0] <= 34.5) {
                classes[0] = 0; 
                classes[1] = 3; 
            } else {
                classes[0] = 1; 
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

int predict_2_s2_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[22] <= 63792.0) {
        if (features[16] <= 63792.0) {
            if (features[13] <= 2141094.0) {
                if (features[15] <= 542.15234375) {
                    if (features[13] <= 2045984.0) {
                        classes[0] = 75; 
                        classes[1] = 0; 
                    } else {
                        if (features[8] <= 3295.6343994140625) {
                            if (features[0] <= 29.5) {
                                classes[0] = 0; 
                                classes[1] = 1; 
                            } else {
                                classes[0] = 4; 
                                classes[1] = 0; 
                            }
                        } else {
                            classes[0] = 12; 
                            classes[1] = 0; 
                        }
                    }
                } else {
                    if (features[6] <= 0.5) {
                        if (features[0] <= 34.5) {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        } else {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        }
                    } else {
                        classes[0] = 5; 
                        classes[1] = 0; 
                    }
                }
            } else {
                if (features[20] <= 1134.1954956054688) {
                    if (features[13] <= 2236810.0) {
                        classes[0] = 0; 
                        classes[1] = 5; 
                    } else {
                        classes[0] = 10; 
                        classes[1] = 0; 
                    }
                } else {
                    classes[0] = 22; 
                    classes[1] = 0; 
                }
            }
        } else {
            if (features[0] <= 29.5) {
                classes[0] = 0; 
                classes[1] = 3; 
            } else {
                classes[0] = 2; 
                classes[1] = 0; 
            }
        }
    } else {
        if (features[18] <= 0.26989966817200184) {
            classes[0] = 0; 
            classes[1] = 3; 
        } else {
            classes[0] = 1; 
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

int predict_3_s2_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[9] <= 547.373046875) {
        classes[0] = 135; 
        classes[1] = 0; 
    } else {
        if (features[23] <= 61616.0) {
            classes[0] = 6; 
            classes[1] = 0; 
        } else {
            if (features[0] <= 24.5) {
                classes[0] = 2; 
                classes[1] = 0; 
            } else {
                if (features[0] <= 29.5) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                } else {
                    classes[0] = 1; 
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

int predict_4_s2_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[12] <= 0.1755448877811432) {
        if (features[14] <= 18213.7900390625) {
            if (features[16] <= 60896.0) {
                classes[0] = 5; 
                classes[1] = 0; 
            } else {
                if (features[0] <= 34.5) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                } else {
                    classes[0] = 1; 
                    classes[1] = 0; 
                }
            }
        } else {
            classes[0] = 0; 
            classes[1] = 1; 
        }
    } else {
        if (features[11] <= 54128.0) {
            if (features[10] <= 54160.0) {
                classes[0] = 94; 
                classes[1] = 0; 
            } else {
                if (features[11] <= 7712.0) {
                    classes[0] = 13; 
                    classes[1] = 0; 
                } else {
                    if (features[16] <= 61520.0) {
                        classes[0] = 10; 
                        classes[1] = 0; 
                    } else {
                        if (features[0] <= 29.5) {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        } else {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        }
                    }
                }
            }
        } else {
            if (features[9] <= 514.55908203125) {
                classes[0] = 12; 
                classes[1] = 0; 
            } else {
                if (features[0] <= 24.5) {
                    classes[0] = 2; 
                    classes[1] = 0; 
                } else {
                    if (features[0] <= 29.5) {
                        classes[0] = 0; 
                        classes[1] = 2; 
                    } else {
                        classes[0] = 2; 
                        classes[1] = 0; 
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

int predict_5_s2_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[9] <= 499.5078125) {
        if (features[12] <= 0.1755448877811432) {
            if (features[7] <= 1.0) {
                classes[0] = 8; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 3; 
            }
        } else {
            classes[0] = 88; 
            classes[1] = 0; 
        }
    } else {
        if (features[19] <= 1122152.0) {
            if (features[8] <= 3295.6343994140625) {
                if (features[17] <= 13216.0) {
                    if (features[0] <= 24.5) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        if (features[0] <= 29.5) {
                            classes[0] = 0; 
                            classes[1] = 3; 
                        } else {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        }
                    }
                } else {
                    if (features[0] <= 24.5) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 2; 
                    }
                }
            } else {
                if (features[14] <= 2217.3221435546875) {
                    if (features[0] <= 29.5) {
                        classes[0] = 0; 
                        classes[1] = 2; 
                    } else {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    }
                } else {
                    classes[0] = 8; 
                    classes[1] = 0; 
                }
            }
        } else {
            classes[0] = 26; 
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

int predict_6_s2_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[20] <= 40691.197265625) {
        if (features[18] <= 0.1394029352813959) {
            if (features[7] <= 1.0) {
                classes[0] = 6; 
                classes[1] = 0; 
            } else {
                if (features[0] <= 34.5) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                } else {
                    classes[0] = 1; 
                    classes[1] = 0; 
                }
            }
        } else {
            if (features[25] <= 994332.0) {
                classes[0] = 82; 
                classes[1] = 0; 
            } else {
                if (features[14] <= 3043.6112060546875) {
                    classes[0] = 42; 
                    classes[1] = 0; 
                } else {
                    if (features[19] <= 1052076.0) {
                        classes[0] = 0; 
                        classes[1] = 2; 
                    } else {
                        classes[0] = 3; 
                        classes[1] = 0; 
                    }
                }
            }
        }
    } else {
        if (features[22] <= 9824.0) {
            if (features[7] <= 1.0) {
                classes[0] = 1; 
                classes[1] = 0; 
            } else {
                if (features[0] <= 34.5) {
                    classes[0] = 0; 
                    classes[1] = 2; 
                } else {
                    classes[0] = 1; 
                    classes[1] = 0; 
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

int predict_7_s2_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[18] <= 16.791666984558105) {
        if (features[8] <= 18111.87744140625) {
            if (features[22] <= 62064.0) {
                if (features[8] <= 1304.439208984375) {
                    if (features[10] <= 45376.0) {
                        if (features[0] <= 29.5) {
                            if (features[0] <= 24.5) {
                                classes[0] = 2; 
                                classes[1] = 0; 
                            } else {
                                classes[0] = 0; 
                                classes[1] = 1; 
                            }
                        } else {
                            classes[0] = 4; 
                            classes[1] = 0; 
                        }
                    } else {
                        classes[0] = 18; 
                        classes[1] = 0; 
                    }
                } else {
                    classes[0] = 59; 
                    classes[1] = 0; 
                }
            } else {
                if (features[18] <= 2.6929798126220703) {
                    if (features[12] <= 3.8258575201034546) {
                        classes[0] = 3; 
                        classes[1] = 0; 
                    } else {
                        if (features[0] <= 29.5) {
                            classes[0] = 0; 
                            classes[1] = 2; 
                        } else {
                            classes[0] = 2; 
                            classes[1] = 0; 
                        }
                    }
                } else {
                    classes[0] = 12; 
                    classes[1] = 0; 
                }
            }
        } else {
            if (features[7] <= 1.0) {
                classes[0] = 12; 
                classes[1] = 0; 
            } else {
                if (features[10] <= 16592.0) {
                    if (features[24] <= 0.9267589598894119) {
                        if (features[0] <= 34.5) {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        } else {
                            classes[0] = 2; 
                            classes[1] = 0; 
                        }
                    } else {
                        if (features[0] <= 34.5) {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        } else {
                            classes[0] = 2; 
                            classes[1] = 0; 
                        }
                    }
                } else {
                    classes[0] = 1; 
                    classes[1] = 0; 
                }
            }
        }
    } else {
        if (features[17] <= 2352.0) {
            if (features[22] <= 25440.0) {
                if (features[0] <= 29.5) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                } else {
                    classes[0] = 3; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 14; 
                classes[1] = 0; 
            }
        } else {
            if (features[0] <= 24.5) {
                classes[0] = 1; 
                classes[1] = 0; 
            } else {
                if (features[0] <= 29.5) {
                    classes[0] = 0; 
                    classes[1] = 3; 
                } else {
                    classes[0] = 1; 
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

int predict_8_s2_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[12] <= 0.09068823046982288) {
        if (features[11] <= 40464.0) {
            classes[0] = 5; 
            classes[1] = 0; 
        } else {
            if (features[0] <= 34.5) {
                classes[0] = 0; 
                classes[1] = 2; 
            } else {
                classes[0] = 2; 
                classes[1] = 0; 
            }
        }
    } else {
        if (features[18] <= 45.931020736694336) {
            if (features[21] <= 543.3662109375) {
                classes[0] = 112; 
                classes[1] = 0; 
            } else {
                if (features[5] <= 1.5) {
                    if (features[0] <= 24.5) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    }
                } else {
                    classes[0] = 12; 
                    classes[1] = 0; 
                }
            }
        } else {
            if (features[18] <= 59.98684310913086) {
                if (features[0] <= 32.0) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                } else {
                    classes[0] = 2; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 7; 
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

int predict_9_s2_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[18] <= 16.791666984558105) {
        if (features[12] <= 0.1755448877811432) {
            if (features[6] <= 0.5) {
                if (features[18] <= 0.5259569901973009) {
                    if (features[0] <= 34.5) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    }
                } else {
                    if (features[0] <= 34.5) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    }
                }
            } else {
                classes[0] = 12; 
                classes[1] = 0; 
            }
        } else {
            if (features[5] <= 1.5) {
                if (features[2] <= 32.0) {
                    if (features[11] <= 8368.0) {
                        if (features[0] <= 24.5) {
                            classes[0] = 2; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        }
                    } else {
                        classes[0] = 11; 
                        classes[1] = 0; 
                    }
                } else {
                    classes[0] = 19; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 80; 
                classes[1] = 0; 
            }
        }
    } else {
        if (features[15] <= 500.2548828125) {
            classes[0] = 9; 
            classes[1] = 0; 
        } else {
            if (features[24] <= 21.628709197044373) {
                if (features[0] <= 24.5) {
                    classes[0] = 2; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 2; 
                }
            } else {
                if (features[0] <= 32.0) {
                    classes[0] = 0; 
                    classes[1] = 1; 
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

int predict_s2_HORZ_SPLIT (float features[]) {
    int n_classes = 2;
    int classes[n_classes];
    int i;
    for (i = 0; i < n_classes; i++) {
        classes[i] = 0;
    }

    classes[predict_0_s2_HORZ_SPLIT(features)]++;
    classes[predict_1_s2_HORZ_SPLIT(features)]++;
    classes[predict_2_s2_HORZ_SPLIT(features)]++;
    classes[predict_3_s2_HORZ_SPLIT(features)]++;
    classes[predict_4_s2_HORZ_SPLIT(features)]++;
    classes[predict_5_s2_HORZ_SPLIT(features)]++;
    classes[predict_6_s2_HORZ_SPLIT(features)]++;
    classes[predict_7_s2_HORZ_SPLIT(features)]++;
    classes[predict_8_s2_HORZ_SPLIT(features)]++;
    classes[predict_9_s2_HORZ_SPLIT(features)]++;

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
