TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    facet.cpp \
    process.cpp \
    parse.cpp \
    vector.cpp

HEADERS += \
    facet.h \
    process.h \
    parse.h \
    vector.h
