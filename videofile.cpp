#include <highgui.h>
#include <cv.h>
#include <iostream>

using namespace cv;
using namespace std;

string intToString(int number){


	std::stringstream ss;
	ss << number;
	return ss.str();
}

int main(int argc, char* argv[])
{

	VideoCapture cap(0); // open the video camera no. 0

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "ERROR INITIALIZING VIDEO CAPTURE" << endl;
		return -1;
	}

	
	VideoWriter writer;

	char* windowName = "Webcam Feed";
	namedWindow(windowName,CV_WINDOW_AUTOSIZE); //create a window to display our webcam feed

	string filename = "myVideo.avi";
	
	//fourcc four charcter code
	int fcc = CV_FOURCC('D','I','V','3');

	// frames per sec integer

	int fps = 20;

	// frame size

	Size frameSize(cap.get(CV_CAP_PROP_FRAME_WIDTH), cap.get(CV_CAP_PROP_FRAME_HEIGHT));
	
	writer = VideoWriter(filename, fcc, fps, frameSize);
	if(!writer.isOpened())
	{
		cout<<"ERROR OPENING FILE FOR WRITE";
		getchar();
		return -1;
	}

	while (1) {

		Mat frame;

		bool bSuccess = cap.read(frame); // read a new frame from camera feed

		if (!bSuccess) //test if frame successfully read
		{
			cout << "ERROR READING FRAME FROM CAMERA FEED" << endl;
			break;
		}

		writer.write(frame);
		
		putText(frame, "REC", Point(0,60), 2, 2, Scalar(0,0,255));
				
		imshow(windowName, frame); //show the frame in "MyVideo" window

		//listen for 10ms for a key to be pressed
		switch(waitKey(10)){

		case 27:
			//'esc' has been pressed (ASCII value for 'esc' is 27)
			//exit program.
			return 0;

		}


	}

	return 0;

}
