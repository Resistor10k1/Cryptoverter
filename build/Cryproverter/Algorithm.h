#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QFile>
#include <QChar>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include "algorithms/Engine.h"
#include "algorithms/LinearKeyShift.h"
#include "algorithms/SimpleDemo.h"
#include "algorithms/CaesarEncryption.h"
#include "algorithms/AES.h"

typedef enum {INPUT, OUTPUT} BufferType;
typedef enum {DECRYPT, ENCRYPT} ConversationType;

class Algorithm
{
  public:
    Algorithm (void);

    void setType (int index = 0);
    QString getName (void);
    QStringList getNameList (void);
    bool hasPrivateKey (void);
    void setPrivateKey (const QString& key);
    void load (void);                                 // For clearing input
    void load (const QString& input);                 // For text import
    void load (QFile& input);                         // For file import
    void save (QFile& output);                        // For file export
    bool isPrintable (BufferType type);               // Shows if selected buffer has pintable characters
    QString showContent (BufferType type);            // Prepare selected buffer to print its content
    QByteArray& getContent (BufferType type);         // Get access to selected buffer for data inspection
    bool convert (ConversationType type);

  private:
    static const int typeCount = 6;                   // Set here total algorithm count and add them in following array
    Engine* engine [typeCount] = {new AES(128),
                                  new AES(192),
                                  new AES(256),
                                  new CaesarEncryption(),
                                  new LinearKeyShift(),
                                  new SimpleDemo()};

    int selectedAlgorithm = 0;
    QByteArray inputBuffer, outputBuffer;
    const size_t displayContentLimit = 10000;         // Max number of characters printed in text fields
};

#endif // ALGORITHM_H
