//调整屏幕亮度和对比度1
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/types_c.h>//#include <opencv2/imgproc/types_c.h>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;

int main()
{
	Mat src;
	src = imread("F:/image/1.png");
	if (!src.data)
	{
		printf("can not load the picture");
		return -1;
	}
	char arr1[] = "input";
	namedWindow(arr1,WINDOW_AUTOSIZE);
	imshow(arr1,src);
	int width = src.cols;//904
	int height = src.rows;//686
	float a = 0.8;
	float c = 100;
	Mat dst = Mat::zeros(src.size(),src.type());
	Mat m;
	src.convertTo(m, CV_32F);
	/*cvtColor(src,m1,CV_BGR2GRAY);
	namedWindow("gray", WINDOW_AUTOSIZE);
	imshow("gray", m1);*/
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
			else if(src.channels()==1)
			{ 
				int gray = src.at<uchar>(row, col);
				dst.at<uchar>(row, col) = saturate_cast<uchar>(a * gray + c);
			}
		}
	}
	char arr2[] = "output";
	namedWindow(arr2, WINDOW_AUTOSIZE);
	imshow(arr2, dst);
	waitKey(0);
	return 0;
}