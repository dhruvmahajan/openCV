#include <cv.h>
#include <highgui.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat frame, prevFrame, frameHSV,prevFrameHSV, diff, diff2 ;
	VideoCapture cap("vehicalVideo.mp4");
	if(!cap.isOpened())
	{
		cout<<"Unable to open video"<<endl;
		return -1;
	}

	namedWindow("Window1", CV_WINDOW_NORMAL);	
	namedWindow("Window2", CV_WINDOW_NORMAL);	
	
	cap.read(prevFrame);
	cvtColor(prevFrame, prevFrameHSV, CV_BGR2HSV);
	while(waitKey(20)!=27)
	{
		if(!cap.read(frame))
		{
			cout<<"Cannot read the frame from video file" << endl;
			break;
		}
		
		cvtColor(frame, frameHSV, CV_BGR2HSV);
		absdiff(frame, prevFrame, diff);
		imshow("Window1", diff);

		diff2 = frame - prevFrame;
		imshow("Window2", diff2);
		prevFrame = frame.clone();
			
	}

}
