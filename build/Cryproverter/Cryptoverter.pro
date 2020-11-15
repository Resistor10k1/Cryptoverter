QT += widgets uitools

HEADERS = Cryptoverter.h \

SOURCES = Cryptoverter.cpp main.cpp \

RESOURCES =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    Cryptoverter.ui

