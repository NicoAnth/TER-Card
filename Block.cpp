#include "Include/Block.hpp"
#include <QCryptographicHash>
#include <QPainter>
#include <QBrush>
#include <QPaintEvent>
#include <QSize>
#include <QTextCodec>
#include <qdebug.h>

int Block::count = 0;


Block::Block():signature(0){};

Block::Block(QByteArray hashPrev, long long slotLeaderSignature, QByteArray m_Hash,QList<Transaction> m_transactionList,int lastPosx, int lastPosy,QWidget *parent): signature(slotLeaderSignature),hash_prev(hashPrev), transactionList(m_transactionList),id(count),hash_cur(m_Hash),lastBlockPosx(lastPosx),lastBlockPosy(lastPosy), QWidget(parent){

    positionx = lastBlockPosx + 150;
    positiony = lastBlockPosy;
    setCursor(Qt::PointingHandCursor);
    setMinimumSize(100,100);
    setGeometry(positionx,0,100,100);
    setToolTip(getInfos());
    setVisible(true);
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

int Block::getPositionx(){
    return positionx;
}

int Block::getPositiony(){
    return positiony;
}

QString Block::getInfos(){
  QString infos="";
  infos += "Signature du slot leader: " + QString::number(signature) + "\n";
  
  infos += "Hash:"+ hash_cur.toHex() +"\n";
  infos += "Hash du bloc précédent:"+ hash_prev.toHex() +"\n";
  
  return infos;
}

