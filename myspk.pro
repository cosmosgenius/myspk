TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
TARGET = spk

SOURCES += main.c

CONFIG(release, debug|release): DESTDIR = $$OUT_PWD/release
CONFIG(debug, debug|release): DESTDIR = $$OUT_PWD/debug

SDL2_MINGW_ROOT=D:\Dev\libs\mingw\sdl2\x86_64-w64-mingw32
SDL2_MSVC_ROOT=D:\Dev\libs\msvc\sdl2

win32-g*{
    message("Compiler is mingw")
    LIBS += -L$$SDL2_MINGW_ROOT/lib -lmingw32
    INCLUDEPATH += $$SDL2_MINGW_ROOT/include/SDL2
    DEPENDPATH += $$SDL2_MINGW_ROOT/include/SDL2
}

win32-msvc*{
    message("Compiler is Visual Studio")
    LIBS += -L$$SDL2_MSVC_ROOT/lib/x86/
    INCLUDEPATH += $$SDL2_MSVC_ROOT/include
    DEPENDPATH += $$SDL2_MSVC_ROOT/include
}

LIBS += -lsdl2main -lsdl2
