#-------------------------------------------------
#
# Project created by QtCreator 2016-05-27T02:00:13
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    savefile.cpp \
    qruntimeerror.cpp

HEADERS  += mainwindow.h \
    savefile.h \
    qruntimeerror.h

FORMS    += mainwindow.ui
