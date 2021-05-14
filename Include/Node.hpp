#ifndef NODE_H
#define NODE_H
#include <QList>
#include <exception>
#include "Block.hpp"

#define TRANSACTION_MAX 3
#define MINIMAL_STAKE 10

class User;
class StakePool;

class NodeClass {
private:

  const User* owner;
  const int minimalStake = MINIMAL_STAKE;
  int stake;
  QList<Block> blockChain;
  QList <Transaction> ledger;
  bool online;
  bool isSlotLeader;

public:

  /* Constructor */
  NodeClass(User* m_owner,QList<Block> m_blockChain,QList <Transaction> m_ledger, int stake);

  /* Slot leader methods */
  NodeClass electSlotLeader();
  bool createBlock();
  bool slotLeaderVerification();
  long long signBlock();  

  /* common methods */
  void execTransaction(User sender, User receiver, int amount);
  bool verifySignature(User m_user,Transaction t, long long Hash);
  QByteArray computeLastBlockHash();

  /* getter */
  QList<Block> getBlockChain(){
    return blockChain;
  }
  QList <Transaction> getLedger(){
    return ledger;
  }
};

#endif