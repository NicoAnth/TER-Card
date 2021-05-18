#include "Include/Block.hpp"
#include <QCryptographicHash>
#include <QPainter>
#include <QBrush>
#include <QPaintEvent>

int Block::count = 0;


Block::Block():signature(0){};

Block::Block(QByteArray hashPrev, long long slotLeaderSignature, QByteArray m_Hash,QList<Transaction> m_transactionList,int lastPosx, int lastPosy): signature(slotLeaderSignature),hash_prev(hashPrev), transactionList(m_transactionList),id(count),hash_cur(m_Hash),lastBlockPosx(lastPosx),lastBlockPosy(lastPosy){
    count += 1;
    positionx = lastBlockPosx + 150;
    positiony = lastBlockPosy;
    QPaintEvent a(QRect(10,50,800,200));
    paintEvent(&a);

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

int Block::getPositionx(){
    return positionx;
}

int Block::getPositiony(){
    return positiony;
}

void Block::paintEvent(QPaintEvent *){
    QPainter p(this);
    QPen pen;
    p.setBrush(Qt::blue);
    p.drawRect(QRect(positionx,positiony,100,100));
    p.drawLine(QLine(lastBlockPosx+100,lastBlockPosy+50,positionx,positiony+50));
}