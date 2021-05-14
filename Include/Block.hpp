#ifndef BLOCK_H
#define BLOCK_H
#include "Transaction.hpp"
#include <QByteArray>
#include <QList>
#include <QString>

class Block {

protected:
  
  static int count;
  int id;
  const long long signature;
  QByteArray hash_prev;
  QByteArray hash_cur;

  QList<Transaction> transactionList;


public:

  //Constructor
  Block();
  Block(QByteArray hashPrev,long long slotLeaderSignature, QByteArray m_Hash,QList<Transaction> m_transactionList);
  
  /* getter */
  QList<Transaction> const getTransactionList();
  QByteArray getHash();
  QString toString();

  Transaction AddTransaction(Transaction t);

};
#endif