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

	//각을 돌리기 위해 이미지의 좌표를 가운데 픽셀을 가저온다.
	Point2f cp((src.cols - 1) / 2.0, (src.rows - 1) / 2.0);
	Mat rot = getRotationMatrix2D(cp, angle, 1.0);
	
	Rect2f rsize = RotatedRect(Point2f(), src.size(), angle).boundingRect2f();
	
	// 각변경 조정
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

	//그림판에서 확대한것처럼 픽셀이 다 드러난 상태에 확대
	tm.start();
	resize(src, dst1, Size(), 4, 4,INTER_NEAREST);
	tm.stop();
	cout << "INTER_NEAREST	" << tm.getTimeMilli() << "ms" << endl << endl;
	Sleep(10);
	
	//가성비 좋고 성능적으로빠르다.
	tm.start();
	resize(src, dst2, Size(1920, 1280));
	tm.stop();
	cout << "INTER_LINEAR	" << tm.getTimeMilli() << "ms" << endl << endl;
	Sleep(10);
	
	// 빠른대신 조금 흐림
	tm.start();
	resize(src, dst3, Size(1920,1280), INTER_CUBIC);
	tm.stop();
	cout << "INTER_CUBIC	" << tm.getTimeMilli() << "ms" << endl << endl;
	Sleep(10);
	
	//빠른대신 조금더 흐림
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