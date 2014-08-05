#include "imagesegmentation.h"

ImageSegmentation::ImageSegmentation(int step)
{
    _step = step;
}

void ImageSegmentation::segmentation(cv::Mat matBinary, std::vector<Segment> &segments){
    cv::Mat matArea;
    for(int y(0); y < matBinary.rows; y = y + _step){
        for(int x(0); x < matBinary.cols; x = x + _step){
            if(matBinary.at<unsigned char>(y, x) == 255){
                if(y + _step < matBinary.rows && x + _step < matBinary.cols){
                    matArea = matBinary(cv::Rect(x, y, _step, _step));
                }
                int emptyPoints(0);
                for(int yy(0); yy < matArea.rows; yy++){
                    for(int xx(0); xx < matArea.cols; xx++){
                        if(matArea.at<unsigned char>(yy, xx) == 0){
                            emptyPoints++;
                        }
                    }
                }
                if(emptyPoints < 0.5*_step*_step){
                    Segment segment(cv::Point(x, y), (_step * 3));
                    segments.push_back(segment);
                }
            }
        }
    }
}

void ImageSegmentation::unionSegment(std::vector<Segment> &segments){
    int id = -1;
    int exsistsId = -1;
    cv::Point currPoint, prevPoint, borderMax, borderMin;
    for(unsigned int i(0); i < segments.size(); i++){
        segments.at(i).getPoint(currPoint);
        bool isIdSet = false;
        for(int prev_i(i - 1); prev_i > -1; prev_i--){
            segments.at(prev_i).getPoint(prevPoint);
            segments.at(prev_i).getAreaMax(borderMax);
            segments.at(prev_i).getAreaMin(borderMin);
            if((currPoint.x <= borderMax.x && currPoint.x >= borderMin.x) &&
                    (currPoint.y <= borderMax.y && currPoint.y >= borderMin.y)){
                segments.at(prev_i).getId(exsistsId);
                segments.at(i).setId(exsistsId);
                isIdSet = true;
            }
        }
        if(!isIdSet){
           id++;
           segments.at(i).setId(id);
        }
    }
}

void ImageSegmentation::drawSegment(cv::Mat matOriginal, std::vector<Segment> segments, int thickness){
    cv::Point point;
    Colors colors;
    int id;
    for(unsigned int i(0); i < segments.size(); i++){
        segments.at(i).getId(id);
        segments.at(i).getPoint(point);
        cv::rectangle(matOriginal, cv::Rect(point.x, point.y, _step, _step), colors.get((unsigned int)id), thickness);
    }
}

void ImageSegmentation::setStep(int step){
    _step = step;
}
