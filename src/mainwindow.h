#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <simplebackgroundsubtract.h>
#include <imagesegmentation.h>
#include <segment.h>
#include <showmatonqtlabel.h>

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QTimer *timer;
    SimpleBackgroundSubtract bg;
    ImageSegmentation iseg;
    cv::VideoCapture webCam;
    cv::Mat matInput, matBinary, matOriginal;

    void showMessageBox(const QString &text);

private slots:
    void processFrameAndUpdateGUI();
    void btnRebuild_click();
    void menuStart_click();
    void menuStop_click();

};

#endif // MAINWINDOW_H
