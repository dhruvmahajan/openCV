#include <cv.h>
#include <highgui.h>
//#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
using namespace cv;

int main()
{
	Mat image(100, 100, CV_8UC3, Scalar(100,0,0));
	for(int i=3;i<4;i++)
		for(int j=3;j<4;j++)
			image.at<Vec3b>(Point(i,j))[0]=255;
	namedWindow("user image", CV_WINDOW_NORMAL); //CV_WINDOW_AUTOSIZE
	imshow("user image", image);
	waitKey(0);
	
}
