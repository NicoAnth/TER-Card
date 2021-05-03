#include <memory>

class NodeClass;

class User {

public:

  int id;
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
};
