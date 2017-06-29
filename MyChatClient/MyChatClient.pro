#-------------------------------------------------
#
# Project created by QtCreator 2017-06-13T15:00:06
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyChatClient
TEMPLATE = app


SOURCES += main.cpp\
        clientwidget.cpp \
    tcpclient.cpp \
    logindialog.cpp \
    signupdialog.cpp \
    common.cpp \
    tcpclientsocket.cpp \
    userclient.cpp \
    myfriendswidget.cpp

HEADERS  += clientwidget.h \
    tcpclient.h \
    logindialog.h \
    signupdialog.h \
    common.h \
    Constant.h \
    Database.h \
    tcpclientsocket.h \
    userclient.h \
    myfriendswidget.h

FORMS    += clientwidget.ui \
    tcpclient.ui \
    logindialog.ui \
    signupdialog.ui \
    myfriendswidget.ui

RESOURCES += \
    res.qrc
