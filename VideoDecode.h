#include "stdafx.h"
#include "opencv2/opencv.hpp"

using namespace cv;

int main(int argc, char**argv)
{
    VideoCapture capture(argv[1]);
    
    if (!capture.isOpened()) {
        return -1;
    }
	double fps = 30;
	if (argc > 1) {
		fps = atoi(argv[2]);
	}
    
    int numberOfFrames = capture.get(CV_CAP_PROP_FRAME_COUNT);
    printf("There are %d frames\n", numberOfFrames);
    
    namedWindow("Video",1);
 
	
	double width = capture.get(CV_CAP_PROP_FRAME_WIDTH);
	double height = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
	printf("fps:%f width:%f height:%f\n", fps, width, height);
	waitKey(0);

	FILE *fp = fopen("./seq/rgb.txt", "w");

    for (int i=0; i<numberOfFrames; i++) {
        
        Mat org_frame;
        // set the new position (this doesn't have be done here. if omitted, if
        //  just reads sequentially, but i added it here just to remember how it
        //  is done.
       // capture.set(CV_CAP_PROP_POS_FRAMES, (double)i);
        
        // grab a new frame
        capture >> org_frame;

		//double ts = capture.get(CV_CAP_PROP_POS_MSEC);

		double secs =	i * 1.0f / fps;


		std::cout << secs << std::endl;

		char fn[100];
		memset(fn, 0, sizeof(fn));
		sprintf(fn, "./seq/rgb/%f.png", secs);

		Mat frame;
		cv::resize(org_frame, frame, cv::Size(640,480));

		
		cv::imwrite(fn, frame);

		fprintf(fp, "%f rgb/%f.png\n", secs, secs);

        imshow("Video", frame);
        
        if (waitKey(5) >= 0) {
          break;
        }
    }

	fclose(fp);

    return 0;
    
} // end main
