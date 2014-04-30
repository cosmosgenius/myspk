TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
TARGET = spk

SOURCES += main.c


PORTAUDIO_MINGW_ROOT=D:\Dev\libs\mingw\portaudio
PORTAUDIO_MSVC_ROOT=D:\Dev\libs\mingw\portaudio

win32-g*{
    message("Compiler is mingw")
    LIBS += -L$$PORTAUDIO_MINGW_ROOT/lib -lmingw32
    INCLUDEPATH += $$PORTAUDIO_MINGW_ROOT/include
    DEPENDPATH += $$PORTAUDIO_MINGW_ROOT/include
}

win32-msvc*{
    message("Compiler is Visual Studio")
    LIBS += -L$$PORTAUDIO_MSVC_ROOT/lib/x86/
    INCLUDEPATH += $$PORTAUDIO_MSVC_ROOT/include
    DEPENDPATH += $$PORTAUDIO_MSVC_ROOT/include
}

LIBS += -lportaudio
