#-------------------------------------------------
#
# Project created by QtCreator 2013-03-16T11:56:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MapEditor
TEMPLATE = app


SOURCES += main.cpp \
    tilemap.cpp \
    Mapview.cpp \
    Element.cpp \
    Mainwindow.cpp \
    tile.cpp

HEADERS  += \
    tilemap.h \
    Mapview.h \
    Mainwindow.h \
    Element.h \
    tile.h

FORMS    += \
    mainwindow.ui

RESOURCES += \
    resource.qrc
win32:RC_FILE = ressource.rc
