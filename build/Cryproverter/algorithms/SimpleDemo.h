#ifndef SIMPLEDEMO_H
#define SIMPLEDEMO_H

#include <QString>
#include <QChar>
#include "Engine.h"

class SimpleDemo : public Engine
{
  public:
    SimpleDemo (void) : Engine ("SimpleDemo", false) {}

    QString encrypt (const QString& input)
    {
      return input;
    }

    QString decrypt (const QString& input)
    {
      return input;
    }
};

#endif // SIMPLEDEMO_H
