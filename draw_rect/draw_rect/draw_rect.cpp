/********
流程：
首先读取一张图片
按键按下读取当前坐标pt1，pt2为鼠标移动时候的坐标，此时在主函数中绘制临时矩形
鼠标松开，记录末点坐标为pt2，在鼠标回调函数中绘制矩形
*********/
#include"stdafx.h"
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
#define WINDOW_NAME "【程序窗口】"        //为窗口标题定义的宏 
void on_MouseHandle(int event, int x, int y, int flags, void* param);
void DrawRectangle(cv::Mat& img);//画矩形函数

bool g_bDrawingBox = false;//是否进行绘制
RNG g_rng(12345);
Point pt1, pt2;//pt1是鼠标按下起始点，pt2是末点
int main(int argc, char** argv)
{
	Mat srcImage = imread("1.jpg");
	Mat img;
	srcImage.copyTo(img);
	Mat tempImage;
	srcImage.copyTo(tempImage);
	namedWindow(WINDOW_NAME);
	setMouseCallback(WINDOW_NAME, on_MouseHandle, (void*)&srcImage);
	while (1)
	{
		bool is_draw_rect = false;
		srcImage.copyTo(tempImage);//拷贝源图到临时变量
		if (g_bDrawingBox) {
			DrawRectangle(tempImage);
			is_draw_rect = true;
		}
		imshow(WINDOW_NAME, tempImage);
		char k = waitKey(20);
		if (k == 27) break;//按下ESC键，程序退出
		if (k == 'c')//按下c键，清除矩形
			img.copyTo(srcImage);
	}
	return 0;
}
void DrawRectangle(cv::Mat& img)
{
	rectangle(img, Rect(pt1, pt2), cv::Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255)), 1);
}
//描述：鼠标回调函数，根据不同的鼠标事件进行不同的操作
void on_MouseHandle(int event, int x, int y, int flags, void* param)
{
	Mat& image = *(cv::Mat*) param;
	switch (event)
	{
		//鼠标移动消息
	case EVENT_MOUSEMOVE:
	{
		if (g_bDrawingBox)//如果是否进行绘制的标识符为真，记录
			pt2 = Point(x, y);
	}
	break;
	//左键按下消息
	case EVENT_LBUTTONDOWN:
	{
		g_bDrawingBox = true;
		pt1 = Point(x, y);
		pt2 = pt1;
	}
	break;

	//左键抬起消息
	case EVENT_LBUTTONUP:
	{
		g_bDrawingBox = false;//置标识符为false
		pt2 = Point(x, y);
		//调用函数进行绘制
		DrawRectangle(image);
		if (pt1.x == pt2.x && pt1.y == pt2.y)
			printf("[%d, %d]\r\n", pt1.x, pt1.y);
		else
			printf("[%d, %d, %d, %d]\r\n", pt1.x, pt1.y, pt2.x, pt2.y);
	}
	break;
	}
}

