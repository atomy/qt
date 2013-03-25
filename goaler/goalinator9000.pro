#-------------------------------------------------
#
# Project created by QtCreator 2013-03-25T15:56:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = goalinator9000
TEMPLATE = app


SOURCES += main.cpp\
    GoalApp.cpp \
    GoalRenderer.cpp \
    GoalContainer.cpp \
    widget.cpp \
    GoalElement.cpp \
    GoalFactory.cpp

HEADERS  += \
    GoalApp.h \
    GoalRenderer.h \
    GoalContainer.h \
    widget.h \
    GoalElement.h \
    GoalFactory.h

FORMS    += \
    widget.ui
