#include <cv.h>
#include <highgui.h>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat src;
	src = imread("pic.png", CV_LOAD_IMAGE_COLOR);
	if(!src.data)
	{
		cout<<"Error Loading image"<<endl;
		return -1;
	}
	
	namedWindow("trackbarWindow", CV_WINDOW_NORMAL);
	
	int brightnessSliderValue = 50;
	createTrackbar("Brightness", "trackbarWindow", &brightnessSliderValue, 100);
	
	while(1)
	{
		Mat dsc;
		int brightness = brightnessSliderValue - 50;
		src.convertTo(dsc, -1, 1, brightness);
		imshow("trackbarWindow", dsc);
		int key = waitKey(10);
		if(key==27)
		{
			cout<<"ESC Pressed"<<endl;
			break;
		}

	}

}
