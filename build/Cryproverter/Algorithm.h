#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QStringList>
#include "algorithms/Engine.h"
#include "algorithms/SimpleDemo.h"
#include "algorithms/SimpleTest.h"

class Algorithm
{
  public:
    Algorithm (void);

    void setType (int index = 0);
    QString getName (void);
    QStringList getNameList (void);
    bool hasPrivateKey (void);


  private:
    Engine engine [2] = {SimpleDemo(), SimpleTest()};           // Add here more algorithms
    const int typeCount = sizeof (engine) / sizeof (Engine);

    int selectedAlgorithm = 0;
};

#endif // ALGORITHM_H
