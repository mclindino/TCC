#include <iostream>
using namespace std;

auto getFeaturesRF(int type)
{
  float* features;
  if (type == 1)
  {
    features = (float *) malloc(sizeof(float)*34);
    features[0] = 1;
    features[1] = 2;
    features[2] = 3;
    features[3] = 4;
    features[4] = 5;
    features[5] = 6;
    features[6] = 7;
    features[7] = 8;
    features[8] = 9;
    features[9] = 10;
    features[10] = 11;
    features[11] = 12;
    features[12] = 13;
    features[13] = 14;
    features[14] = 15;
    features[15] = 16;
    features[16] = 17;
    features[17] = 18;
    features[18] = 19;
    features[19] = 20;
    features[20] = 21;
    features[21] = 22;
    features[22] = 23;
    features[23] = 24;
    features[24] = 25;
    features[25] = 26;
    features[26] = 27;
    features[27] = 28;
    features[28] = 29;
    features[29] = 30;
    features[30] = 31;
    features[31] = 32;
    features[32] = 33;
    features[33] = 34;
  }
  else if(type == 2)
  {
    features = (float *) malloc(sizeof(float)*32);
    features[0] = 32;
    features[1] = 31;
    features[2] = 30;
    features[3] = 29;
    features[4] = 28;
    features[5] = 27;
    features[6] = 26;
    features[7] = 25;
    features[8] = 24;
    features[9] = 23;
    features[10] = 22;
    features[11] = 21;
    features[12] = 20;
    features[13] = 19;
    features[14] = 18;
    features[15] = 17;
    features[16] = 16;
    features[17] = 15;
    features[18] = 14;
    features[19] = 13;
    features[20] = 12;
    features[21] = 11;
    features[22] = 10;
    features[23] = 9;
    features[24] = 8;
    features[25] = 7;
    features[26] = 6;
    features[27] = 5;
    features[28] = 4;
    features[29] = 3;
    features[30] = 2;
    features[31] = 1;
  }
  return features;
}

int main()
{
  float* pixel;
  pixel = getFeaturesRF(2);
  cout << pixel[0] << endl;
}