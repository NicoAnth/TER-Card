#ifndef BLOCK_H
#define BLOCK_H
#include "Transaction.hpp"
#include <QByteArray>
#include <QList>
#include <QString>

class Block {

private:
  const long long signature;
  QByteArray hash_prev;
  QList<Transaction> transactionList;

protected:
  
  int id;
  static int count;
  QByteArray hash_cur;

public:

  //Constructor
  Block();
  Block(QByteArray hashPrev,long long slotLeaderSignature, QByteArray m_Hash,QList<Transaction> m_transactionList);
  virtual ~Block(){};
  /* getter */
  QList<Transaction> const getTransactionList();
  QByteArray getHash();
  QString toString();

  Transaction AddTransaction(Transaction t);

};
#endif