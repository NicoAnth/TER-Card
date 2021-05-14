#ifndef NODE_H
#define NODE_H
#include <QList>
#include "Chain.hpp"

#define TRANSACTION_MAX 3

class User;
class StakePool;

class NodeClass {
public:

  const User* owner;
  QList<Block> blockChain;
  QList <Transaction> ledger;
  bool online;
  bool isSlotLeader;

  /* Slot leader methods */
  int electSlotLeader(void);
  bool createBlock();
  bool slotLeaderVerification();
  long long signBlock();  

  /* common methods */
  void execTransaction(User sender, User receiver, int amount);
  bool verifySignature(User m_user,Transaction t, long long Hash);
  QByteArray computeLastBlockHash();
  //Node()
};
#endif