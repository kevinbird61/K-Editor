#-------------------------------------------------
#
# Project created by QtCreator 2016-06-30T12:23:10
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kedior
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    codeeditor.cpp \
    lexer.cpp \
    highlighter.cpp

HEADERS  += mainwindow.h \
    codeeditor.h \
    lexer.h \
    highlighter.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
