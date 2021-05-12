#include "Include/User.hpp"
#include "Include/Transaction.hpp"
#include <bits/stdc++.h>
#include <QByteArray>
#include <qdebug.h>

User::User()
{
  id = 1;
  totalStakes = 1;
  useableStakes = 1;
  pooledStakes = 1;
  createKeys(publicKey,privateKey);
  connectedNode = NULL;
};

std::tuple<long long, long long, long long> User::getPrivateKey(){
  return privateKey;
}

std::pair<Transaction,long long> User::sendTransaction(Transaction t){

  QString s = s.fromStdString(t.toString());
  QByteArray hash = QCryptographicHash::hash(s.toLocal8Bit(),QCryptographicHash::Sha256);
  qDebug()<< hash.toHex();
  std::string hashString = hash.toHex(0).toStdString();
  long long ll = std::stoll(hashString);
  long long signature = encrypt(ll,publicKey,privateKey);
  return std::make_pair(t,signature);
}


