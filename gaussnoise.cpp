#include<opencv2\opencv.hpp>
#include<iostream>
#include"filter.h"

using namespace cv;
using namespace std;

void gaussnoise(Mat img,int ave,int stand)
{

	cv::Mat img2(Size(img.cols, img.rows), img.type());
	RNG rng;  //创建一个RNG类
	rng.fill(img2, RNG::NORMAL, ave, stand);  //均值，标准差
	img = img2 + img;
	imshow("高斯噪声图像", img);

}