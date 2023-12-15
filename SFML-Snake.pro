TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        food.cpp \
        main.cpp \
        mover.cpp

HEADERS += \
    food.h \
    mover.h



INCLUDEPATH += F:/Qt_workspace/SFML-2.6.1/SFML-2.6.1/include
DEPENDPATH += F:/Qt_workspace/SFML-2.6.1/SFML-2.6.1/build

unix|win32: LIBS += -LF:/Qt_workspace/SFML-2.6.1/SFML-2.6.1/build/lib/ -lsfml-system


unix|win32: LIBS += -LF:/Qt_workspace/SFML-2.6.1/SFML-2.6.1/build/lib/ -lsfml-graphics



unix|win32: LIBS += -LF:/Qt_workspace/SFML-2.6.1/SFML-2.6.1/build/lib/ -lsfml-window


