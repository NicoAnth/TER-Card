#ifndef BLOCK_H
#define BLOCK_H
#include "Transaction.hpp"
#include <QByteArray>
#include <QList>
#define TRANSACTION_MAX 10

class Block {
public:
  
  static int count;
  const long long signature;
  const QByteArray hash_prev;
  const QByteArray hash_cur;
  const int id;

  QList<Transaction> trans;

  //Constructor
  Block(QByteArray hashPrev);

private:
  Transaction AddTransaction(Transaction t);
};
#endif