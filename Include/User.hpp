#ifndef USER_H
#define USER_H
#include <memory>
#include <utility> 
#include "Node.hpp"
#include "Transaction.hpp"
#include "Rsa.h"
#include <QCryptographicHash>

class GenesisBlock;
class StakePool;
class NodeClass;

class User {

  public:

    static int count;
    int id;
    std::pair<long long, long long> publicKey;
    float totalStakes;
    float useableStakes;
    float pooledStakes;
    NodeClass* connectedNode;
    StakePool* connectedPool;

    //Constructor
    User(GenesisBlock& geBlock);
    ~User();
    
    std::tuple<long long, long long, long long> const getPrivateKey() const;
    Transaction createTransaction(User* m_receiver, int m_amount);
    NodeClass createNode(NodeClass onlineNode, int amount);
    void joinStakePool(StakePool& sp, int stake);
    void addUseableStakes(float addus);
    void addtotalStakes(float addts);


  private:
   std::tuple<long long, long long, long long> privateKey;

};

inline bool operator <(const User &u, const User &u2){
  return u.useableStakes < u2.useableStakes;
}
long long hashtoll(std::string hash);
#endif
