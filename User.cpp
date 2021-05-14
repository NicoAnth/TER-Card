#include "Include/User.hpp"
#include "Include/Transaction.hpp"
#include <bits/stdc++.h>
#include <QByteArray>
#include <qdebug.h>

int User::count = 0;

User::User()
{
  id = count;
  totalStakes = 1;
  useableStakes = 1;
  pooledStakes = 1;
  createKeys(publicKey,privateKey);
  connectedNode = NULL;
  count++;
};

User::~User(){
  count--;
}

const std::tuple<long long, long long, long long> User::getPrivateKey() const {
  return privateKey;
}

Transaction User::createTransaction(User& m_receiver, int m_amount){

  Transaction t(*this,m_receiver,m_amount);
  QString s = s.fromStdString(t.toString());
  QByteArray hash = QCryptographicHash::hash(s.toLocal8Bit(),QCryptographicHash::Sha256);
  qDebug()<< hash.toHex();
  std::string hashString = hash.toHex(0).toStdString();
  long long ll = std::stoll(hashString);
  long long signature = encrypt(ll,publicKey,privateKey);
  t.setSignature(signature);
  return t;
}


