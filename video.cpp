#include <cv.h>
#include <highgui.h>

using namespace std;
using namespace cv;

int main()
{
	Mat image;
	VideoCapture cap;
	cap.open(0);
	namedWindow("window1", 1);

	while(1)
	{
		cap>>image;
		imshow("window1", image);
		waitKey(33);
	}



}
