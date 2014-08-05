#ifndef IMAGESEGMENTATION_H
#define IMAGESEGMENTATION_H

#include <segment.h>
#include <colors.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>


class ImageSegmentation
{
public:
    ImageSegmentation(int step = 5);
public:
    void segmentation(cv::Mat matBinary, std::vector<Segment> &segments);
    void unionSegment(std::vector<Segment> &segments);
    void drawSegment(cv::Mat matOriginal, std::vector<Segment> segments, int thickness = 1);
    void setStep(int step);
private:
    int _step;
};

#endif // IMAGESEGMENTATION_H
