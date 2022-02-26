#include<opencv2\opencv.hpp>
#include<iostream>
#include"filter.h"

using namespace cv;
using namespace std;

void saltnoise(Mat img,int n)
{
	
	//imshow("ԭʼͼ��", img);

	int channel_num = img.channels();

	for (int k = 0; k < n / 2; k++)
	{
		//���ȷ��ͼ����λ��
		int i, j;
		i = std::rand() % img.cols;  //ȡ�������㣬��֤��ͼ��������� 
		j = std::rand() % img.rows;  //ȡ�������㣬��֤��ͼ��������� 
		int write_black = std::rand() % 2;  //�ж�Ϊ��ɫ�������Ǻ�ɫ�����ı���
		if (write_black == 0)  //��Ӱ�ɫ����
		{
			if (channel_num == 1)  //����Ҷ�ͼ��
			{
				img.at<uchar>(j, i) = 255;  //��ɫ����
			}
			else if (channel_num == 3)  //�����ɫͼ��
			{
				img.at<cv::Vec3b>(j, i)[0] = 255; //cv::Vec3bΪopencv�����һ��3��ֵ����������  
				img.at<cv::Vec3b>(j, i)[1] = 255; //[]ָ��ͨ����B:0��G:1��R:2  
				img.at<cv::Vec3b>(j, i)[2] = 255;
			}
		}
		else  //��Ӻ�ɫ����
		{
			if (img.type() == CV_8UC1)
			{
				img.at<uchar>(j, i) = 0;
			}
			else if (img.type() == CV_8UC3)
			{
				img.at<cv::Vec3b>(j, i)[0] = 0; //cv::Vec3bΪopencv�����һ��3��ֵ����������  
				img.at<cv::Vec3b>(j, i)[1] = 0; //[]ָ��ͨ����B:0��G:1��R:2  
				img.at<cv::Vec3b>(j, i)[2] = 0;
			}
		}


	}
	imshow("��������ͼ��", img);
}