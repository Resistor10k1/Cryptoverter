QT += widgets uitools

HEADERS = Cryptoverter.h \
  Algorithm.h \
  algorithms/AES.h \
  algorithms/CaesarEncryption.h \
  algorithms/Engine.h \
  algorithms/LinearKeyShift.h \
  algorithms/SHA256.h \
  algorithms/SimpleDemo.h

SOURCES = Cryptoverter.cpp main.cpp \
  Algorithm.cpp \
  algorithms/AES.cpp \
  algorithms/CaesarEncryption.cpp

RESOURCES =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    Cryptoverter.ui

DISTFILES +=

