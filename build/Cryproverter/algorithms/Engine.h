#ifndef ENGINE_H
#define ENGINE_H

#include <QString>

class Engine
{
  public:
    Engine (QString n, bool key): name (n), hasPrivateKey (key) {}

    const QString name;
    const bool hasPrivateKey;
  private:

};

#endif // ENGINE_H
