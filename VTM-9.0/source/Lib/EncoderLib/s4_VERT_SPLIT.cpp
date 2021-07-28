#include "s4_VERT_SPLIT.h"
int predict_0_s4_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[26] <= 608.0) {
        classes[0] = 0; 
        classes[1] = 5; 
    } else {
        if (features[12] <= 293.802001953125) {
            if (features[20] <= 31456.0) {
                classes[0] = 2; 
                classes[1] = 0; 
            } else {
                if (features[19] <= 467.7929992675781) {
                    if (features[2] <= 34.5) {
                        classes[0] = 0; 
                        classes[1] = 4; 
                    } else {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    }
                } else {
                    classes[0] = 0; 
                    classes[1] = 1; 
                }
            }
        } else {
            if (features[15] <= 3952.0) {
                classes[0] = 8; 
                classes[1] = 0; 
            } else {
                if (features[23] <= 247682.0) {
                    classes[0] = 8; 
                    classes[1] = 0; 
                } else {
                    if (features[25] <= 447.8320007324219) {
                        if (features[2] <= 32.0) {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        }
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

int predict_1_s4_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[32] <= 1808.0) {
        if (features[28] <= 45.67290115356445) {
            if (features[27] <= 64336.0) {
                if (features[2] <= 29.5) {
                    if (features[17] <= 446004.0) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        classes[0] = 3; 
                        classes[1] = 0; 
                    }
                } else {
                    if (features[27] <= 29968.0) {
                        classes[0] = 0; 
                        classes[1] = 9; 
                    } else {
                        if (features[29] <= 238426.0) {
                            classes[0] = 2; 
                            classes[1] = 0; 
                        } else {
                            if (features[22] <= 0.5916934832930565) {
                                classes[0] = 0; 
                                classes[1] = 2; 
                            } else {
                                if (features[2] <= 34.5) {
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
            } else {
                classes[0] = 2; 
                classes[1] = 0; 
            }
        } else {
            classes[0] = 6; 
            classes[1] = 0; 
        }
    } else {
        classes[0] = 4; 
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

int predict_2_s4_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[34] <= 0.5146550443023443) {
        if (features[19] <= 482.1524963378906) {
            if (features[31] <= 232.031005859375) {
                if (features[6] <= 144.0) {
                    classes[0] = 10; 
                    classes[1] = 0; 
                } else {
                    if (features[26] <= 58320.0) {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    }
                }
            } else {
                classes[0] = 1; 
                classes[1] = 0; 
            }
        } else {
            if (features[27] <= 33200.0) {
                if (features[8] <= 95.0) {
                    classes[0] = 1; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 4; 
                }
            } else {
                classes[0] = 2; 
                classes[1] = 0; 
            }
        }
    } else {
        if (features[17] <= 485766.0) {
            classes[0] = 0; 
            classes[1] = 7; 
        } else {
            if (features[18] <= 416.92201232910156) {
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

int predict_3_s4_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[18] <= 426.36900329589844) {
        if (features[12] <= 335.9739990234375) {
            if (features[33] <= 223.5) {
                if (features[2] <= 34.5) {
                    classes[0] = 0; 
                    classes[1] = 3; 
                } else {
                    classes[0] = 3; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 4; 
                classes[1] = 0; 
            }
        } else {
            classes[0] = 0; 
            classes[1] = 8; 
        }
    } else {
        classes[0] = 14; 
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

int predict_4_s4_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[27] <= 65152.0) {
        if (features[25] <= 490.52349853515625) {
            if (features[21] <= 61296.0) {
                classes[0] = 16; 
                classes[1] = 0; 
            } else {
                if (features[2] <= 34.5) {
                    classes[0] = 0; 
                    classes[1] = 2; 
                } else {
                    classes[0] = 1; 
                    classes[1] = 0; 
                }
            }
        } else {
            if (features[8] <= 111.0) {
                classes[0] = 8; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 4; 
            }
        }
    } else {
        classes[0] = 0; 
        classes[1] = 1; 
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

int predict_5_s4_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[22] <= 0.6702380180358887) {
        classes[0] = 0; 
        classes[1] = 4; 
    } else {
        if (features[20] <= 62000.0) {
            if (features[24] <= 3951.5450439453125) {
                classes[0] = 14; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 1; 
            }
        } else {
            if (features[18] <= 934.449462890625) {
                if (features[13] <= 474.38099670410156) {
                    if (features[25] <= 430.1445007324219) {
                        if (features[2] <= 29.5) {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 5; 
                        }
                    } else {
                        classes[0] = 0; 
                        classes[1] = 2; 
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

int predict_6_s4_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[12] <= 3436.9949951171875) {
        if (features[14] <= 61760.0) {
            if (features[7] <= 303.0) {
                if (features[27] <= 2624.0) {
                    classes[0] = 0; 
                    classes[1] = 4; 
                } else {
                    if (features[24] <= 331.1159973144531) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    }
                }
            } else {
                if (features[13] <= 465.38099670410156) {
                    classes[0] = 7; 
                    classes[1] = 0; 
                } else {
                    if (features[21] <= 63216.0) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        if (features[2] <= 34.5) {
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
            classes[0] = 8; 
            classes[1] = 0; 
        }
    } else {
        classes[0] = 0; 
        classes[1] = 4; 
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

int predict_7_s4_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[30] <= 2239.0150146484375) {
        if (features[23] <= 218112.0) {
            if (features[21] <= 33584.0) {
                classes[0] = 9; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 1; 
            }
        } else {
            if (features[6] <= 80.0) {
                classes[0] = 5; 
                classes[1] = 0; 
            } else {
                if (features[2] <= 24.5) {
                    classes[0] = 2; 
                    classes[1] = 0; 
                } else {
                    if (features[29] <= 210294.0) {
                        if (features[2] <= 32.0) {
                            classes[0] = 1; 
                            classes[1] = 0; 
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
        }
    } else {
        classes[0] = 0; 
        classes[1] = 4; 
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

int predict_8_s4_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[25] <= 490.52349853515625) {
        if (features[12] <= 426.5760040283203) {
            if (features[2] <= 34.5) {
                classes[0] = 0; 
                classes[1] = 2; 
            } else {
                classes[0] = 7; 
                classes[1] = 0; 
            }
        } else {
            classes[0] = 7; 
            classes[1] = 0; 
        }
    } else {
        if (features[15] <= 5568.0) {
            if (features[17] <= 523234.0) {
                classes[0] = 0; 
                classes[1] = 2; 
            } else {
                classes[0] = 8; 
                classes[1] = 0; 
            }
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

int predict_9_s4_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[8] <= 111.0) {
        classes[0] = 10; 
        classes[1] = 0; 
    } else {
        if (features[22] <= 104.31794929504395) {
            if (features[23] <= 119148.0) {
                classes[0] = 1; 
                classes[1] = 0; 
            } else {
                if (features[20] <= 62800.0) {
                    classes[0] = 0; 
                    classes[1] = 7; 
                } else {
                    if (features[14] <= 52848.0) {
                        if (features[2] <= 29.5) {
                            classes[0] = 2; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 4; 
                        }
                    } else {
                        if (features[2] <= 34.5) {
                            classes[0] = 0; 
                            classes[1] = 2; 
                        } else {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        }
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

int predict_s4_VERT_SPLIT (float features[]) {
    int n_classes = 2;
    int classes[n_classes];
    int i;
    for (i = 0; i < n_classes; i++) {
        classes[i] = 0;
    }

    classes[predict_0_s4_VERT_SPLIT(features)]++;
    classes[predict_1_s4_VERT_SPLIT(features)]++;
    classes[predict_2_s4_VERT_SPLIT(features)]++;
    classes[predict_3_s4_VERT_SPLIT(features)]++;
    classes[predict_4_s4_VERT_SPLIT(features)]++;
    classes[predict_5_s4_VERT_SPLIT(features)]++;
    classes[predict_6_s4_VERT_SPLIT(features)]++;
    classes[predict_7_s4_VERT_SPLIT(features)]++;
    classes[predict_8_s4_VERT_SPLIT(features)]++;
    classes[predict_9_s4_VERT_SPLIT(features)]++;

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
