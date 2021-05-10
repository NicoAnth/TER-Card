#ifndef BLOCK_H
#define BLOCK_H
#include "Transaction.hpp"
#include <QList>

class Block {
public:
  long int signature;
  int hash_prev;
  int hash_cur;
  int id;

  QList<Transaction> trans;
  //pointeur vers le bloc suivant ?

  //Pour le debug
  Block() : id(-99){}

private:
  Transaction AddTransaction(Transaction t);
};
#endif