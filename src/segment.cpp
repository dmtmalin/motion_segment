#include "segment.h"

Segment::Segment(cv::Point point, int area, int id)
{
    _point = point;
    _area = area;
    _id = id;

    _pointMax = cv::Point(point.x + area, point.y + area);
    _pointMin = cv::Point(point.x - area, point.y - area);
}

void Segment::getPoint(cv::Point &outPoint){
    outPoint = _point;
}

void Segment::getAreaMax(cv::Point &outPoint){
    outPoint = _pointMax;
}

void Segment::getAreaMin(cv::Point &outPoint){
    outPoint = _pointMin;
}

void Segment::setId(int id){
    _id = id;
}

void Segment::getId(int &outId){
    outId = _id;
}
