#include<opencv2\opencv.hpp>
#include<iostream>
#include"filter.h"

using namespace cv;
using namespace std;

void edg(Mat img)
{
	Mat img2, img3, img4;
	Mat kernex = (Mat_<float>(1, 3) << 1, 0, -1);  //X�����Ե����˲���
	Mat kerney = (Mat_<float>(3, 1) << 1, 0, -1);  //Y�����Ե����˲���

	filter2D(img, img2, CV_16S, kernex);
	convertScaleAbs(img2, img2);//�����ֵ

	//��[1 0 -1]'����ɴ�ֱ�����Ե
	filter2D(img, img3, CV_16S, kerney);
	convertScaleAbs(img3, img3);
	img4 = img2 + img3;
	imshow("��Ե��ȡ", img3);

}