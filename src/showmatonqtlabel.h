#ifndef SHOWMATONQTLABEL_H
#define SHOWMATONQTLABEL_H

#include <QLabel>

#include <opencv2/imgproc/imgproc.hpp>

class ShowMatOnQtLabel
{
public:
    ShowMatOnQtLabel();
public:
    static void imshow(cv::Mat mat, QLabel *label, int type);

};

#endif // SHOWMATONQTLABEL_H
