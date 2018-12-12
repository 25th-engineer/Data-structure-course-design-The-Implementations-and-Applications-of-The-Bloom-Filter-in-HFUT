#-------------------------------------------------
#
# Project created by QtCreator 2018-08-19T20:05:57
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = TangTang
TEMPLATE = app
#DEFINES += NOMINMAX  self added
#RC_FILE = rc/DFZ.jpg self added

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    myhighlight.cpp \
    bloomfilter.cpp

HEADERS += \
        mainwindow.h \
    bloomfilter.h \
    myhighlight.h

FORMS += \
        mainwindow.ui

contains(QMAKE_TARGET.arch, x86_64) {
    TYPE = 64
    QTDIR = C:/Qt/5.5/msvc2013_64
} else {
    TYPE = 32
    QTDIR = C:/Qt/5.5/msvc2013
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
