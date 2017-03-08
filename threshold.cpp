#include <cv.h>
#include <highgui.h>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("apple.jpg", 1);
	namedWindow("Threshold Window", CV_WINDOW_NORMAL);
	cvtColor(src, src, COLOR_BGR2GRAY);	
	int threshValue = 0;
	int type = 0;
	createTrackbar("Threshold Trackbar", "Threshold Window", &threshValue, 255);
	createTrackbar("Type", "Threshold Window", &type, 4);

	while(1)
	{
		Mat dsc;
		threshold(src, dsc, threshValue, 255, type);
		imshow("Threshold Window", dsc);
		waitKey(20);
	}


}
