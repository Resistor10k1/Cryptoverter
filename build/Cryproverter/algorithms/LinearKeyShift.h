#ifndef LINEARKEYSHIFT_H
#define LINEARKEYSHIFT_H

#include <QString>
#include <QChar>
#include "Engine.h"

class LinearKeyShift : public Engine
{
  public:
    LinearKeyShift (void) : Engine ("LinearKeyShift", true) {}

    QString encrypt (const QString& input)
    {
      QString output;
      for (int i = 0; i < input.length (); i++)
      {
        QChar qchar (input [i]);
        char character = qchar.toLatin1();
        if (character >= 'A' && character <= 'Z')
        {
          character += getKeyShift (privateKey);
          if (character < 'A' || character > 'Z') character -= 26;
        }
        if (character >= 'a' && character <= 'z')
        {
          character += getKeyShift (privateKey);
          if (character < 'a' || character > 'z') character -= 26;
        }
        output[i] = character;
      }
      return output;
    }

    QString decrypt (const QString& input)
    {
      QString output;
      for (int i = 0; i < input.length (); i++)
      {
        QChar qchar (input [i]);
        char character = qchar.toLatin1();
        if (character >= 'A' && character <= 'Z')
        {
          character -= getKeyShift (privateKey);
          if (character < 'A' || character > 'Z') character += 26;
        }
        if (character >= 'a' && character <= 'z')
        {
          character -= getKeyShift (privateKey);
          if (character < 'a' || character > 'z') character += 26;
        }
        output[i] = character;
      }
      return output;
    }

private:
  int getKeyShift (const QString& key)
  {
    int shift = 0;
    for (int i = 0; i < key.length (); i++)
    {
      QChar qchar (key [i]);
      shift += qchar.toLatin1() * (i + 1) * (i + 1);
    }
    return shift % 26;
  }
};

#endif // LINEARKEYSHIFT_H
