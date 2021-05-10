#ifndef Us
#define Us
#include "Include/User.hpp"
#endif

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
  SHA256 sha;
  std::string hash = sha(t.toString());
  long long ll = std::stoll(hash);
  long long signature = encrypt(ll,publicKey,privateKey);
  return make_pair(signature,t);
}


