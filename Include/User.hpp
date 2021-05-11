#ifndef USER_H
#define USER_H
#include <memory>
#include <utility> 
#include "Node.hpp"
#include "Transaction.hpp"
#include "Rsa.h"
#include <QCryptographicHash>

class NodeClass;

class User {

  public:

    int id;
    std::pair<long long, long long> publicKey;
    int totalStakes;
    int useableStakes;
    int pooledStakes;

    // And we finally start with our dubious hacks !
    // We're stuck in an include loop and a simple forward definition doesn't cut it
    // So we need to make it a pointer
    // Either that or we use a unique_ptr but I'll go with a friendly yet firm "No"
    NodeClass* connectedNode;
    
    //Constructor
    User();
    
    std::tuple<long long, long long, long long> getPrivateKey();
    std::pair<long long,Transaction> sendTransaction(Transaction t);

  private:
    std::tuple<long long, long long, long long> privateKey;

};

inline bool operator <(const User &u, const User &u2){
  return u.useableStakes < u2.useableStakes;
}
#endif
