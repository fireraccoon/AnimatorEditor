#-------------------------------------------------
#
# Project created by QtCreator 2015-07-05T00:00:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AnimatorEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    editorscene.cpp \
    stateitem.cpp \
    newparamdialog.cpp \
    animator.cpp \
    state.cpp \
    parameter.cpp \
    transition.cpp \
    condition.cpp

HEADERS  += mainwindow.h \
    editorscene.h \
    stateitem.h \
    newparamdialog.h \
    animator.h \
    state.h \
    parameter.h \
    transition.h \
    condition.h

RESOURCES = qdarkstyle/style.qrc \
    res/res.qrc

FORMS    += mainwindow.ui \
    newparameterdialog.ui



