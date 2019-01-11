TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    source/main.cpp \
    source/application.cpp \
    source/resourcemanager.cpp

INCLUDEPATH += SFML-2.5.1\include
DEPENDPATH += SFML-2.5.1\include

INCLUDEPATH += include

LIBS += -Llibs

CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-system-d -lsfml-network-d -lsfml-main-d -lsfml-window-d -lsfml-graphics-d
CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-system -lsfml-network -lsfml-main -lsfml-window -lsfml-graphics

HEADERS += \
    include/application.h \
    include/constants.h \
    include/resourcemanager.h
