#include "simplebackgroundsubtract.h"

SimpleBackgroundSubtract::SimpleBackgroundSubtract()
{
}

void SimpleBackgroundSubtract::subtraction(cv::Mat _matInput){
    if(_matInput.empty()){
        return;
    }
    cv::cvtColor(_matInput, _matInput, CV_RGB2GRAY);

    matInput = _matInput;

    if(matBackground.empty()){
        matBackground = _matInput;
    }
    cv::absdiff(matInput, matBackground, matSubtraction);
}

void SimpleBackgroundSubtract::rebuildBackground(){
    if(!matInput.empty()){
        matBackground = matInput;
    }
}

void SimpleBackgroundSubtract::getMatSubtractionBinary(cv::Mat &outMat, int threshold){
    if(!matSubtraction.empty()){              
        cv::threshold(matSubtraction, outMat, threshold, 255, CV_THRESH_BINARY);
    }
}
