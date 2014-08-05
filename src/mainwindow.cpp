#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#define TIMER_INTERVAL 20

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    

    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));

    connect(ui->actionStart, SIGNAL(triggered()),this, SLOT(menuStart_click()));
    connect(ui->actionStop, SIGNAL(triggered()), this, SLOT(menuStop_click()));
    connect(ui->btnRebuild, SIGNAL(clicked()),this, SLOT(btnRebuild_click()));
}

void MainWindow::btnRebuild_click(){

    bg.rebuildBackground();
}

void MainWindow::menuStart_click(){

    webCam.open(0);

    if(!webCam.isOpened()){
        showMessageBox("camera is not available, application will close!");
        return;
    }

    timer->start(TIMER_INTERVAL);
}

void MainWindow::menuStop_click(){

    webCam.release();

    timer->stop();
}

void MainWindow::processFrameAndUpdateGUI(){

    webCam.read(matInput);
    if(matInput.empty()){
        return;
    }
    matOriginal = matInput.clone();
    bg.subtraction(matInput);    
    bg.getMatSubtractionBinary(matBinary, ui->sliderThresh->value());

    std::vector<Segment> *segments = new std::vector<Segment>();
    iseg.setStep(ui->sliderSegment->value());
    iseg.segmentation(matBinary, *segments);
    iseg.unionSegment(*segments);
    iseg.drawSegment(matOriginal, *segments);
    if(segments){
        delete segments;
    }

    ShowMatOnQtLabel::imshow(matBinary, ui->labelImage, CV_GRAY2RGB);
    ShowMatOnQtLabel::imshow(matOriginal, ui->labelImage2, CV_BGR2RGB);


}

void MainWindow::showMessageBox(const QString &text){
    QMessageBox *box = new QMessageBox();
    box->setText(text);
    box->exec();
    if(box){
        delete box;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}
