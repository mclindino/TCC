#include "s0_QT_SPLIT.h"
int predict_0_s0_QT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[12] <= 45072.0) {
        if (features[22] <= 14389.3994140625) {
            if (features[9] <= 8220322.0) {
                classes[0] = 0; 
                classes[1] = 5; 
            } else {
                if (features[8] <= 0.732419840991497) {
                    if (features[6] <= 6048.0) {
                        classes[0] = 0; 
                        classes[1] = 2; 
                    } else {
                        if (features[0] <= 29.5) {
                            classes[0] = 0; 
                            classes[1] = 2; 
                        } else {
                            if (features[0] <= 34.5) {
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
            classes[0] = 1; 
            classes[1] = 0; 
        }
    } else {
        if (features[31] <= 3216.0) {
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

int predict_1_s0_QT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[27] <= 1564036.0) {
        classes[0] = 0; 
        classes[1] = 5; 
    } else {
        if (features[19] <= 7424.0) {
            if (features[10] <= 1308.2112426757812) {
                classes[0] = 1; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 4; 
            }
        } else {
            if (features[3] <= 1.5) {
                classes[0] = 0; 
                classes[1] = 1; 
            } else {
                if (features[26] <= 0.9826292991638184) {
                    classes[0] = 9; 
                    classes[1] = 0; 
                } else {
                    if (features[27] <= 2022856.0) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 1; 
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

int predict_2_s0_QT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[29] <= 506.5810546875) {
        if (features[25] <= 47824.0) {
            classes[0] = 0; 
            classes[1] = 3; 
        } else {
            classes[0] = 11; 
            classes[1] = 0; 
        }
    } else {
        classes[0] = 0; 
        classes[1] = 8; 
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

int predict_3_s0_QT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[4] <= 16239.15966796875) {
        classes[0] = 14; 
        classes[1] = 0; 
    } else {
        if (features[16] <= 29573.1865234375) {
            classes[0] = 0; 
            classes[1] = 6; 
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

int predict_4_s0_QT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[25] <= 47840.0) {
        if (features[32] <= 6.439984083175659) {
            classes[0] = 0; 
            classes[1] = 4; 
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
        if (features[25] <= 48128.0) {
            if (features[18] <= 58096.0) {
                if (features[0] <= 29.5) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                } else {
                    if (features[0] <= 34.5) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    }
                }
            } else {
                classes[0] = 2; 
                classes[1] = 0; 
            }
        } else {
            classes[0] = 10; 
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

int predict_5_s0_QT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[22] <= 1124.9312744140625) {
        classes[0] = 4; 
        classes[1] = 0; 
    } else {
        if (features[21] <= 2044496.0) {
            if (features[1] <= 64.0) {
                classes[0] = 0; 
                classes[1] = 1; 
            } else {
                classes[0] = 3; 
                classes[1] = 0; 
            }
        } else {
            classes[0] = 0; 
            classes[1] = 14; 
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

int predict_6_s0_QT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[31] <= 4768.0) {
        if (features[27] <= 2227560.0) {
            if (features[30] <= 27392.0) {
                classes[0] = 8; 
                classes[1] = 0; 
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
            classes[0] = 0; 
            classes[1] = 1; 
        }
    } else {
        classes[0] = 0; 
        classes[1] = 10; 
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

int predict_7_s0_QT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[12] <= 45280.0) {
        if (features[26] <= 0.3994049206376076) {
            classes[0] = 2; 
            classes[1] = 0; 
        } else {
            if (features[28] <= 6844.513671875) {
                if (features[0] <= 29.5) {
                    classes[0] = 0; 
                    classes[1] = 2; 
                } else {
                    if (features[12] <= 44816.0) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        if (features[15] <= 2254292.0) {
                            if (features[3] <= 7.0) {
                                classes[0] = 1; 
                                classes[1] = 0; 
                            } else {
                                if (features[0] <= 34.5) {
                                    classes[0] = 3; 
                                    classes[1] = 0; 
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 1; 
                                }
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
                    }
                }
            } else {
                classes[0] = 0; 
                classes[1] = 4; 
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

int predict_8_s0_QT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[25] <= 47760.0) {
        classes[0] = 0; 
        classes[1] = 3; 
    } else {
        if (features[17] <= 501.87744140625) {
            if (features[27] <= 2226844.0) {
                classes[0] = 10; 
                classes[1] = 0; 
            } else {
                if (features[12] <= 44848.0) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                } else {
                    if (features[0] <= 29.5) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        if (features[0] <= 34.5) {
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

int predict_9_s0_QT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[12] <= 39920.0) {
        classes[0] = 0; 
        classes[1] = 6; 
    } else {
        if (features[8] <= 0.262312613427639) {
            if (features[27] <= 2226254.0) {
                classes[0] = 3; 
                classes[1] = 0; 
            } else {
                if (features[0] <= 29.5) {
                    classes[0] = 0; 
                    classes[1] = 2; 
                } else {
                    if (features[0] <= 34.5) {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 2; 
                    }
                }
            }
        } else {
            classes[0] = 7; 
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

int predict_s0_QT_SPLIT (float features[]) {
    int n_classes = 2;
    int classes[n_classes];
    int i;
    for (i = 0; i < n_classes; i++) {
        classes[i] = 0;
    }

    classes[predict_0_s0_QT_SPLIT(features)]++;
    classes[predict_1_s0_QT_SPLIT(features)]++;
    classes[predict_2_s0_QT_SPLIT(features)]++;
    classes[predict_3_s0_QT_SPLIT(features)]++;
    classes[predict_4_s0_QT_SPLIT(features)]++;
    classes[predict_5_s0_QT_SPLIT(features)]++;
    classes[predict_6_s0_QT_SPLIT(features)]++;
    classes[predict_7_s0_QT_SPLIT(features)]++;
    classes[predict_8_s0_QT_SPLIT(features)]++;
    classes[predict_9_s0_QT_SPLIT(features)]++;

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
