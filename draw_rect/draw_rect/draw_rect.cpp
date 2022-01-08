/********
���̣�
���ȶ�ȡһ��ͼƬ
�������¶�ȡ��ǰ����pt1��pt2Ϊ����ƶ�ʱ������꣬��ʱ���������л�����ʱ����
����ɿ�����¼ĩ������Ϊpt2�������ص������л��ƾ���
*********/
#include"stdafx.h"
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
#define WINDOW_NAME "�����򴰿ڡ�"        //Ϊ���ڱ��ⶨ��ĺ� 
void on_MouseHandle(int event, int x, int y, int flags, void* param);
void DrawRectangle(cv::Mat& img);//�����κ���

bool g_bDrawingBox = false;//�Ƿ���л���
RNG g_rng(12345);
Point pt1, pt2;//pt1����갴����ʼ�㣬pt2��ĩ��
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
		srcImage.copyTo(tempImage);//����Դͼ����ʱ����
		if (g_bDrawingBox) {
			DrawRectangle(tempImage);
			is_draw_rect = true;
		}
		imshow(WINDOW_NAME, tempImage);
		char k = waitKey(20);
		if (k == 27) break;//����ESC���������˳�
		if (k == 'c')//����c�����������
			img.copyTo(srcImage);
	}
	return 0;
}
void DrawRectangle(cv::Mat& img)
{
	rectangle(img, Rect(pt1, pt2), cv::Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255)), 1);
}
//���������ص����������ݲ�ͬ������¼����в�ͬ�Ĳ���
void on_MouseHandle(int event, int x, int y, int flags, void* param)
{
	Mat& image = *(cv::Mat*) param;
	switch (event)
	{
		//����ƶ���Ϣ
	case EVENT_MOUSEMOVE:
	{
		if (g_bDrawingBox)//����Ƿ���л��Ƶı�ʶ��Ϊ�棬��¼
			pt2 = Point(x, y);
	}
	break;
	//���������Ϣ
	case EVENT_LBUTTONDOWN:
	{
		g_bDrawingBox = true;
		pt1 = Point(x, y);
		pt2 = pt1;
	}
	break;

	//���̧����Ϣ
	case EVENT_LBUTTONUP:
	{
		g_bDrawingBox = false;//�ñ�ʶ��Ϊfalse
		pt2 = Point(x, y);
		//���ú������л���
		DrawRectangle(image);
		if (pt1.x == pt2.x && pt1.y == pt2.y)
			printf("[%d, %d]\r\n", pt1.x, pt1.y);
		else
			printf("[%d, %d, %d, %d]\r\n", pt1.x, pt1.y, pt2.x, pt2.y);
	}
	break;
	}
}

