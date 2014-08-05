#include "colors.h"

Colors::Colors()
{    
}

cv::Scalar Colors::get(unsigned int id){
    srand(id);
    while(id >= colors.size()){
        colors.push_back(cv::Scalar(rand()%255, rand()%255, rand()%255));
    }
    return colors.at(id);
}
