#include<opencv2\opencv.hpp>
#include<iostream>
#include"filter.h"

using namespace cv;
using namespace std;

void yang_gaussfilting(Mat img, int size, float stand, float variance)
{
	
	//int size = 3;//高斯核半径
	int corepoint = ((size + 1) / 2) - 1;

	//float stand = 1;//标准差
	//float variance = 1;//方差
	Mat kerne = Mat_<float>(size, size);//创建矩阵
	float jishu = 0;
	//float gui =1/(stand * exp((-(pow(corepoint, 2) + pow(corepoint, 2))) / (2 * pow(variance, 2))));//归一化
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			float r2 = pow(i - corepoint, 2) + pow(j - corepoint, 2);//r^2
			float k = (stand * exp((-r2) / (2 * pow(variance, 2))));
			kerne.at<float>(i, j) = k;//高斯核赋值
			jishu = jishu + k;
		}
	}
	kerne = kerne / jishu;
	Mat img3;
	filter2D(img, img3, img.type(), kerne);
	imshow("高斯滤波图像", img3);
	
}


