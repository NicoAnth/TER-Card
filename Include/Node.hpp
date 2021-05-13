#ifndef NODE_H
#define NODE_H
#include <QList>
#include "Chain.hpp"


class User;
class StakePool;

class NodeClass {
public:

  const User* Owner;
  QList<Chain> chain;
  QList <Transaction> ledger;
  bool online;
  bool isSlotLeader;

  int electSlotLeader(void);

  Block createBlock(int Uid);

  Block createBlock(StakePool& SP);

  void execTransaction(User sender, User receiver, int amount);
  bool verifySignature(User m_user,Transaction t, long long Hash);
  //Node();
};
#endif