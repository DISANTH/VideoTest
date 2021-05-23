#include "opencv2/opencv.hpp"
#include <iostream>
#include <ctime>
#include <cstdio>
#include <time.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int main() {

    //////////////////// Added Part
    time_t start, end;
    //////////////////// Added Part
    VideoCapture vcap("/dev/video2");
    if (!vcap.isOpened()) {
        cout << "Error opening video stream or file" << endl;
        return -1;
    }
    int frame_width = vcap.get(CV_CAP_PROP_FRAME_WIDTH);
    int frame_height = vcap.get(CV_CAP_PROP_FRAME_HEIGHT);
    VideoWriter video("/home/testVideo.avi", CV_FOURCC('M', 'J', 'P', 'G'), 10, Size(frame_width, frame_height), true);

    //////////////////// Added Part
    time(&start);
    //////////////////// Added Part

    for (;;) {

        Mat frame;
        vcap >> frame;
        video.write(frame);
        imshow("Frame", frame);
        char c = (char)waitKey(33);
        if (c == 27) break;

        //////////////////// Added Part
        time(&end);
        double dif = difftime(end, start);
        printf("Elasped time is %.2lf seconds.", dif);
        if (dif==10)
        {
            std::cout << "DONE Video File Saved at /home/testVideo.avi" << dif<< std::endl;
            break;
        }
        //////////////////// Added Part
    }
    return 0;
}
