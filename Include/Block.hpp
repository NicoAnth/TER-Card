#include "Transaction.hpp"

class Block {
public:
  long int signature;
  int hash_prev;
  int hash_cur;
  int id;

  std::list<Transaction> trans;
  //pointeur vers le bloc suivant ?

  //Pour le debug
  Block() : id(-99){}

private:
  Transaction AddTransaction(Transaction t);
};
