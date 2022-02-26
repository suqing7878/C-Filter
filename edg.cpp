#include<opencv2\opencv.hpp>
#include<iostream>
#include"filter.h"

using namespace cv;
using namespace std;

void edg(Mat img)
{
	Mat img2, img3, img4;
	Mat kernex = (Mat_<float>(1, 3) << 1, 0, -1);  //X·½Ïò±ßÔµ¼ì²âÂË²¨Æ÷
	Mat kerney = (Mat_<float>(3, 1) << 1, 0, -1);  //Y·½Ïò±ßÔµ¼ì²âÂË²¨Æ÷

	filter2D(img, img2, CV_16S, kernex);
	convertScaleAbs(img2, img2);//Çó¾ø¶ÔÖµ

	//ÒÔ[1 0 -1]'¼ì²âÓÉ´¹Ö±·½Ïò±ßÔµ
	filter2D(img, img3, CV_16S, kerney);
	convertScaleAbs(img3, img3);
	img4 = img2 + img3;
	imshow("±ßÔµÌáÈ¡", img3);

}