#ifndef COLORS_H
#define COLORS_H

#include <opencv2/core/core.hpp>
#include <stdlib.h>

class Colors
{
public:
    Colors();
public:
    cv::Scalar get(unsigned int id);
private:
    std::vector<cv::Scalar> colors;
};

#endif // COLORS_H
