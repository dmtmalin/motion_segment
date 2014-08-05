#ifndef SEGMENT_H
#define SEGMENT_H

#include <opencv2/core/core.hpp>

class Segment
{
public:
    Segment(cv::Point point, int area, int id = -1);
public:    
    void getPoint(cv::Point &outPoint);
    void getAreaMax(cv::Point &outPoint);
    void getAreaMin(cv::Point &outPoint);

    void setId(int id);
    void getId(int &outId);   
private:
    cv::Point _point, _pointMax, _pointMin;
    int _area, _id;
};

#endif // SEGMENT_H
