#include<opencv2\opencv.hpp>
#include<iostream>


using namespace cv;
using namespace std;

void saltnoise(Mat img, int n);
void gaussnoise(Mat img, int ave, int stand);
void filting(Mat img, int ave, int stand, int size, int sigma);
void edg(Mat img);
void yang_gaussfilting(Mat img, int size, float stand, float variance);