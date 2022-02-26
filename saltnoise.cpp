#include<opencv2\opencv.hpp>
#include<iostream>
#include"filter.h"

using namespace cv;
using namespace std;

void saltnoise(Mat img,int n)
{
	
	//imshow("原始图像", img);

	int channel_num = img.channels();

	for (int k = 0; k < n / 2; k++)
	{
		//随机确定图像中位置
		int i, j;
		i = std::rand() % img.cols;  //取余数运算，保证在图像的列数内 
		j = std::rand() % img.rows;  //取余数运算，保证在图像的行数内 
		int write_black = std::rand() % 2;  //判定为白色噪声还是黑色噪声的变量
		if (write_black == 0)  //添加白色噪声
		{
			if (channel_num == 1)  //处理灰度图像
			{
				img.at<uchar>(j, i) = 255;  //白色噪声
			}
			else if (channel_num == 3)  //处理彩色图像
			{
				img.at<cv::Vec3b>(j, i)[0] = 255; //cv::Vec3b为opencv定义的一个3个值的向量类型  
				img.at<cv::Vec3b>(j, i)[1] = 255; //[]指定通道，B:0，G:1，R:2  
				img.at<cv::Vec3b>(j, i)[2] = 255;
			}
		}
		else  //添加黑色噪声
		{
			if (img.type() == CV_8UC1)
			{
				img.at<uchar>(j, i) = 0;
			}
			else if (img.type() == CV_8UC3)
			{
				img.at<cv::Vec3b>(j, i)[0] = 0; //cv::Vec3b为opencv定义的一个3个值的向量类型  
				img.at<cv::Vec3b>(j, i)[1] = 0; //[]指定通道，B:0，G:1，R:2  
				img.at<cv::Vec3b>(j, i)[2] = 0;
			}
		}


	}
	imshow("椒盐噪声图像", img);
}