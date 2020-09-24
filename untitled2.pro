#-------------------------------------------------
#
# Project created by QtCreator 2018-12-15T22:23:28
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = untitled2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp \
    staticobject.cpp \
    movingobject.cpp \
    game.cpp \
    tank.cpp \
    brick.cpp \
    bullet.cpp \
    enemybullet.cpp \
    mybullet.cpp \
    mytank.cpp \
    goodtank.cpp \
    myfriendtank.cpp \
    badtank.cpp \
    enemysimple.cpp \
    lifes.cpp \
    bulletexplosion.cpp \
    tankexplosion.cpp \
    explosion.cpp \
    base.cpp \
    steelbrick.cpp \
    bonus.cpp \
    enemysimplefactory.cpp \
    menu.cpp \
    menupointer.cpp \
    level.cpp \
    gameoverlabel.cpp \
    scoretable.cpp \
    enemysign.cpp \
    eagle.cpp \
    enemyspeedy.cpp \
    enemyspeedyfactory.cpp

HEADERS += \
        widget.h \
    positional.h \
    staticobject.h \
    drawable.h \
    moveable.h \
    movingobject.h \
    game.h \
    tank.h \
    brick.h \
    bullet.h \
    destroyable.h \
    bulletfactory.h \
    enemybullet.h \
    mybullet.h \
    mytank.h \
    goodtank.h \
    myfriendtank.h \
    badtank.h \
    enemysimple.h \
    lifes.h \
    explosionalgorithm.h \
    bulletexplosion.h \
    tankexplosion.h \
    explosion.h \
    base.h \
    steelbrick.h \
    bonus.h \
    badtankfactory.h \
    enemysimplefactory.h \
    menu.h \
    menupointer.h \
    level.h \
    gameoverlabel.h \
    scoretable.h \
    enemysign.h \
    eagle.h \
    enemyspeedy.h \
    enemyspeedyfactory.h

FORMS += \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
