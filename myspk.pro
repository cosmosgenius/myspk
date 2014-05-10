QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myspk
TEMPLATE = app


SOURCES += main.cpp\
        myspkmain.cpp \
    palayer.cpp

HEADERS  += myspkmain.h \
    palayer.h

FORMS    += myspkmain.ui

win32-g++: LIBS += -L$$PWD/pa/mingw/ -lportaudio -lwinmm -lm -lole32 -luuid
win32-msvc*: LIBS += -L$$PWD/pa/msvc/x86/ -lportaudio_static -ladvapi32

INCLUDEPATH += $$PWD/pa/include
DEPENDPATH += $$PWD/pa/include

PRE_TARGETDEPS += $$PWD/pa/mingw/libportaudio.a
