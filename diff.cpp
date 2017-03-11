#include <cv.h>
#include <highgui.h>
#include <iostream>

using namespace cv;
using namespace std;



Mat src; Mat src_gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);

void thresh_callback(int, void* )
{
	Mat threshold_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	/// Detect edges using Threshold
	threshold( src_gray, threshold_output, thresh, 255, THRESH_BINARY );
	/// Find contours
	findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

	/// Approximate contours to polygons + get bounding rects and circles
	vector<vector<Point> > contours_poly( contours.size() );
	vector<Rect> boundRect( contours.size() );
	vector<Point2f>center( contours.size() );
	vector<float>radius( contours.size() );

	for( int i = 0; i < contours.size(); i++ )
	{ approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
		boundRect[i] = boundingRect( Mat(contours_poly[i]) );
		minEnclosingCircle( (Mat)contours_poly[i], center[i], radius[i] );
	}


	/// Draw polygonal contour + bonding rects + circles
	Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
	for( int i = 0; i< contours.size(); i++ )
	{
		Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
		//drawContours( drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
		rectangle( drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );
	//	circle( drawing, center[i], (int)radius[i], color, 2, 8, 0 );
		cout<<"No: "<<contours.size()<<endl;
	}

	/// Show in a window
	namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
	imshow( "Contours", drawing );
}


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
	createTrackbar("Threshold Trackbar", "Window absDiffenrce", &threshValue, 255, thresh_callback);
	
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


		imshow("Window absDiffenrce", diffThreshold);
		imshow("Window Original", frame);
		prevFrameYUV = frameYUV.clone();
		src = diffThreshold.clone();	
		cvtColor(diffThreshold, src, CV_YUV2BGR);
		cvtColor(src, src_gray, CV_BGR2GRAY);
		thresh_callback(0,0);
	}

}
