#include "Include/Block.hpp"

Transaction Block::AddTransaction(Transaction t){
    this->trans.append(t);
    return t;
}