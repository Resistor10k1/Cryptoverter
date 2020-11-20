#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QFile>
#include <QStringList>
#include "algorithms/Engine.h"
#include "algorithms/LinearKeyShift.h"
#include "algorithms/SimpleDemo.h"

typedef enum {INPUT, OUTPUT} BufferType;

class Algorithm
{
  public:
    Algorithm (void);

    void setType (int index = 0);
    QString getName (void);
    QStringList getNameList (void);
    bool hasPrivateKey (void);
    void setPrivateKey (const QString& key);
    void load (const QString& input);                 // For text import
    void load (QFile& input);                         // For file import
    void save (QFile& output);                        // For file export
    QString showContent (BufferType type);            // Prepare selected buffer to print its content

    bool decrypt (void);
    bool encrypt (void);

  private:
    static const int typeCount = 2;                                                 // Set here total algorithm count
    Engine* engine [typeCount] = {new LinearKeyShift(), new SimpleDemo()};          // Add here more algorithms

    int selectedAlgorithm = 0;
    QByteArray inputBuffer, outputBuffer;
    const size_t displayContentLimit = 10000;         // Max number of characters printed in text fields
};

#endif // ALGORITHM_H
