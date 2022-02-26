#include<opencv2\opencv.hpp>
#include<iostream>
#include"filter.h"

using namespace cv;
using namespace std;

void yang_gaussfilting(Mat img, int size, float stand, float variance)
{
	
	//int size = 3;//��˹�˰뾶
	int corepoint = ((size + 1) / 2) - 1;

	//float stand = 1;//��׼��
	//float variance = 1;//����
	Mat kerne = Mat_<float>(size, size);//��������
	float jishu = 0;
	//float gui =1/(stand * exp((-(pow(corepoint, 2) + pow(corepoint, 2))) / (2 * pow(variance, 2))));//��һ��
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			float r2 = pow(i - corepoint, 2) + pow(j - corepoint, 2);//r^2
			float k = (stand * exp((-r2) / (2 * pow(variance, 2))));
			kerne.at<float>(i, j) = k;//��˹�˸�ֵ
			jishu = jishu + k;
		}
	}
	kerne = kerne / jishu;
	Mat img3;
	filter2D(img, img3, img.type(), kerne);
	imshow("��˹�˲�ͼ��", img3);
	
}


