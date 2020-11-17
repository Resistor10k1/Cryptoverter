#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QStringList>
#include "algorithms/Engine.h"
#include "algorithms/LinearKeyShift.h"
#include "algorithms/SimpleDemo.h"

class Algorithm
{
  public:
    Algorithm (void);

    void setType (int index = 0);
    QString getName (void);
    QStringList getNameList (void);
    bool hasPrivateKey (void);
    void setPrivateKey (const QString& key);

    QString decrypt (const QString& input);
    QString encrypt (const QString& input);

  private:
    static const int typeCount = 2;                                                 // Set here total algorithms count
    Engine* engine [typeCount] = {new LinearKeyShift(), new SimpleDemo()};          // Add here more algorithms

    int selectedAlgorithm = 0;
};

#endif // ALGORITHM_H
