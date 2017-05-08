#-------------------------------------------------
#
# Project created by QtCreator 2017-04-03T11:03:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MQTTClient
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


SOURCES += main.cpp\
        window.cpp \
    publish.cpp \
    #client.cpp \
    subscribe.cpp \
    brokerstatus.cpp \
    utils.cpp \
    mosquittoapi.cpp \
    element.cpp \
    list.cpp \
    savetoformat.cpp \
    txt.cpp \
    #apisingleton.cpp
    loglist.cpp \
    log.cpp

HEADERS  += window.h \
    publish.h \
    #client.h \
    subscribe.h \
    brokerstatus.h \
    mosquittoapi.h \
    element.h \
    list.h \
    savetoformat.h \
    txt.h \
    #apisingleton.h
    loglist.h \
    log.h \
    date.h

FORMS    += window.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/local/Cellar/mosquitto/1.4.11/lib/release/ -lmosquitto.1.4.11
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/local/Cellar/mosquitto/1.4.11/lib/debug/ -lmosquitto.1.4.11
else:unix: LIBS += -L$$PWD/../../../../usr/local/Cellar/mosquitto/1.4.11/lib/ -lmosquitto.1.4.11

INCLUDEPATH += $$PWD/../../../../usr/local/Cellar/mosquitto/1.4.11/include
DEPENDPATH += $$PWD/../../../../usr/local/Cellar/mosquitto/1.4.11/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/local/Cellar/mosquitto/1.4.11/lib/release/ -lmosquittopp.1.4.11
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/local/Cellar/mosquitto/1.4.11/lib/debug/ -lmosquittopp.1.4.11
else:unix: LIBS += -L$$PWD/../../../../usr/local/Cellar/mosquitto/1.4.11/lib/ -lmosquittopp.1.4.11

INCLUDEPATH += $$PWD/../../../../usr/local/Cellar/mosquitto/1.4.11/include
DEPENDPATH += $$PWD/../../../../usr/local/Cellar/mosquitto/1.4.11/include

