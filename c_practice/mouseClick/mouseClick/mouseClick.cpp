// mouseClick.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<opencv2\opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void on_mouse(int EVENT, int x, int y, int flags, void* userdata);
void main()
{
	while (1)
	{
		char k = waitKey(20);
		if (k == 27)
			break;
		namedWindow("【display】");
		Mat src;
		src = imread("./1.jpg");
		setMouseCallback("【display】", on_mouse, &src);
		imshow("【display】", src);
		waitKey(0);
		destroyAllWindows();
	}
}

void on_mouse(int EVENT, int x, int y, int flags, void* userdata)
{
	Mat hh;
	hh = *(Mat*)userdata;
	Point p(x, y);
	switch (EVENT)
	{
		case EVENT_LBUTTONDOWN:
		{
			printf("position=(%d,%d)\t",x,y);
			printf("b=%d\t", hh.at<Vec3b>(p)[0]);
			printf("g=%d\t", hh.at<Vec3b>(p)[1]);
			printf("r=%d\n", hh.at<Vec3b>(p)[2]);
			circle(hh, p, 2, Scalar(255), 3);
		}
		break;
	}
}

