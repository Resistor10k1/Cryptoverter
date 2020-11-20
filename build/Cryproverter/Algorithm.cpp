#include "Algorithm.h"
#include <QTextStream>    // For debugging

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

void Algorithm::load (const QString& input)
{
  inputBuffer.clear ();
  inputBuffer = input.toUtf8 ();

  QTextStream(stdout) << "Imported String" << endl;

  //QTextStream(stdout) << "import String: " << input << endl;
  //QTextStream(stdout) << "   results is: " << inputBuffer << endl;
}

void Algorithm::load (QFile& input)
{
  inputBuffer.clear ();
  inputBuffer = input.readAll ();

  QTextStream(stdout) << "Imported File" << endl;

  //QTextStream(stdout) << "  results is: " << inputBuffer << endl;
}

void Algorithm::save (QFile& output)
{
  output.write (outputBuffer);
}

QString Algorithm::showContent (BufferType type)
{
  QByteArray limited = (type == INPUT) ? inputBuffer : outputBuffer;
  limited.resize (displayContentLimit);
  return QString::fromUtf8(limited);
}

bool Algorithm::decrypt (void)
{
  outputBuffer.resize (inputBuffer.size ());
  return engine [selectedAlgorithm]->decrypt(inputBuffer.constData (), outputBuffer.data (), inputBuffer.size ());
}

bool Algorithm::encrypt (void)
{
  outputBuffer.resize (inputBuffer.size ());
  return engine [selectedAlgorithm]->encrypt(inputBuffer.constData (), outputBuffer.data (), inputBuffer.size ());
}
