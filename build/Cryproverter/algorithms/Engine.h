#ifndef ENGINE_H
#define ENGINE_H

#include <QString>

class Engine
{
  public:
    Engine (QString n, bool key): name (n), hasPrivateKey (key) {}
    void setPrivateKey (const QString& key) {privateKey = key;}
    virtual bool encrypt (const char* input, char* output, size_t size) = 0;
    virtual bool decrypt (const char* input, char* output, size_t size) = 0;

    const QString name;
    const bool hasPrivateKey;
    QString privateKey;
};

#endif // ENGINE_H
