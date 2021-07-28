#include "s3_HORZ_SPLIT.h"
int predict_0_s3_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[28] <= 24148.96875) {
        if (features[21] <= 188020.0) {
            if (features[0] <= 29.5) {
                classes[0] = 5; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 1; 
            }
        } else {
            classes[0] = 549; 
            classes[1] = 0; 
        }
    } else {
        if (features[8] <= 0.5) {
            if (features[0] <= 29.5) {
                classes[0] = 6; 
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

int predict_1_s3_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[27] <= 137364.0) {
        if (features[0] <= 27.0) {
            classes[0] = 1; 
            classes[1] = 0; 
        } else {
            classes[0] = 0; 
            classes[1] = 3; 
        }
    } else {
        if (features[32] <= 12.989284038543701) {
            if (features[21] <= 188020.0) {
                if (features[31] <= 6496.0) {
                    classes[0] = 2; 
                    classes[1] = 0; 
                } else {
                    if (features[0] <= 29.5) {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    }
                }
            } else {
                classes[0] = 551; 
                classes[1] = 0; 
            }
        } else {
            if (features[0] <= 29.5) {
                classes[0] = 2; 
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

int predict_2_s3_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[9] <= 2.0) {
        classes[0] = 531; 
        classes[1] = 0; 
    } else {
        if (features[22] <= 22264.6474609375) {
            if (features[23] <= 500.1171875) {
                if (features[12] <= 56592.0) {
                    classes[0] = 14; 
                    classes[1] = 0; 
                } else {
                    if (features[16] <= 14259.9228515625) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        if (features[0] <= 29.5) {
                            classes[0] = 4; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        }
                    }
                }
            } else {
                if (features[7] <= 1.5) {
                    classes[0] = 2; 
                    classes[1] = 0; 
                } else {
                    if (features[13] <= 27904.0) {
                        if (features[0] <= 29.5) {
                            classes[0] = 2; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        }
                    } else {
                        if (features[0] <= 29.5) {
                            classes[0] = 3; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        }
                    }
                }
            }
        } else {
            if (features[0] <= 27.0) {
                classes[0] = 1; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 2; 
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

int predict_3_s3_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[11] <= 558.55859375) {
        classes[0] = 545; 
        classes[1] = 0; 
    } else {
        if (features[20] <= 4.876635164022446) {
            classes[0] = 11; 
            classes[1] = 0; 
        } else {
            if (features[18] <= 62016.0) {
                classes[0] = 3; 
                classes[1] = 0; 
            } else {
                if (features[0] <= 29.5) {
                    classes[0] = 2; 
                    classes[1] = 0; 
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

int predict_4_s3_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[19] <= 7056.0) {
        if (features[27] <= 274498.0) {
            if (features[28] <= 1386.5873718261719) {
                classes[0] = 2; 
                classes[1] = 0; 
            } else {
                if (features[17] <= 370.67578125) {
                    classes[0] = 0; 
                    classes[1] = 3; 
                } else {
                    if (features[24] <= 53248.0) {
                        if (features[13] <= 12672.0) {
                            if (features[0] <= 27.0) {
                                classes[0] = 2; 
                                classes[1] = 0; 
                            } else {
                                classes[0] = 0; 
                                classes[1] = 2; 
                            }
                        } else {
                            if (features[0] <= 29.5) {
                                classes[0] = 3; 
                                classes[1] = 0; 
                            } else {
                                classes[0] = 0; 
                                classes[1] = 3; 
                            }
                        }
                    } else {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    }
                }
            }
        } else {
            classes[0] = 115; 
            classes[1] = 0; 
        }
    } else {
        if (features[29] <= 489.84765625) {
            classes[0] = 427; 
            classes[1] = 0; 
        } else {
            if (features[18] <= 23632.0) {
                classes[0] = 2; 
                classes[1] = 0; 
            } else {
                if (features[0] <= 29.5) {
                    classes[0] = 2; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 1; 
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

int predict_5_s3_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[27] <= 140332.0) {
        if (features[0] <= 27.0) {
            classes[0] = 1; 
            classes[1] = 0; 
        } else {
            classes[0] = 0; 
            classes[1] = 2; 
        }
    } else {
        classes[0] = 560; 
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

int predict_6_s3_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[28] <= 24249.3544921875) {
        if (features[27] <= 189230.0) {
            if (features[20] <= 9.043600231409073) {
                classes[0] = 5; 
                classes[1] = 0; 
            } else {
                if (features[0] <= 29.5) {
                    classes[0] = 6; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 1; 
                }
            }
        } else {
            classes[0] = 543; 
            classes[1] = 0; 
        }
    } else {
        if (features[27] <= 144426.0) {
            if (features[0] <= 27.0) {
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

int predict_7_s3_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[30] <= 832.0) {
        classes[0] = 505; 
        classes[1] = 0; 
    } else {
        if (features[21] <= 280150.0) {
            if (features[14] <= 53.01096153259277) {
                classes[0] = 35; 
                classes[1] = 0; 
            } else {
                if (features[0] <= 27.0) {
                    classes[0] = 4; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 1; 
                }
            }
        } else {
            if (features[33] <= 203568.0) {
                if (features[0] <= 27.0) {
                    classes[0] = 1; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 4; 
                }
            } else {
                if (features[33] <= 260046.0) {
                    classes[0] = 5; 
                    classes[1] = 0; 
                } else {
                    if (features[25] <= 25952.0) {
                        if (features[0] <= 29.5) {
                            classes[0] = 3; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 2; 
                        }
                    } else {
                        if (features[0] <= 27.0) {
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

int predict_8_s3_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[9] <= 2.0) {
        classes[0] = 527; 
        classes[1] = 0; 
    } else {
        if (features[18] <= 42608.0) {
            classes[0] = 15; 
            classes[1] = 0; 
        } else {
            if (features[27] <= 279756.0) {
                if (features[21] <= 208450.0) {
                    if (features[0] <= 27.0) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    }
                } else {
                    if (features[0] <= 29.5) {
                        classes[0] = 8; 
                        classes[1] = 0; 
                    } else {
                        if (features[17] <= 547.16796875) {
                            classes[0] = 4; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 2; 
                        }
                    }
                }
            } else {
                if (features[0] <= 29.5) {
                    classes[0] = 2; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 3; 
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

int predict_9_s3_HORZ_SPLIT(float features[]) {
    int classes[2];
    
    if (features[32] <= 0.3722296208143234) {
        classes[0] = 525; 
        classes[1] = 0; 
    } else {
        if (features[11] <= 566.421875) {
            if (features[27] <= 139246.0) {
                if (features[0] <= 29.5) {
                    classes[0] = 3; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 1; 
                }
            } else {
                classes[0] = 32; 
                classes[1] = 0; 
            }
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

int predict_s3_HORZ_SPLIT (float features[]) {
    int n_classes = 2;
    int classes[n_classes];
    int i;
    for (i = 0; i < n_classes; i++) {
        classes[i] = 0;
    }

    classes[predict_0_s3_HORZ_SPLIT(features)]++;
    classes[predict_1_s3_HORZ_SPLIT(features)]++;
    classes[predict_2_s3_HORZ_SPLIT(features)]++;
    classes[predict_3_s3_HORZ_SPLIT(features)]++;
    classes[predict_4_s3_HORZ_SPLIT(features)]++;
    classes[predict_5_s3_HORZ_SPLIT(features)]++;
    classes[predict_6_s3_HORZ_SPLIT(features)]++;
    classes[predict_7_s3_HORZ_SPLIT(features)]++;
    classes[predict_8_s3_HORZ_SPLIT(features)]++;
    classes[predict_9_s3_HORZ_SPLIT(features)]++;

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
