#-------------------------------------------------
#
# Project created by QtCreator 2017-06-13T15:23:28
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyChatServer
TEMPLATE = app


SOURCES += main.cpp\
        serverwidget.cpp \
    tcpserver.cpp \
    common.cpp \
    userserver.cpp \
    userclient.cpp \
    database.cpp \
    tcpclientsocket.cpp

HEADERS  += serverwidget.h \
    tcpserver.h \
    common.h \
    userserver.h \
    userclient.h \
    constant.h \
    database.h \
    tcpclientsocket.h

FORMS    += serverwidget.ui
