#include <QApplication>
#include "Cryptoverter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Cryptoverter cryptoverter;
    cryptoverter.show();
    return app.exec();
}

