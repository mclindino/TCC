#include "s0_HORZ_SPLIT.h"
int predict_0_s0_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[8] <= 2.9022289514541626) {
        if (features[2] <= 319.0) {
            if (features[5] <= 523.73193359375) {
                if (features[7] <= 50240.0) {
                    classes[0] = 0; 
                    classes[1] = 5; 
                } else {
                    classes[0] = 2; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 6; 
                classes[1] = 0; 
            }
        } else {
            classes[0] = 13; 
            classes[1] = 0; 
        }
    } else {
        classes[0] = 0; 
        classes[1] = 5; 
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

int predict_1_s0_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[19] <= 51200.0) {
        if (features[15] <= 3826412.0) {
            classes[0] = 2; 
            classes[1] = 0; 
        } else {
            if (features[0] <= 34.5) {
                classes[0] = 0; 
                classes[1] = 5; 
            } else {
                if (features[1] <= 64.0) {
                    if (features[4] <= 20293.8037109375) {
                        classes[0] = 0; 
                        classes[1] = 3; 
                    } else {
                        if (features[20] <= 1.2351520657539368) {
                            classes[0] = 0; 
                            classes[1] = 1; 
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
        }
    } else {
        if (features[3] <= 14.0) {
            classes[0] = 13; 
            classes[1] = 0; 
        } else {
            classes[0] = 0; 
            classes[1] = 2; 
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

int predict_2_s0_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[18] <= 32496.0) {
        classes[0] = 7; 
        classes[1] = 0; 
    } else {
        if (features[15] <= 4183850.0) {
            if (features[21] <= 3535300.0) {
                classes[0] = 0; 
                classes[1] = 1; 
            } else {
                if (features[17] <= 452.095458984375) {
                    classes[0] = 4; 
                    classes[1] = 0; 
                } else {
                    if (features[0] <= 34.5) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        classes[0] = 4; 
                        classes[1] = 0; 
                    }
                }
            }
        } else {
            if (features[18] <= 39424.0) {
                classes[0] = 0; 
                classes[1] = 10; 
            } else {
                if (features[0] <= 34.5) {
                    if (features[3] <= 8.0) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    }
                } else {
                    classes[0] = 0; 
                    classes[1] = 2; 
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

int predict_3_s0_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[12] <= 12800.0) {
        classes[0] = 0; 
        classes[1] = 9; 
    } else {
        if (features[9] <= 8580824.0) {
            if (features[13] <= 61136.0) {
                classes[0] = 6; 
                classes[1] = 0; 
            } else {
                if (features[7] <= 49824.0) {
                    if (features[0] <= 29.5) {
                        classes[0] = 0; 
                        classes[1] = 3; 
                    } else {
                        if (features[0] <= 34.5) {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 3; 
                        }
                    }
                } else {
                    classes[0] = 0; 
                    classes[1] = 1; 
                }
            }
        } else {
            classes[0] = 8; 
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

int predict_4_s0_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[3] <= 6.0) {
        classes[0] = 17; 
        classes[1] = 0; 
    } else {
        if (features[5] <= 460.0064697265625) {
            classes[0] = 2; 
            classes[1] = 0; 
        } else {
            if (features[16] <= 2970.810546875) {
                if (features[21] <= 4268184.0) {
                    classes[0] = 1; 
                    classes[1] = 0; 
                } else {
                    if (features[19] <= 50928.0) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        if (features[0] <= 34.5) {
                            if (features[0] <= 29.5) {
                                classes[0] = 0; 
                                classes[1] = 1; 
                            } else {
                                classes[0] = 1; 
                                classes[1] = 0; 
                            }
                        } else {
                            classes[0] = 0; 
                            classes[1] = 2; 
                        }
                    }
                }
            } else {
                classes[0] = 0; 
                classes[1] = 6; 
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

int predict_5_s0_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[5] <= 459.9825439453125) {
        classes[0] = 9; 
        classes[1] = 0; 
    } else {
        if (features[21] <= 4275544.0) {
            if (features[13] <= 61568.0) {
                classes[0] = 0; 
                classes[1] = 15; 
            } else {
                if (features[8] <= 4.14469051361084) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                } else {
                    classes[0] = 2; 
                    classes[1] = 0; 
                }
            }
        } else {
            if (features[20] <= 0.8152613043785095) {
                classes[0] = 3; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 1; 
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

int predict_6_s0_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[12] <= 12928.0) {
        classes[0] = 0; 
        classes[1] = 6; 
    } else {
        if (features[11] <= 524.885498046875) {
            if (features[4] <= 12521.81494140625) {
                classes[0] = 13; 
                classes[1] = 0; 
            } else {
                if (features[5] <= 459.9825439453125) {
                    classes[0] = 4; 
                    classes[1] = 0; 
                } else {
                    if (features[0] <= 34.5) {
                        classes[0] = 0; 
                        classes[1] = 2; 
                    } else {
                        classes[0] = 3; 
                        classes[1] = 0; 
                    }
                }
            }
        } else {
            classes[0] = 0; 
            classes[1] = 3; 
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

int predict_7_s0_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[10] <= 14647.05517578125) {
        if (features[3] <= 8.0) {
            classes[0] = 15; 
            classes[1] = 0; 
        } else {
            if (features[6] <= 7888.0) {
                classes[0] = 0; 
                classes[1] = 3; 
            } else {
                if (features[12] <= 32464.0) {
                    classes[0] = 2; 
                    classes[1] = 0; 
                } else {
                    if (features[0] <= 34.5) {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 3; 
                    }
                }
            }
        }
    } else {
        classes[0] = 0; 
        classes[1] = 6; 
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

int predict_8_s0_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[5] <= 460.0064697265625) {
        classes[0] = 12; 
        classes[1] = 0; 
    } else {
        if (features[3] <= 8.0) {
            if (features[9] <= 8589546.0) {
                classes[0] = 5; 
                classes[1] = 0; 
            } else {
                if (features[0] <= 34.5) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                } else {
                    classes[0] = 3; 
                    classes[1] = 0; 
                }
            }
        } else {
            if (features[17] <= 486.846435546875) {
                classes[0] = 0; 
                classes[1] = 4; 
            } else {
                if (features[11] <= 524.78857421875) {
                    classes[0] = 1; 
                    classes[1] = 0; 
                } else {
                    if (features[0] <= 29.5) {
                        classes[0] = 0; 
                        classes[1] = 2; 
                    } else {
                        if (features[21] <= 4275824.0) {
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

int predict_9_s0_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[6] <= 33952.0) {
        if (features[8] <= 0.262312613427639) {
            if (features[21] <= 4281860.0) {
                classes[0] = 0; 
                classes[1] = 4; 
            } else {
                classes[0] = 4; 
                classes[1] = 0; 
            }
        } else {
            classes[0] = 12; 
            classes[1] = 0; 
        }
    } else {
        classes[0] = 0; 
        classes[1] = 11; 
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

int predict_s0_HORZ_SPLIT (float features[]) {
    int n_classes = 2;
    int classes[n_classes];
    int i;
    for (i = 0; i < n_classes; i++) {
        classes[i] = 0;
    }

    classes[predict_0_s0_HORZ_SPLIT(features)]++;
    classes[predict_1_s0_HORZ_SPLIT(features)]++;
    classes[predict_2_s0_HORZ_SPLIT(features)]++;
    classes[predict_3_s0_HORZ_SPLIT(features)]++;
    classes[predict_4_s0_HORZ_SPLIT(features)]++;
    classes[predict_5_s0_HORZ_SPLIT(features)]++;
    classes[predict_6_s0_HORZ_SPLIT(features)]++;
    classes[predict_7_s0_HORZ_SPLIT(features)]++;
    classes[predict_8_s0_HORZ_SPLIT(features)]++;
    classes[predict_9_s0_HORZ_SPLIT(features)]++;

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
