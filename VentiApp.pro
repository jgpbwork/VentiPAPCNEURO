QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainmenu.cpp \
    mainscreen.cpp \
    mainwindow.cpp \
    mylabelanimated.cpp \
    mywidgetanimated.cpp \
    optiondatetime.cpp \
    optioncalibration.cpp \
    globalfunctions.cpp \
    optionalarmlimit.cpp \
    optiongeneral.cpp \
    DrvI2C.cpp \
    DrvAdc.cpp \
    IEEE754.cpp \
    DrvGauge.cpp \
    DrvGpio.cpp \
    DrvRtc.cpp \
    ThrInput.cpp \
    Time.cpp \
    optionsetdate.cpp \
    optionsettime.cpp \
    processesclass.cpp \
    ThrAlarm.cpp

HEADERS += \
    mainmenu.h \
    mainscreen.h \
    mainwindow.h \
    mylabelanimated.h \
    mywidgetanimated.h \
    optiondatetime.h \
    optioncalibration.h \
    globalfunctions.h \
    optionalarmlimit.h \
    optiongeneral.h \
    DrvI2C.h \
    DrvAdc.h \
    IEEE754.h \
    DrvGauge.h \
    DrvGpio.h \
    DrvRtc.h \
    GMacros.h \
    Singleton.h \
    QMath.h \
    ThrInput.h \
    Time.h \
    optionsetdate.h \
    optionsettime.h \
    processesclass.h \
    ThrAlarm.h

FORMS += \
    mainmenu.ui \
    mainscreen.ui \
    mainwindow.ui \
    optiondatetime.ui \
    optioncalibration.ui \
    optionalarmlimit.ui \
    optiongeneral.ui \
    optionsetdate.ui \
    optionsettime.ui \
    optionsetdate.ui \
    optionsettime.ui

LIBS += -L/usr/local/include -lwiringPi \
        -L/usr/local/lib -lpigpiod_if2 #To include libpigpiod_if2.so from /usr/local/lib


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc

DISTFILES +=
