#-------------------------------------------------
#
# Project created by QtCreator 2018-04-02T23:03:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dati
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    welcome.cpp \
    setback.cpp \
    history.cpp \
    error.cpp \
    setting.cpp

HEADERS  += widget.h \
    welcome.h \
    setback.h \
    history.h \
    error.h \
    setting.h

FORMS    += \
    welcome.ui \
    setback.ui \
    history.ui \
    error.ui \
    widget.ui \
    setting.ui

RESOURCES +=
