#include <cv.h>
#include <highgui.h>
//#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <iostream>
using namespace cv;

int main( int argc, char** argv )
{
	char* imageName = argv[1];

	Mat image;
	image = imread( imageName, 1 );
#if 0
	if(image.empty())
	{
		std::cout << "ERROR : Image cannot be loaded..!!" << std::endl;
		return -1;
	}
#endif
	if( argc != 2 || !image.data )
	{
		printf( " No image data \n " );
		return -1;
	}

	Mat gray_image;
	cvtColor( image, gray_image, CV_BGR2GRAY );

	imwrite( "./Gray_Image.jpg", gray_image );

	namedWindow( "Gray image", CV_WINDOW_AUTOSIZE );

	imshow( "Gray image", gray_image );

	waitKey(0);

	destroyWindow("Gray image");
	return 0;
}

