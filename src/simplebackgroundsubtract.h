#ifndef SIMPLEBACKGROUNDSUBTRACT_H
#define SIMPLEBACKGROUNDSUBTRACT_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class SimpleBackgroundSubtract
{
public:
    SimpleBackgroundSubtract();
private:
    cv::Mat matInput, matBackground, matSubtraction, matBinary;
public:
    void subtraction(cv::Mat _matInput);
    void rebuildBackground();
    void getMatSubtractionBinary(cv::Mat &outMat, int threshold = 1);
};

#endif // SIMPLEBACKGROUNDSUBTRACT_H
