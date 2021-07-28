#include "s4_QT_SPLIT.h"
int predict_0_s4_QT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[32] <= 2240.0) {
        classes[0] = 0; 
        classes[1] = 3; 
    } else {
        classes[0] = 3; 
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

int predict_1_s4_QT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[31] <= 421.7034912109375) {
        classes[0] = 0; 
        classes[1] = 1; 
    } else {
        if (features[7] <= 207.0) {
            if (features[2] <= 34.5) {
                classes[0] = 2; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 1; 
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

int predict_2_s4_QT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[25] <= 514.2655029296875) {
        classes[0] = 0; 
        classes[1] = 2; 
    } else {
        if (features[2] <= 34.5) {
            classes[0] = 1; 
            classes[1] = 0; 
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

int predict_3_s4_QT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[17] <= 417568.0) {
        classes[0] = 0; 
        classes[1] = 1; 
    } else {
        if (features[12] <= 1996.8304443359375) {
            if (features[2] <= 34.5) {
                classes[0] = 2; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 1; 
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

int predict_4_s4_QT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[2] <= 29.5) {
        classes[0] = 0; 
        classes[1] = 2; 
    } else {
        if (features[2] <= 34.5) {
            classes[0] = 3; 
            classes[1] = 0; 
        } else {
            classes[0] = 0; 
            classes[1] = 1; 
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

int predict_5_s4_QT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[25] <= 429.6094970703125) {
        classes[0] = 2; 
        classes[1] = 0; 
    } else {
        if (features[14] <= 34128.0) {
            if (features[2] <= 29.5) {
                classes[0] = 0; 
                classes[1] = 2; 
            } else {
                classes[0] = 1; 
                classes[1] = 0; 
            }
        } else {
            classes[0] = 0; 
            classes[1] = 1; 
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

int predict_6_s4_QT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[29] <= 100206.0) {
        classes[0] = 1; 
        classes[1] = 0; 
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

int predict_7_s4_QT_SPLIT(float features[]) {
    int classes[2];
    
    classes[0] = 0; 
    classes[1] = 6; 
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

int predict_8_s4_QT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[25] <= 391.42999267578125) {
        classes[0] = 2; 
        classes[1] = 0; 
    } else {
        if (features[30] <= 522.2570190429688) {
            classes[0] = 0; 
            classes[1] = 2; 
        } else {
            if (features[2] <= 29.5) {
                classes[0] = 0; 
                classes[1] = 1; 
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

int predict_9_s4_QT_SPLIT(float features[]) {
    int classes[2];
    
    if (features[8] <= 79.0) {
        if (features[2] <= 29.5) {
            classes[0] = 0; 
            classes[1] = 1; 
        } else {
            classes[0] = 2; 
            classes[1] = 0; 
        }
    } else {
        classes[0] = 0; 
        classes[1] = 3; 
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

int predict_s4_QT_SPLIT (float features[]) {
    int n_classes = 2;
    int classes[n_classes];
    int i;
    for (i = 0; i < n_classes; i++) {
        classes[i] = 0;
    }

    classes[predict_0_s4_QT_SPLIT(features)]++;
    classes[predict_1_s4_QT_SPLIT(features)]++;
    classes[predict_2_s4_QT_SPLIT(features)]++;
    classes[predict_3_s4_QT_SPLIT(features)]++;
    classes[predict_4_s4_QT_SPLIT(features)]++;
    classes[predict_5_s4_QT_SPLIT(features)]++;
    classes[predict_6_s4_QT_SPLIT(features)]++;
    classes[predict_7_s4_QT_SPLIT(features)]++;
    classes[predict_8_s4_QT_SPLIT(features)]++;
    classes[predict_9_s4_QT_SPLIT(features)]++;

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
