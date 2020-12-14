include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread

HEADERS += \
        ../../Cryproverter/algorithms/AES.h \
        ../../Cryproverter/algorithms/CaesarEncryption.h \
        ../../Cryproverter/algorithms/Engine.h \
        ../../Cryproverter/algorithms/LinearKeyShift.h \
        ../../Cryproverter/algorithms/SHA256.h \
        ../../Cryproverter/algorithms/SimpleDemo.h \
        tst_testencryption.h

SOURCES += \
        ../../Cryproverter/algorithms/AES.cpp \
        ../../Cryproverter/algorithms/CaesarEncryption.cpp \
        main.cpp

INCLUDEPATH += \
        ../../Cryproverter/algorithms

