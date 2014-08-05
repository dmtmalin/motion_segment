#-------------------------------------------------
#
# Project created by QtCreator 2013-04-03T19:37:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DetectMotionSeg
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    simplebackgroundsubtract.cpp \
    showmatonqtlabel.cpp \
    segment.cpp \
    imagesegmentation.cpp \
    colors.cpp

HEADERS  += mainwindow.h \
    simplebackgroundsubtract.h \
    showmatonqtlabel.h \
    segment.h \
    imagesegmentation.h \
    colors.h

FORMS    += mainwindow.ui

INCLUDEPATH += C:/build_with_QT/Release/include

LIBS += -LC:/build_with_QT/Release/lib\
-lopencv_core244\
-lopencv_highgui244\
-lopencv_imgproc244\
