#-------------------------------------------------
#
# Project created by QtCreator 2021-12-07T14:12:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 1BankATMS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    Graph.cpp \
    transfer.cpp \
    register.cpp \
    dwrecords.cpp \
    user.cpp \
    select.cpp \
    trie.cpp \
    deposit.cpp \
    getmoney.cpp \
    check.cpp \
    dwrui.cpp \
    admin.cpp \
    qsort.cpp \
    tfrui.cpp

HEADERS += \
        mainwindow.h \
    Graph.h \
    transfer.h \
    register.h \
    dwrecords.h \
    user.h \
    select.h \
    trie.h \
    deposit.h \
    getmoney.h \
    check.h \
    dwrui.h \
    admin.h \
    qsort.h \
    tfrui.h

FORMS += \
        mainwindow.ui \
    transfer.ui \
    register.ui \
    select.ui \
    deposit.ui \
    getmoney.ui \
    check.ui \
    dwrui.ui \
    admin.ui \
    tfrui.ui

