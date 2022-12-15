#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;
using namespace cv;

//void affine_scale();
void affine_rotate();
//void size_trans();

TickMeter tm;

int main()
{
	//affine_scale();
	//size_trans();
	affine_rotate();
	return 0;
}

void affine_rotate()
{

	Mat src = imread("tekapo.bmp");
	if (src.empty())
	{
		cerr << "Image load failed!" << endl;
		return;
	}
	double angle = -45;

	//���� ������ ���� �̹����� ��ǥ�� ��� �ȼ��� �����´�.
	Point2f cp((src.cols - 1) / 2.0, (src.rows - 1) / 2.0);
	Mat rot = getRotationMatrix2D(cp, angle, 1.0);
	
	Rect2f rsize = RotatedRect(Point2f(), src.size(), angle).boundingRect2f();
	
	// ������ ����
	rot.at<double>(0, 2) += rsize.width / 2.0 - src.cols / 2.0;
	rot.at<double>(1, 2) += rsize.height / 2.0 - src.rows / 2.0;

	Mat dst;
	warpAffine(src, dst, rot, rsize.size());
	imshow("src", src);
	imshow("dst1", dst);

	waitKey();
	destroyAllWindows();

	
}


void affine_scale()
{
	/*Mat src = imread("rose.bmp");

	if(src.empty())
	{
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dst1, dst2, dst3, dst4;

	//�׸��ǿ��� Ȯ���Ѱ�ó�� �ȼ��� �� �巯�� ���¿� Ȯ��
	tm.start();
	resize(src, dst1, Size(), 4, 4,INTER_NEAREST);
	tm.stop();
	cout << "INTER_NEAREST	" << tm.getTimeMilli() << "ms" << endl << endl;
	Sleep(10);
	
	//������ ���� ���������κ�����.
	tm.start();
	resize(src, dst2, Size(1920, 1280));
	tm.stop();
	cout << "INTER_LINEAR	" << tm.getTimeMilli() << "ms" << endl << endl;
	Sleep(10);
	
	// ������� ���� �帲
	tm.start();
	resize(src, dst3, Size(1920,1280), INTER_CUBIC);
	tm.stop();
	cout << "INTER_CUBIC	" << tm.getTimeMilli() << "ms" << endl << endl;
	Sleep(10);
	
	//������� ���ݴ� �帲
	tm.start();
	resize(src, dst4, Size(1920, 1280),INTER_LANCZOS4);
	tm.stop();
	cout << "INTER_LANCZOS4	" << tm.getTimeMilli() << "ms" << endl << endl;
	Sleep(10);
	

	imshow("src", src);
	imshow("dst1", dst1(Rect(400,500,400,400)));
	imshow("dst2", dst2(Rect(400,500,400,400)));
	imshow("dst3", dst3(Rect(400,500,400,400)));
	imshow("dst4", dst4(Rect(400,500,400,400)));

	waitKey();
	destroyAllWindows();*/
}