#-------------------------------------------------
#
# Project created by QtCreator 2011-04-03T21:14:01
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = structures
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \        
    List.cpp \
    StructExceptions.cpp \
    StudContainer.cpp \
    ArrayQueue.cpp \
    controller.cpp \
    Deque.cpp

HEADERS += \
    List.h \
    ArrayStack.h \
    StructExceptions.h \
    StudContainer.h \
    ArrayQueue.h \
    controller.h \
    Deque.h

OTHER_FILES += \
    students.txt \
    script.txt
