#-------------------------------------------------
#
# Project created by QtCreator 2014-05-27T07:30:50
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Receiver
TEMPLATE = app


SOURCES += main.cpp\
        Dialog.cpp

HEADERS  += Dialog.h \
    Receiver.h \
    PortError.h

FORMS    += Dialog.ui
