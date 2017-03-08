#include <cv.h>
#include <highgui.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat frame, prevFrame, frameYUV,prevFrameYUV, diff, diffThreshold ;
	VideoCapture cap("vehicalVideo.mp4");
	if(!cap.isOpened())
	{
		cout<<"Unable to open video"<<endl;
		return -1;
	}

	namedWindow("Window absDiffenrce", CV_WINDOW_AUTOSIZE);	
	namedWindow("Window Original", CV_WINDOW_AUTOSIZE);	

	int threshValue = 0;	
	createTrackbar("Threshold Trackbar", "Window absDiffenrce", &threshValue, 255);
	
	cap.read(prevFrame);
	cvtColor(prevFrame, prevFrameYUV, CV_BGR2YUV);
	
	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	cout<<"Widht: "<<dWidth<<" Height: "<<dHeight<<endl;	

	//cout<<"YUV: "<<(int)prevFrameYUV.channels();
	for(int i=500;i<510;i++){
		for(int j=500;j<510;j++){
			cout<< (int)prevFrameYUV.at<Vec3b>(Point(i,j))[0]<<" ";
		}
		cout<<endl;
	}


	while(waitKey(20)!=27)
	{
		if(!cap.read(frame))
		{
			cout<<"Cannot read the frame from video file" << endl;
			break;
		}
		
		cvtColor(frame, frameYUV, CV_BGR2YUV);
		absdiff(frameYUV, prevFrameYUV, diff);
		threshold(diff, diffThreshold, threshValue, 255, 3);

		/*for(int y=0;y<100;y++)
		{
			for(int x=0;x<100;x++)
			{
				Vec3b color = diffThreshold.at<Vec3b>(Point(x,y));
				color[0] =255;
				diffThreshold.at<Vec3b>(Point(x,y)) = color;
			}
		}*/

		imshow("Window absDiffenrce", diffThreshold);
		imshow("Window Original", frame);
		prevFrameYUV = frameYUV.clone();
			
	}

}
