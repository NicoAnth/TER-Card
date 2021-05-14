#include "Include/Block.hpp"
#include <QCryptographicHash>

int Block::count = 0;

Block::Block():signature(0){};

Block::Block(QByteArray hashPrev, long long slotLeaderSignature, QByteArray m_Hash,QList<Transaction> m_transactionList): signature(slotLeaderSignature),hash_prev(hashPrev), transactionList(m_transactionList),id(count),hash_cur(m_Hash){
    count += 1;
}

Transaction Block::AddTransaction(Transaction t){
    
    this->transactionList.append(t);
    return t;
}

QList<Transaction> const Block::getTransactionList(){
    return transactionList;
}

QByteArray Block::getHash(){
    return hash_cur;
}

QString Block::toString(){
    QString string;
    QList<Transaction>::Iterator i;
    for(i=(transactionList.begin()+transactionList.size())-3; i != transactionList.end(); ++i){
      string += string.fromStdString(i->toString());
    }
    return string;
}