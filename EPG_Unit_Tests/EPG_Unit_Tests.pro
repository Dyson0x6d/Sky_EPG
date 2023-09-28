QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../SkyEpgApp/

SOURCES +=  tst_rewards_service.cpp \
    ../SkyEpgApp/ChannelObject.cpp \
    ../SkyEpgApp/EligibilityServiceStubObject.cpp \
    ../SkyEpgApp/RewardsEntryItem.cpp \
    ../SkyEpgApp/RewardsServiceObject.cpp \
    ../SkyEpgApp/UserObject.cpp

HEADERS += \
    ../SkyEpgApp/ChannelObject.h \
    ../SkyEpgApp/EligibilityServiceStubObject.h \
    ../SkyEpgApp/EpgAppTypes.h \
    ../SkyEpgApp/RewardsEntryItem.h \
    ../SkyEpgApp/RewardsServiceObject.h \
    ../SkyEpgApp/UserObject.h
