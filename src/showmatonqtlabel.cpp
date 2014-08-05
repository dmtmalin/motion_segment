#include "showmatonqtlabel.h"

ShowMatOnQtLabel::ShowMatOnQtLabel()
{
}
void ShowMatOnQtLabel::imshow(cv::Mat mat, QLabel *label, int type){
    if(!mat.empty()){
        switch(type){
        case CV_GRAY2RGB:
            cv::cvtColor(mat, mat, CV_GRAY2RGB);
             break;
        case CV_BGR2RGB:
            cv::cvtColor(mat, mat, CV_BGR2RGB);
            break;
        }
        QImage qimg((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        label->setPixmap(QPixmap::fromImage(qimg));
    }
}
