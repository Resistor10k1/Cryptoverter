#ifndef ENGINE_H
#define ENGINE_H

#include <QString>

class Engine
{
  public:
    Engine (QString n, bool key): name (n), hasPrivateKey (key) {}
    void setPrivateKey (const QString& key) {privateKey = key;}
    virtual QString encrypt (const QString& input) = 0;
    virtual QString decrypt (const QString& input) = 0;

    const QString name;
    const bool hasPrivateKey;
    QString privateKey;
};

#endif // ENGINE_H
