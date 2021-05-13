#include "Include/Block.hpp"


/* Block::Block(QByteArray hashPrev):hash_prev(hashPrev){
    
} */
Transaction Block::AddTransaction(Transaction t){
    
    this->trans.append(t);
    return t;
}