#ifndef NODE_H
#define NODE_H
#include <QList>
#include <exception>
#include <QObject>
#include "Block.hpp"

#define TRANSACTION_MAX 3
#define MINIMAL_STAKE 10

class User;
class StakePool;

class NodeClass:public QObject {
    Q_OBJECT
private:

  const User* owner;
  const int minimalStake = MINIMAL_STAKE;
  int stake;
  static QList<Block*> blockChain;
  static QList <Transaction> ledger;
  bool online;
  bool isSlotLeader;

public:

  /* Constructor */
  NodeClass(User* m_owner,QList<Block*> &m_blockChain,QList <Transaction> m_ledger, int stake);

  /* Slot leader methods */
  NodeClass* electSlotLeader();
  bool createBlock();
  bool slotLeaderVerification();
  long long signBlock();  

  /* common methods */
  void execTransaction(User* sender, User* receiver, int amount, float fees);
  bool verifySignature(User* m_user,Transaction t, long long Hash);
  void receiveTransactionRequest(Transaction t);
  QByteArray computeLastBlockHash();

  /* getter */
  QList<Block*> &getBlockChain(){
    return blockChain;
  }
  QList <Transaction> getLedger(){
    return ledger;
  }
  /* setter */
  void setSlotLeader(bool sl){isSlotLeader = sl;}
};

#endif
