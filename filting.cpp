#include<opencv2\opencv.hpp>
#include<iostream>
#include"filter.h"

using namespace cv;
using namespace std;

void filting(Mat img, int ave, int stand, int size,int sigma)//输入图像，均值，标准差，卷积核大小，sigma标准差
{
	Mat img2, img3, img4;
	GaussianBlur(img, img2, Size(size, size), ave, stand);
	imshow("高斯滤波图像", img2);
	bilateralFilter(img, img3, size, sigma, sigma);
	imshow("双边滤波图像", img3);
	medianBlur(img, img4, size);
	imshow("中值滤波图像", img4);
}