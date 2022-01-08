// showImg.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
//#include"opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include<string>


using namespace std;
using namespace cv;

int main()
{
	Mat img = cv::imread(".\\1.jpg");
	cv::namedWindow("input Img", 0);
	cv::resizeWindow("input Img", img.cols, img.rows);
	cv::imshow("input Img", img);
	
	cv::waitKey(0);
	destroyAllWindows();

    return 0;
}

