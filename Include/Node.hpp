#include <list>
#include "Chain.hpp"
#include "StakePool.hpp"

//I still can't believe I lost 2 hours because Node was already taken and my compilo didn't say anything
class NodeClass {
public:
  std::list<User> users;
  std::list<Chain> chain;
  static std::list<int> bufferTransactions;

  int electSlotLeader(void);

  Block createBlock(int Uid);

  Block createBlock(StakePool SP);

  void execTransaction(User sender, User receiver, int amount);
};
