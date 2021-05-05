#include <memory>
#include <utility> 

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
    
    User();

    void generateMoney();
    std::tuple<long long, long long, long long> getPrivateKey();

  private:
    std::tuple<long long, long long, long long> privateKey;

};

inline bool operator <(const User &u, const User &u2){
  return u.useableStakes < u2.useableStakes;
}
