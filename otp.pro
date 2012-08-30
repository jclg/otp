#-------------------------------------------------
#
# Project created by QtCreator 2012-08-28T12:40:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = otp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    otp.cpp \
    base64.cpp \
    helper.cpp \
    displaykeydialog.cpp

HEADERS  += mainwindow.h \
    otp.h \
    base64.h \
    helper.h \
    displaykeydialog.h

FORMS    += mainwindow.ui \
    displaykeydialog.ui

RESOURCES += \
    otp.qrc
