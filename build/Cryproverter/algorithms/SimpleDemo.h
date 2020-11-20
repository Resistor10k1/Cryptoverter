#ifndef SIMPLEDEMO_H
#define SIMPLEDEMO_H

#include <QString>
#include <QChar>
#include "Engine.h"

class SimpleDemo : public Engine
{
  public:
    SimpleDemo (void) : Engine ("SimpleDemo", false) {}

    bool encrypt (const char* input, char* output, size_t size)
    {
      memcpy (output, input, size);
      return true; // Success
    }

    bool decrypt (const char* input, char* output, size_t size)
    {
      memcpy (output, input, size);
      return true; // Success
    }
};

#endif // SIMPLEDEMO_H
