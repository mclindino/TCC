#include "s3_VERT_SPLIT.h"
int predict_0_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[9] <= 2.0) {
        classes[0] = 769; 
        classes[1] = 0; 
    } else {
        if (features[21] <= 304723.078125) {
            classes[0] = 17; 
            classes[1] = 0; 
        } else {
            if (features[0] <= 24.5) {
                classes[0] = 3; 
                classes[1] = 0; 
            } else {
                if (features[1] <= 48.0) {
                    classes[0] = 0; 
                    classes[1] = 696; 
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

int predict_1_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[16] <= 7765.896240234375) {
        if (features[10] <= 11563.4609375) {
            classes[0] = 534; 
            classes[1] = 0; 
        } else {
            if (features[10] <= 14416.44482421875) {
                if (features[5] <= 111.0) {
                    classes[0] = 0; 
                    classes[1] = 29; 
                } else {
                    classes[0] = 1; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 23; 
                classes[1] = 0; 
            }
        }
    } else {
        if (features[19] <= 11008.0) {
            classes[0] = 75; 
            classes[1] = 0; 
        } else {
            if (features[0] <= 36.98390579223633) {
                if (features[24] <= 12768.0) {
                    classes[0] = 30; 
                    classes[1] = 0; 
                } else {
                    if (features[8] <= 0.5) {
                        if (features[29] <= 137.30859375) {
                            classes[0] = 0; 
                            classes[1] = 710; 
                        } else {
                            classes[0] = 4; 
                            classes[1] = 0; 
                        }
                    } else {
                        classes[0] = 36; 
                        classes[1] = 0; 
                    }
                }
            } else {
                if (features[15] <= 1137282.0) {
                    classes[0] = 42; 
                    classes[1] = 0; 
                } else {
                    if (features[26] <= 0.8544405996799469) {
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

int predict_2_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[9] <= 2.0) {
        classes[0] = 724; 
        classes[1] = 0; 
    } else {
        if (features[7] <= 1.5) {
            classes[0] = 7; 
            classes[1] = 0; 
        } else {
            if (features[32] <= -0.2469543218612671) {
                if (features[12] <= 57900.263671875) {
                    classes[0] = 0; 
                    classes[1] = 738; 
                } else {
                    classes[0] = 3; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 14; 
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

int predict_3_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[1] <= 48.0) {
        if (features[3] <= 112.0) {
            if (features[9] <= 2.0) {
                classes[0] = 101; 
                classes[1] = 0; 
            } else {
                if (features[31] <= 111.5) {
                    classes[0] = 0; 
                    classes[1] = 717; 
                } else {
                    classes[0] = 12; 
                    classes[1] = 0; 
                }
            }
        } else {
            classes[0] = 259; 
            classes[1] = 0; 
        }
    } else {
        classes[0] = 397; 
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

int predict_4_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[25] <= 48238.962890625) {
        if (features[19] <= 11024.0) {
            classes[0] = 156; 
            classes[1] = 0; 
        } else {
            if (features[1] <= 48.0) {
                if (features[30] <= 751.5) {
                    if (features[24] <= 11504.0) {
                        classes[0] = 26; 
                        classes[1] = 0; 
                    } else {
                        if (features[16] <= 5663.99169921875) {
                            if (features[8] <= 0.5) {
                                classes[0] = 0; 
                                classes[1] = 12; 
                            } else {
                                classes[0] = 38; 
                                classes[1] = 0; 
                            }
                        } else {
                            if (features[8] <= 0.5) {
                                classes[0] = 0; 
                                classes[1] = 678; 
                            } else {
                                classes[0] = 25; 
                                classes[1] = 0; 
                            }
                        }
                    }
                } else {
                    classes[0] = 11; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 134; 
                classes[1] = 0; 
            }
        }
    } else {
        if (features[9] <= 2.0) {
            classes[0] = 354; 
            classes[1] = 0; 
        } else {
            if (features[18] <= 13710.94482421875) {
                classes[0] = 0; 
                classes[1] = 36; 
            } else {
                if (features[27] <= 420469.203125) {
                    classes[0] = 12; 
                    classes[1] = 0; 
                } else {
                    if (features[5] <= 211.67840957641602) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        classes[0] = 3; 
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

int predict_5_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[15] <= 847566.90625) {
        if (features[8] <= 0.5) {
            if (features[33] <= 70557.5) {
                if (features[1] <= 48.0) {
                    classes[0] = 0; 
                    classes[1] = 564; 
                } else {
                    classes[0] = 6; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 9; 
                classes[1] = 0; 
            }
        } else {
            classes[0] = 116; 
            classes[1] = 0; 
        }
    } else {
        if (features[5] <= 143.0) {
            if (features[16] <= 7785.47607421875) {
                classes[0] = 53; 
                classes[1] = 0; 
            } else {
                if (features[9] <= 2.0) {
                    classes[0] = 27; 
                    classes[1] = 0; 
                } else {
                    if (features[33] <= 142821.5) {
                        classes[0] = 0; 
                        classes[1] = 222; 
                    } else {
                        classes[0] = 3; 
                        classes[1] = 0; 
                    }
                }
            }
        } else {
            classes[0] = 486; 
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

int predict_6_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[11] <= 411.26953125) {
        if (features[9] <= 2.0) {
            classes[0] = 125; 
            classes[1] = 0; 
        } else {
            if (features[30] <= 12575.5) {
                if (features[25] <= 50560.0) {
                    classes[0] = 0; 
                    classes[1] = 511; 
                } else {
                    classes[0] = 6; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 15; 
                classes[1] = 0; 
            }
        }
    } else {
        if (features[3] <= 112.0) {
            if (features[20] <= 1.1290767192840576) {
                if (features[24] <= 36285.2734375) {
                    classes[0] = 51; 
                    classes[1] = 0; 
                } else {
                    if (features[12] <= 29900.9189453125) {
                        if (features[8] <= 0.5) {
                            classes[0] = 0; 
                            classes[1] = 65; 
                        } else {
                            classes[0] = 14; 
                            classes[1] = 0; 
                        }
                    } else {
                        if (features[9] <= 2.0) {
                            classes[0] = 21; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 5; 
                        }
                    }
                }
            } else {
                if (features[9] <= 2.0) {
                    classes[0] = 17; 
                    classes[1] = 0; 
                } else {
                    if (features[21] <= 339983.71875) {
                        classes[0] = 4; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 136; 
                    }
                }
            }
        } else {
            classes[0] = 516; 
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

int predict_7_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[2] <= 48.0) {
        classes[0] = 409; 
        classes[1] = 0; 
    } else {
        if (features[22] <= 4940.574462890625) {
            if (features[27] <= 572386.0) {
                if (features[8] <= 0.5) {
                    if (features[11] <= 460.3601989746094) {
                        classes[0] = 6; 
                        classes[1] = 0; 
                    } else {
                        if (features[33] <= 142821.5) {
                            classes[0] = 0; 
                            classes[1] = 23; 
                        } else {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        }
                    }
                } else {
                    classes[0] = 241; 
                    classes[1] = 0; 
                }
            } else {
                if (features[3] <= 64.0) {
                    classes[0] = 7; 
                    classes[1] = 0; 
                } else {
                    if (features[7] <= 1.5) {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    } else {
                        if (features[21] <= 596504.0) {
                            classes[0] = 0; 
                            classes[1] = 80; 
                        } else {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        }
                    }
                }
            }
        } else {
            if (features[9] <= 2.0) {
                classes[0] = 117; 
                classes[1] = 0; 
            } else {
                if (features[32] <= -0.30621302127838135) {
                    classes[0] = 0; 
                    classes[1] = 593; 
                } else {
                    classes[0] = 6; 
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

int predict_8_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[9] <= 2.0) {
        classes[0] = 719; 
        classes[1] = 0; 
    } else {
        if (features[21] <= 292902.0) {
            classes[0] = 15; 
            classes[1] = 0; 
        } else {
            if (features[1] <= 48.0) {
                classes[0] = 0; 
                classes[1] = 748; 
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

int predict_9_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[10] <= 4219.1343994140625) {
        classes[0] = 424; 
        classes[1] = 0; 
    } else {
        if (features[8] <= 0.5) {
            if (features[27] <= 296410.0) {
                classes[0] = 12; 
                classes[1] = 0; 
            } else {
                if (features[24] <= 9584.0) {
                    classes[0] = 5; 
                    classes[1] = 0; 
                } else {
                    if (features[0] <= 36.98390579223633) {
                        classes[0] = 0; 
                        classes[1] = 726; 
                    } else {
                        if (features[22] <= 16459.16650390625) {
                            classes[0] = 0; 
                            classes[1] = 3; 
                        } else {
                            classes[0] = 5; 
                            classes[1] = 0; 
                        }
                    }
                }
            }
        } else {
            classes[0] = 311; 
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

int predict_s3_VERT_SPLIT (float features[]) {
    int n_classes = 2;
    int classes[n_classes];
    int i;
    for (i = 0; i < n_classes; i++) {
        classes[i] = 0;
    }

    classes[predict_0_s3_VERT_SPLIT(features)]++;
    classes[predict_1_s3_VERT_SPLIT(features)]++;
    classes[predict_2_s3_VERT_SPLIT(features)]++;
    classes[predict_3_s3_VERT_SPLIT(features)]++;
    classes[predict_4_s3_VERT_SPLIT(features)]++;
    classes[predict_5_s3_VERT_SPLIT(features)]++;
    classes[predict_6_s3_VERT_SPLIT(features)]++;
    classes[predict_7_s3_VERT_SPLIT(features)]++;
    classes[predict_8_s3_VERT_SPLIT(features)]++;
    classes[predict_9_s3_VERT_SPLIT(features)]++;

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
