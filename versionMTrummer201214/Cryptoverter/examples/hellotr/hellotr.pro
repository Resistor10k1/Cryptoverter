SOURCES      = main.cpp
TRANSLATIONS = hellotr_la.ts

target.path = $$[QT_INSTALL_EXAMPLES]/linguist/hellotr
INSTALLS += target

QT += widgets

simulator: warning(This example might not fully work on Simulator platform)
