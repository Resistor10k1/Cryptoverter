#include <QApplication>
#include "Cryptoverter.h"

int main(int argc, char *argv[])
{
    //Q_INIT_RESOURCE(calculatorbuilder);

    QApplication app(argc, argv);
    Cryptoverter cryptoverter;
    cryptoverter.show();
    return app.exec();
}

