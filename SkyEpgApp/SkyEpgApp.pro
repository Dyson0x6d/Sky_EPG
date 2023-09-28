QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ChannelObject.cpp \
    EligibilityServiceStubObject.cpp \
    RewardsEntryItem.cpp \
    RewardsServiceObject.cpp \
    UserObject.cpp \
    main.cpp

TRANSLATIONS += \
    SkyEpgApp_en_GB.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ChannelObject.h \
    EligibilityServiceStubObject.h \
    EpgAppTypes.h \
    RewardsEntryItem.h \
    RewardsServiceObject.h \
    UserObject.h
