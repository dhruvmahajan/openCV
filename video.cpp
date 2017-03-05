#include <cv.h>
#include <highgui.h>

using namespace std;
using namespace cv;

int main()
{
	Mat frame;
	VideoCapture cap;
	cap.open("motionTrackingTutorial/bouncingBall.avi");
	if(!cap.isOpened())
	{
		cout<<"Cannot open the video file"<<endl;
		return -1;
	}
	cap.set(CV_CAP_PROP_POS_MSEC, 1000);	
	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	cout<<"Depth width "<<dWidth<<endl;

	namedWindow("window1", CV_WINDOW_NORMAL);

	while(1)
	{
		if(!cap.read(frame))
		{
			cout << "Cannot read the frame from video file" << endl;
			break;
		}
		imshow("window1", frame);
		if(waitKey(30) == (int)'a') //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl; 
			break; 
		}
	}



}
