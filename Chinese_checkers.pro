QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



RC_FILE += ./info.rc




SOURCES += \
    AI.cpp \
    all_settings.cpp \
    board.cpp \
    c_room.cpp \
    connect.cpp \
    last_step.cpp \
    main.cpp \
    marble.cpp \
    music.cpp \
    networkdata.cpp \
    networkserver.cpp \
    networksocket.cpp \
    player.cpp \
    rank.cpp \
    room_1.cpp \
    rooms.cpp \
    server.cpp \
    settings.cpp \
    startpage.cpp \
    widget.cpp

HEADERS += \
    AI.h \
    all_settings.h \
    board.h \
    c_room.h \
    connect.h \
    last_step.h \
    marble.h \
    music.h \
    networkdata.h \
    networkserver.h \
    networksocket.h \
    player.h \
    rank.h \
    room_1.h \
    rooms.h \
    server.h \
    settings.h \
    startpage.h \
    widget.h

FORMS += \
    all_settings.ui \
    c_room.ui \
    connect.ui \
    last_step.ui \
    rank.ui \
    room_1.ui \
    rooms.ui \
    server.ui \
    startpage.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc \
    music.qrc
