#-------------------------------------------------
#
# Project created by QtCreator 2014-03-31T10:32:22
#
#-------------------------------------------------
# Harold Garbeil 
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QuikServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mytcpserver.cpp

HEADERS  += mainwindow.h \
    mytcpserver.h

FORMS    += mainwindow.ui
