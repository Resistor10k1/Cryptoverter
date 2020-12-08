#ifndef ENGINE_H
#define ENGINE_H

#include <QString>

class Engine
{
  public:
    Engine (QString n, bool key): name (n), hasPrivateKey (key) {}
    void setPrivateKey (const QString& key) {privateKey = key;}
    virtual int getEncryptedSize (int inputSize) {return inputSize;}
    virtual int getDecryptedSize (int inputSize) {return inputSize;}
    virtual bool encrypt (const char* input, char* output, size_t size) = 0;
    virtual bool decrypt (const char* input, char* output, size_t size) = 0;

    QString name;
    QString privateKey;
    const bool hasPrivateKey;
};

#endif // ENGINE_H
