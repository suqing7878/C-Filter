#include<opencv2\opencv.hpp>
#include<iostream>
#include"filter.h"

using namespace cv;
using namespace std;

void filting(Mat img, int ave, int stand, int size,int sigma)//����ͼ�񣬾�ֵ����׼�����˴�С��sigma��׼��
{
	Mat img2, img3, img4;
	GaussianBlur(img, img2, Size(size, size), ave, stand);
	imshow("��˹�˲�ͼ��", img2);
	bilateralFilter(img, img3, size, sigma, sigma);
	imshow("˫���˲�ͼ��", img3);
	medianBlur(img, img4, size);
	imshow("��ֵ�˲�ͼ��", img4);
}