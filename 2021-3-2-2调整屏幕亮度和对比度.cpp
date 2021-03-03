//调整屏幕亮度和对比度
#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;

int main()
{
	Mat src;
	src = imread("F:/image/1.2.png");
	if (!src.data)
	{
		printf("can not load the picture");
		return -1;
	}
	namedWindow("input",WINDOW_AUTOSIZE);
	imshow("input",src);
	int width = src.cols;//904
	int height = src.rows;//686
	float a = 0.8;
	float c = 30;
	Mat dst = Mat::zeros(src.size(),src.type());
	Mat m;
	src.convertTo(m, CV_32F);
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (src.channels() == 3)
			{
				float b = m.at<Vec3f>(row, col)[0];
				float g = m.at<Vec3f>(row, col)[1];
				float r = m.at<Vec3f>(row, col)[2];
				dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(a * b + c);//dst必须和src类型大小要一样,即dst要初始化
				dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(a * g + c);
				dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(a * r + c);
			}
		}
	}
	namedWindow("output", WINDOW_AUTOSIZE);
	imshow("output", dst);
	waitKey(0);
	return 0;
}