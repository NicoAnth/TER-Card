#ifndef Us
#define Us
#include "Include/User.hpp"
#endif

User::User()
{
  id = -1;
  totalStakes = -1;
  useableStakes = -1;
  pooledStakes = -1;
  //publicKey = std::make_pair();
  connectedNode = NULL;
};

std::tuple<long long, long long, long long> User::getPrivateKey(){
  return privateKey;
}

