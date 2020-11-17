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

QString Algorithm::decrypt (const QString& input)
{
  return engine [selectedAlgorithm]->decrypt(input);
}

QString Algorithm::encrypt (const QString& input)
{
  return engine [selectedAlgorithm]->encrypt(input);
}
