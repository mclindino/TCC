#include "s0_VERT_SPLIT.h"
int predict_0_s0_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[3] <= 8.0) {
        if (features[2] <= 191.0) {
            if (features[11] <= 469.075439453125) {
                classes[0] = 2; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 1; 
            }
        } else {
            classes[0] = 19; 
            classes[1] = 0; 
        }
    } else {
        if (features[18] <= 54640.0) {
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

int predict_1_s0_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[9] <= 7536354.0) {
        classes[0] = 10; 
        classes[1] = 0; 
    } else {
        if (features[0] <= 34.5) {
            if (features[13] <= 39152.0) {
                classes[0] = 0; 
                classes[1] = 6; 
            } else {
                classes[0] = 3; 
                classes[1] = 0; 
            }
        } else {
            if (features[9] <= 8576878.0) {
                if (features[3] <= 10.0) {
                    if (features[16] <= 25340.451171875) {
                        classes[0] = 3; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    }
                } else {
                    classes[0] = 0; 
                    classes[1] = 2; 
                }
            } else {
                classes[0] = 5; 
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

int predict_2_s0_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[17] <= 456.7509765625) {
        if (features[15] <= 3813916.0) {
            classes[0] = 8; 
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
    } else {
        if (features[4] <= 2945.176025390625) {
            if (features[11] <= 546.90673828125) {
                classes[0] = 3; 
                classes[1] = 0; 
            } else {
                if (features[14] <= 0.6544312238693237) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                } else {
                    if (features[0] <= 34.5) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 2; 
                    }
                }
            }
        } else {
            classes[0] = 0; 
            classes[1] = 10; 
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

int predict_3_s0_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[20] <= 1.8128701448440552) {
        if (features[9] <= 8580824.0) {
            if (features[5] <= 523.4183349609375) {
                classes[0] = 0; 
                classes[1] = 9; 
            } else {
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
            }
        } else {
            classes[0] = 2; 
            classes[1] = 0; 
        }
    } else {
        classes[0] = 12; 
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

int predict_4_s0_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[3] <= 6.0) {
        classes[0] = 16; 
        classes[1] = 0; 
    } else {
        if (features[5] <= 459.9825439453125) {
            classes[0] = 2; 
            classes[1] = 0; 
        } else {
            if (features[16] <= 3577.4471435546875) {
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
            } else {
                classes[0] = 0; 
                classes[1] = 8; 
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

int predict_5_s0_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[12] <= 20064.0) {
        classes[0] = 0; 
        classes[1] = 6; 
    } else {
        if (features[18] <= 31328.0) {
            if (features[7] <= 50048.0) {
                classes[0] = 0; 
                classes[1] = 6; 
            } else {
                classes[0] = 6; 
                classes[1] = 0; 
            }
        } else {
            classes[0] = 12; 
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

int predict_6_s0_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[19] <= 24832.0) {
        if (features[11] <= 547.15087890625) {
            if (features[3] <= 8.0) {
                classes[0] = 10; 
                classes[1] = 0; 
            } else {
                if (features[5] <= 459.9825439453125) {
                    classes[0] = 2; 
                    classes[1] = 0; 
                } else {
                    if (features[0] <= 34.5) {
                        if (features[2] <= 319.0) {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 2; 
                        }
                    } else {
                        classes[0] = 4; 
                        classes[1] = 0; 
                    }
                }
            }
        } else {
            classes[0] = 0; 
            classes[1] = 3; 
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

int predict_7_s0_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[6] <= 45456.0) {
        if (features[3] <= 8.0) {
            classes[0] = 15; 
            classes[1] = 0; 
        } else {
            if (features[14] <= 20.96475887298584) {
                if (features[20] <= 1.0221377611160278) {
                    classes[0] = 0; 
                    classes[1] = 2; 
                } else {
                    if (features[20] <= 1.857641339302063) {
                        if (features[0] <= 34.5) {
                            classes[0] = 2; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 3; 
                        }
                    } else {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    }
                }
            } else {
                classes[0] = 1; 
                classes[1] = 0; 
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

int predict_8_s0_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[16] <= 6236.047607421875) {
        if (features[6] <= 62992.0) {
            if (features[14] <= 0.6670726239681244) {
                if (features[13] <= 39184.0) {
                    classes[0] = 1; 
                    classes[1] = 0; 
                } else {
                    if (features[0] <= 29.5) {
                        classes[0] = 0; 
                        classes[1] = 2; 
                    } else {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    }
                }
            } else {
                if (features[9] <= 8589546.0) {
                    classes[0] = 11; 
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
        } else {
            classes[0] = 0; 
            classes[1] = 2; 
        }
    } else {
        if (features[4] <= 20420.0966796875) {
            classes[0] = 0; 
            classes[1] = 6; 
        } else {
            if (features[13] <= 51024.0) {
                classes[0] = 0; 
                classes[1] = 2; 
            } else {
                classes[0] = 1; 
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

int predict_9_s0_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[14] <= 0.6542958319187164) {
        classes[0] = 0; 
        classes[1] = 5; 
    } else {
        if (features[5] <= 459.725830078125) {
            classes[0] = 15; 
            classes[1] = 0; 
        } else {
            if (features[7] <= 49984.0) {
                if (features[12] <= 26128.0) {
                    classes[0] = 1; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 5; 
                }
            } else {
                classes[0] = 4; 
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

int predict_s0_VERT_SPLIT (float features[]) {
    int n_classes = 2;
    int classes[n_classes];
    int i;
    for (i = 0; i < n_classes; i++) {
        classes[i] = 0;
    }

    classes[predict_0_s0_VERT_SPLIT(features)]++;
    classes[predict_1_s0_VERT_SPLIT(features)]++;
    classes[predict_2_s0_VERT_SPLIT(features)]++;
    classes[predict_3_s0_VERT_SPLIT(features)]++;
    classes[predict_4_s0_VERT_SPLIT(features)]++;
    classes[predict_5_s0_VERT_SPLIT(features)]++;
    classes[predict_6_s0_VERT_SPLIT(features)]++;
    classes[predict_7_s0_VERT_SPLIT(features)]++;
    classes[predict_8_s0_VERT_SPLIT(features)]++;
    classes[predict_9_s0_VERT_SPLIT(features)]++;

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
