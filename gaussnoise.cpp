#include<opencv2\opencv.hpp>
#include<iostream>
#include"filter.h"

using namespace cv;
using namespace std;

void gaussnoise(Mat img,int ave,int stand)
{

	cv::Mat img2(Size(img.cols, img.rows), img.type());
	RNG rng;  //����һ��RNG��
	rng.fill(img2, RNG::NORMAL, ave, stand);  //��ֵ����׼��
	img = img2 + img;
	imshow("��˹����ͼ��", img);

}