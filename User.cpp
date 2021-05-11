#include "Include/User.hpp"
#include "Include/Transaction.hpp"

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

std::pair<long long,Transaction> User::sendTransaction(Transaction t){
  
  QString s = s.fromStdString(t.toString());
  QByteArray hash = QCryptographicHash::hash(s.toLocal8Bit(),QCryptographicHash::Sha256);
  long long signature = encrypt(hash.toLongLong(),publicKey,privateKey);
  return std::make_pair(signature,t);
}


