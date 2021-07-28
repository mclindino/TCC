#include "s3_VERT_SPLIT.h"
int predict_0_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[9] <= 2.0) {
        classes[0] = 507; 
        classes[1] = 0; 
    } else {
        if (features[21] <= 453578.0) {
            if (features[19] <= 55872.0) {
                classes[0] = 16; 
                classes[1] = 0; 
            } else {
                if (features[30] <= 24639.5) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                } else {
                    classes[0] = 6; 
                    classes[1] = 0; 
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

int predict_1_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[26] <= 20.109127044677734) {
        if (features[19] <= 64592.0) {
            if (features[17] <= 559.376953125) {
                if (features[9] <= 2.0) {
                    classes[0] = 441; 
                    classes[1] = 0; 
                } else {
                    if (features[10] <= 14237.28466796875) {
                        if (features[21] <= 444260.0) {
                            classes[0] = 5; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        }
                    } else {
                        classes[0] = 15; 
                        classes[1] = 0; 
                    }
                }
            } else {
                if (features[22] <= 988.4779357910156) {
                    classes[0] = 3; 
                    classes[1] = 0; 
                } else {
                    if (features[9] <= 2.0) {
                        classes[0] = 1; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    }
                }
            }
        } else {
            if (features[9] <= 2.0) {
                classes[0] = 23; 
                classes[1] = 0; 
            } else {
                if (features[32] <= -0.10654062032699585) {
                    classes[0] = 0; 
                    classes[1] = 3; 
                } else {
                    classes[0] = 3; 
                    classes[1] = 0; 
                }
            }
        }
    } else {
        if (features[10] <= 11687.02099609375) {
            classes[0] = 26; 
            classes[1] = 0; 
        } else {
            if (features[8] <= 0.5) {
                classes[0] = 0; 
                classes[1] = 6; 
            } else {
                classes[0] = 6; 
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

int predict_2_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[9] <= 2.0) {
        classes[0] = 510; 
        classes[1] = 0; 
    } else {
        if (features[25] <= 47984.0) {
            if (features[32] <= -0.3584298640489578) {
                classes[0] = 0; 
                classes[1] = 7; 
            } else {
                classes[0] = 4; 
                classes[1] = 0; 
            }
        } else {
            if (features[21] <= 366704.0) {
                classes[0] = 12; 
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

int predict_3_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[11] <= 411.26953125) {
        if (features[17] <= 473.931640625) {
            if (features[9] <= 2.0) {
                classes[0] = 118; 
                classes[1] = 0; 
            } else {
                if (features[27] <= 426658.0) {
                    classes[0] = 10; 
                    classes[1] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 5; 
                }
            }
        } else {
            if (features[24] <= 9104.0) {
                classes[0] = 2; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 5; 
            }
        }
    } else {
        if (features[10] <= 4219.1343994140625) {
            classes[0] = 220; 
            classes[1] = 0; 
        } else {
            if (features[17] <= 551.890625) {
                classes[0] = 172; 
                classes[1] = 0; 
            } else {
                if (features[8] <= 0.5) {
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

int predict_4_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[19] <= 64592.0) {
        if (features[19] <= 57520.0) {
            if (features[23] <= 558.833984375) {
                classes[0] = 337; 
                classes[1] = 0; 
            } else {
                if (features[20] <= 2.2931989431381226) {
                    classes[0] = 20; 
                    classes[1] = 0; 
                } else {
                    if (features[23] <= 559.568359375) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    }
                }
            }
        } else {
            if (features[26] <= 19.541071891784668) {
                if (features[8] <= 0.5) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                } else {
                    classes[0] = 126; 
                    classes[1] = 0; 
                }
            } else {
                if (features[8] <= 0.5) {
                    classes[0] = 0; 
                    classes[1] = 4; 
                } else {
                    classes[0] = 10; 
                    classes[1] = 0; 
                }
            }
        }
    } else {
        if (features[9] <= 2.0) {
            classes[0] = 27; 
            classes[1] = 0; 
        } else {
            if (features[33] <= 70557.5) {
                classes[0] = 0; 
                classes[1] = 4; 
            } else {
                classes[0] = 2; 
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

int predict_5_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[13] <= 59344.0) {
        if (features[8] <= 0.5) {
            if (features[11] <= 521.619140625) {
                if (features[20] <= 0.6775454878807068) {
                    if (features[25] <= 50624.0) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    }
                } else {
                    classes[0] = 8; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 0; 
                classes[1] = 1; 
            }
        } else {
            classes[0] = 452; 
            classes[1] = 0; 
        }
    } else {
        if (features[16] <= 9287.06298828125) {
            classes[0] = 44; 
            classes[1] = 0; 
        } else {
            if (features[5] <= 47.0) {
                if (features[8] <= 0.5) {
                    classes[0] = 0; 
                    classes[1] = 7; 
                } else {
                    classes[0] = 13; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 6; 
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

int predict_6_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[11] <= 411.26953125) {
        if (features[9] <= 2.0) {
            classes[0] = 135; 
            classes[1] = 0; 
        } else {
            if (features[30] <= 175.5) {
                if (features[0] <= 32.0) {
                    classes[0] = 0; 
                    classes[1] = 6; 
                } else {
                    classes[0] = 1; 
                    classes[1] = 0; 
                }
            } else {
                classes[0] = 21; 
                classes[1] = 0; 
            }
        }
    } else {
        classes[0] = 371; 
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

int predict_7_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[19] <= 64592.0) {
        if (features[26] <= 20.109127044677734) {
            if (features[21] <= 479534.0) {
                if (features[21] <= 477368.0) {
                    if (features[10] <= 40930.62890625) {
                        classes[0] = 216; 
                        classes[1] = 0; 
                    } else {
                        if (features[16] <= 29339.5009765625) {
                            classes[0] = 2; 
                            classes[1] = 0; 
                        } else {
                            if (features[0] <= 34.5) {
                                if (features[8] <= 0.5) {
                                    classes[0] = 0; 
                                    classes[1] = 1; 
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
                } else {
                    if (features[9] <= 2.0) {
                        classes[0] = 2; 
                        classes[1] = 0; 
                    } else {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    }
                }
            } else {
                classes[0] = 233; 
                classes[1] = 0; 
            }
        } else {
            if (features[9] <= 2.0) {
                classes[0] = 36; 
                classes[1] = 0; 
            } else {
                if (features[3] <= 144.0) {
                    classes[0] = 0; 
                    classes[1] = 4; 
                } else {
                    classes[0] = 1; 
                    classes[1] = 0; 
                }
            }
        }
    } else {
        if (features[20] <= 0.09035971760749817) {
            classes[0] = 0; 
            classes[1] = 4; 
        } else {
            classes[0] = 29; 
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

int predict_8_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[9] <= 2.0) {
        classes[0] = 504; 
        classes[1] = 0; 
    } else {
        if (features[21] <= 382474.0) {
            classes[0] = 20; 
            classes[1] = 0; 
        } else {
            if (features[0] <= 34.5) {
                classes[0] = 0; 
                classes[1] = 9; 
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

int predict_9_s3_VERT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[10] <= 13767.6396484375) {
        if (features[8] <= 0.5) {
            if (features[27] <= 486366.0) {
                classes[0] = 5; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 1; 
            }
        } else {
            classes[0] = 400; 
            classes[1] = 0; 
        }
    } else {
        if (features[20] <= 0.08931311964988708) {
            if (features[18] <= 3792.0) {
                classes[0] = 3; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 6; 
            }
        } else {
            if (features[10] <= 14237.28466796875) {
                classes[0] = 0; 
                classes[1] = 1; 
            } else {
                if (features[9] <= 2.0) {
                    classes[0] = 98; 
                    classes[1] = 0; 
                } else {
                    if (features[30] <= 7039.5) {
                        if (features[14] <= 0.44170621037483215) {
                            classes[0] = 3; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 5; 
                        }
                    } else {
                        classes[0] = 12; 
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
