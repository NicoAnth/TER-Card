#ifndef NODE_H
#define NODE_H
#include <QList>
#include "Chain.hpp"

class StakePool;
//I still can't believe I lost 2 hours because Node was already taken and my compilo didn't say anything
class NodeClass {
public:

  QList<User> users;
  QList<Chain> chain;
  static QList<int> bufferTransactions;

  int electSlotLeader(void);

  Block createBlock(int Uid);

  Block createBlock(StakePool& SP);

  void execTransaction(User sender, User receiver, int amount);
  
  //Node();
};
#endif