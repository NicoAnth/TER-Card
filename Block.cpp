#include "Include/Block.hpp"
#include <QCryptographicHash>

int Block::count = 0;

Block::Block():signature(NULL){};

Block::Block(QByteArray hashPrev, long long slotLeaderSignature, QByteArray m_Hash,QList<Transaction> m_transactionList): id(count),signature(slotLeaderSignature),hash_prev(hashPrev),hash_cur(m_Hash), transactionList(m_transactionList){
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