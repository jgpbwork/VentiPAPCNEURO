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
    sources \ aboutscreen.cpp \
    sources \ main.cpp \
    sources \ mainmenu.cpp \
    sources \ mainscreen.cpp \
    sources \ mainwindow.cpp \
    sources \ mylabelanimated.cpp \
    sources \ mywidgetanimated.cpp \
    sources \ optiondatetime.cpp \
    sources \ optioncalibration.cpp \
    sources \ globalfunctions.cpp \
    sources \ optionalarmlimit.cpp \
    sources \ optiongeneral.cpp \
    sources \ DrvI2C.cpp \
    sources \ DrvAdc.cpp \
    sources \ IEEE754.cpp \
    sources \ DrvGauge.cpp \
    sources \ DrvGpio.cpp \
    sources \ DrvRtc.cpp \
    sources \ ThrInput.cpp \
    sources \ Time.cpp \
    sources \ optionsetdate.cpp \
    sources \ optionsettime.cpp \
    sources \ processesclass.cpp \
    sources \ ThrAlarm.cpp \
    sources \ customeventfilter.cpp

HEADERS += \
    headers \ aboutscreen.h \
    headers \ mainmenu.h \
    headers \ mainscreen.h \
    headers \ mainwindow.h \
    headers \ mylabelanimated.h \
    headers \ mywidgetanimated.h \
    headers \ optiondatetime.h \
    headers \ optioncalibration.h \
    headers \ globalfunctions.h \
    headers \ optionalarmlimit.h \
    headers \ optiongeneral.h \
    headers \ DrvI2C.h \
    headers \ DrvAdc.h \
    headers \ IEEE754.h \
    headers \ DrvGauge.h \
    headers \ DrvGpio.h \
    headers \ DrvRtc.h \
    headers \ GMacros.h \
    headers \ Singleton.h \
    headers \ QMath.h \
    headers \ ThrInput.h \
    headers \ Time.h \
    headers \ optionsetdate.h \
    headers \ optionsettime.h \
    headers \ processesclass.h \
    headers \ ThrAlarm.h \
    headers \ customeventfilter.h

FORMS += \
    forms \ aboutscreen.ui \
    forms \ mainmenu.ui \
    forms \ mainscreen.ui \
    forms \ mainwindow.ui \
    forms \ optiondatetime.ui \
    forms \ optioncalibration.ui \
    forms \ optionalarmlimit.ui \
    forms \ optiongeneral.ui \
    forms \ optionsetdate.ui \
    forms \ optionsettime.ui \
    forms \ optionsetdate.ui \
    forms \ optionsettime.ui

LIBS += -L/usr/local/include -lwiringPi \
        -L/usr/local/lib -lpigpiod_if2 #To include libpigpiod_if2.so from /usr/local/lib


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc

DISTFILES +=
