#include "s2_VERT_SPLIT.h"
int predict_0_s2_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[20] <= 13755.697265625) {
        if (features[21] <= 571.076171875) {
            if (features[14] <= 370.6018524169922) {
                if (features[21] <= 434.607421875) {
                    if (features[7] <= 1.0) {
                        classes[0] = 4; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 3; 
                    }
                } else {
                    classes[0] = 7; 
                    classes[1] = 0; 
                }
            } else {
                if (features[7] <= 1.0) {
                    classes[0] = 111; 
                    classes[1] = 0; 
                } else {
                    if (features[20] <= 6886.075927734375) {
                        if (features[24] <= 0.507135609164834) {
                            if (features[13] <= 2054010.0) {
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
                    } else {
                        if (features[9] <= 464.63427734375) {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        }
                    }
                }
            }
        } else {
            if (features[7] <= 1.0) {
                classes[0] = 1; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 1; 
            }
        }
    } else {
        if (features[1] <= 32.0) {
            if (features[0] <= 29.5) {
                classes[0] = 0; 
                classes[1] = 4; 
            } else {
                if (features[8] <= 14462.36865234375) {
                    if (features[7] <= 1.0) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    }
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

int predict_1_s2_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[7] <= 1.0) {
        classes[0] = 132; 
        classes[1] = 0; 
    } else {
        if (features[24] <= 1.4471235871315002) {
            if (features[19] <= 1134600.0) {
                classes[0] = 0; 
                classes[1] = 15; 
            } else {
                classes[0] = 2; 
                classes[1] = 0; 
            }
        } else {
            if (features[23] <= 2816.0) {
                classes[0] = 0; 
                classes[1] = 1; 
            } else {
                classes[0] = 8; 
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
    
    if (features[15] <= 429.1328125) {
        if (features[6] <= 0.5) {
            classes[0] = 0; 
            classes[1] = 18; 
        } else {
            classes[0] = 19; 
            classes[1] = 0; 
        }
    } else {
        if (features[10] <= 15904.0) {
            if (features[21] <= 434.607421875) {
                if (features[7] <= 1.0) {
                    classes[0] = 2; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 2; 
                }
            } else {
                if (features[15] <= 547.2802734375) {
                    classes[0] = 21; 
                    classes[1] = 0; 
                } else {
                    if (features[13] <= 2229390.0) {
                        if (features[0] <= 32.0) {
                            if (features[7] <= 1.0) {
                                classes[0] = 1; 
                                classes[1] = 0; 
                            } else {
                                classes[0] = 0; 
                                classes[1] = 1; 
                            }
                        } else {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        }
                    } else {
                        classes[0] = 6; 
                        classes[1] = 0; 
                    }
                }
            }
        } else {
            classes[0] = 87; 
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

int predict_3_s2_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[8] <= 14462.36865234375) {
        if (features[17] <= 59936.0) {
            if (features[6] <= 0.5) {
                if (features[10] <= 7872.0) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                } else {
                    if (features[15] <= 547.3466796875) {
                        classes[0] = 0; 
                        classes[1] = 2; 
                    } else {
                        classes[0] = 9; 
                        classes[1] = 0; 
                    }
                }
            } else {
                classes[0] = 83; 
                classes[1] = 0; 
            }
        } else {
            if (features[6] <= 0.5) {
                if (features[25] <= 890590.0) {
                    classes[0] = 0; 
                    classes[1] = 6; 
                } else {
                    classes[0] = 2; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 26; 
                classes[1] = 0; 
            }
        }
    } else {
        if (features[3] <= 95.0) {
            classes[0] = 0; 
            classes[1] = 6; 
        } else {
            if (features[7] <= 1.0) {
                classes[0] = 14; 
                classes[1] = 0; 
            } else {
                if (features[2] <= 32.0) {
                    if (features[17] <= 7904.0) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    }
                } else {
                    classes[0] = 0; 
                    classes[1] = 7; 
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
    
    if (features[20] <= 13755.697265625) {
        if (features[14] <= 370.6018524169922) {
            if (features[17] <= 60448.0) {
                if (features[7] <= 1.0) {
                    classes[0] = 4; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 3; 
                }
            } else {
                classes[0] = 7; 
                classes[1] = 0; 
            }
        } else {
            if (features[3] <= 159.0) {
                if (features[6] <= 0.5) {
                    if (features[19] <= 1121060.0) {
                        if (features[19] <= 731336.0) {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 4; 
                        }
                    } else {
                        classes[0] = 6; 
                        classes[1] = 0; 
                    }
                } else {
                    classes[0] = 24; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 98; 
                classes[1] = 0; 
            }
        }
    } else {
        if (features[6] <= 0.5) {
            classes[0] = 0; 
            classes[1] = 8; 
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

int predict_5_s2_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[25] <= 832038.0) {
        if (features[22] <= 19856.0) {
            if (features[7] <= 1.0) {
                classes[0] = 1; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 3; 
            }
        } else {
            if (features[0] <= 32.0) {
                classes[0] = 0; 
                classes[1] = 2; 
            } else {
                if (features[6] <= 0.5) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                } else {
                    classes[0] = 1; 
                    classes[1] = 0; 
                }
            }
        }
    } else {
        if (features[6] <= 0.5) {
            if (features[15] <= 547.392578125) {
                if (features[0] <= 29.5) {
                    classes[0] = 0; 
                    classes[1] = 9; 
                } else {
                    if (features[4] <= 95.0) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        if (features[14] <= 311.52113342285156) {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 6; 
                        }
                    }
                }
            } else {
                classes[0] = 6; 
                classes[1] = 0; 
            }
        } else {
            classes[0] = 127; 
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
    
    if (features[20] <= 5847.191650390625) {
        if (features[19] <= 777598.0) {
            if (features[8] <= 21179.857421875) {
                classes[0] = 1; 
                classes[1] = 0; 
            } else {
                if (features[0] <= 32.0) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                } else {
                    if (features[7] <= 1.0) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    }
                }
            }
        } else {
            if (features[12] <= 24.098684310913086) {
                if (features[25] <= 1112080.0) {
                    classes[0] = 75; 
                    classes[1] = 0; 
                } else {
                    if (features[6] <= 0.5) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        classes[0] = 12; 
                        classes[1] = 0; 
                    }
                }
            } else {
                if (features[7] <= 1.0) {
                    classes[0] = 8; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 3; 
                }
            }
        }
    } else {
        if (features[7] <= 1.0) {
            classes[0] = 40; 
            classes[1] = 0; 
        } else {
            if (features[24] <= 3.2313246726989746) {
                classes[0] = 0; 
                classes[1] = 10; 
            } else {
                if (features[14] <= 3301.7789306640625) {
                    classes[0] = 0; 
                    classes[1] = 3; 
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

int predict_7_s2_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[14] <= 12892.390625) {
        if (features[8] <= 3364.6207275390625) {
            if (features[6] <= 0.5) {
                if (features[11] <= 4080.0) {
                    if (features[16] <= 58400.0) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    }
                } else {
                    classes[0] = 6; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 74; 
                classes[1] = 0; 
            }
        } else {
            if (features[20] <= 5847.191650390625) {
                classes[0] = 15; 
                classes[1] = 0; 
            } else {
                if (features[7] <= 1.0) {
                    classes[0] = 19; 
                    classes[1] = 0; 
                } else {
                    if (features[16] <= 12448.0) {
                        classes[0] = 0; 
                        classes[1] = 5; 
                    } else {
                        if (features[11] <= 25632.0) {
                            classes[0] = 2; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        }
                    }
                }
            }
        }
    } else {
        if (features[17] <= 53872.0) {
            if (features[19] <= 804046.0) {
                if (features[7] <= 1.0) {
                    classes[0] = 3; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 1; 
                }
            } else {
                if (features[17] <= 7904.0) {
                    if (features[7] <= 1.0) {
                        classes[0] = 7; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    }
                } else {
                    classes[0] = 6; 
                    classes[1] = 0; 
                }
            }
        } else {
            if (features[0] <= 29.5) {
                classes[0] = 0; 
                classes[1] = 7; 
            } else {
                if (features[13] <= 1638046.0) {
                    classes[0] = 3; 
                    classes[1] = 0; 
                } else {
                    if (features[10] <= 61056.0) {
                        if (features[7] <= 1.0) {
                            classes[0] = 2; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        }
                    } else {
                        if (features[6] <= 0.5) {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        } else {
                            classes[0] = 2; 
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

int predict_8_s2_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[21] <= 545.9951171875) {
        if (features[21] <= 406.2685546875) {
            if (features[6] <= 0.5) {
                classes[0] = 0; 
                classes[1] = 4; 
            } else {
                classes[0] = 4; 
                classes[1] = 0; 
            }
        } else {
            if (features[11] <= 624.0) {
                if (features[6] <= 0.5) {
                    classes[0] = 0; 
                    classes[1] = 3; 
                } else {
                    classes[0] = 7; 
                    classes[1] = 0; 
                }
            } else {
                if (features[7] <= 1.0) {
                    classes[0] = 113; 
                    classes[1] = 0; 
                } else {
                    if (features[0] <= 29.5) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        classes[0] = 9; 
                        classes[1] = 0; 
                    }
                }
            }
        }
    } else {
        if (features[6] <= 0.5) {
            if (features[17] <= 3328.0) {
                classes[0] = 2; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 7; 
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

int predict_9_s2_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[15] <= 429.1328125) {
        if (features[16] <= 11760.0) {
            if (features[6] <= 0.5) {
                classes[0] = 0; 
                classes[1] = 4; 
            } else {
                classes[0] = 2; 
                classes[1] = 0; 
            }
        } else {
            if (features[18] <= 6.352759838104248) {
                if (features[6] <= 0.5) {
                    classes[0] = 0; 
                    classes[1] = 3; 
                } else {
                    classes[0] = 17; 
                    classes[1] = 0; 
                }
            } else {
                if (features[6] <= 0.5) {
                    if (features[17] <= 2672.0) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 3; 
                    }
                } else {
                    classes[0] = 3; 
                    classes[1] = 0; 
                }
            }
        }
    } else {
        if (features[3] <= 127.0) {
            if (features[6] <= 0.5) {
                if (features[15] <= 547.392578125) {
                    classes[0] = 0; 
                    classes[1] = 3; 
                } else {
                    classes[0] = 4; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 12; 
                classes[1] = 0; 
            }
        } else {
            if (features[23] <= 6272.0) {
                if (features[6] <= 0.5) {
                    classes[0] = 0; 
                    classes[1] = 2; 
                } else {
                    classes[0] = 32; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 72; 
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
