#include "Algorithm.h"

Algorithm::Algorithm (void)
{
}

void Algorithm::setType (int index)
{
  if (index < 0 || index >= typeCount) return;
  selectedAlgorithm = index;
}

QString Algorithm::getName (void)
{
  return engine [selectedAlgorithm]->name;
}

QStringList Algorithm::getNameList (void)
{
  QStringList nameList;
  for (int i = 0; i < typeCount; i++)
  {
    nameList.append (engine [i]->name);
  }
  return nameList;
}

bool Algorithm::hasPrivateKey (void)
{
  return engine [selectedAlgorithm]->hasPrivateKey;
}

void Algorithm::setPrivateKey (const QString& key)
{
  engine [selectedAlgorithm]->setPrivateKey(key);
}

void Algorithm::load (void)
{
  inputBuffer.clear ();
  outputBuffer.clear ();
}

void Algorithm::load (const QString& input)
{
  inputBuffer.clear ();
  inputBuffer = input.toUtf8 ();
}

void Algorithm::load (QFile& input)
{
  inputBuffer.clear ();
  inputBuffer = input.readAll ();
}

void Algorithm::save (QFile& output)
{
  output.write (outputBuffer);
}

bool Algorithm::isPrintable (BufferType type)
{
  QByteArray& array = (type == INPUT) ? inputBuffer : outputBuffer;
  for (int i = 0; i < array.size (); i++)
  {
    QChar c = array.at (i);
    if (c.isNull ()) return true;
    if (!c.isSpace () && (c.isNonCharacter () || !c.isPrint ())) return false;
  }
  return true;
}

QString Algorithm::showContent (BufferType type)
{
  QByteArray limited = (type == INPUT) ? inputBuffer : outputBuffer;
  limited.resize (displayContentLimit);
  return QString::fromUtf8(limited);
}

QByteArray& Algorithm::getContent (BufferType type)
{
  return (type == INPUT) ? inputBuffer : outputBuffer;
}

bool Algorithm::convert (ConversationType type)
{
  if (type == DECRYPT)
  {
    outputBuffer.resize (engine [selectedAlgorithm]->getDecryptedSize (inputBuffer.size ()));
    return engine [selectedAlgorithm]->decrypt(inputBuffer.constData (), outputBuffer.data (), inputBuffer.size ());
  }
  else
  {
    outputBuffer.resize (engine [selectedAlgorithm]->getEncryptedSize (inputBuffer.size ()));
    return engine [selectedAlgorithm]->encrypt(inputBuffer.constData (), outputBuffer.data (), inputBuffer.size ());
  }
}
