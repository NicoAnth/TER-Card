#ifndef NODE_H
#define NODE_H
#include <QList>
#include "Chain.hpp"

#define TRANSACTION_MAX 3

class User;
class StakePool;

class NodeClass {
private:

  const User* owner;
  QList<Block> blockChain;
  QList <Transaction> ledger;
  bool online;
  bool isSlotLeader;

public:

  /* Constructor */
  NodeClass(User* m_owner,QList<Block> m_blockChain,QList <Transaction> m_ledger);

  /* Slot leader methods */
  NodeClass electSlotLeader();
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