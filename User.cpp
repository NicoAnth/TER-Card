#include "Include/User.hpp"
#include "Include/Transaction.hpp"
#include "Include/GenesisBlock.hpp"
#include "Include/StakePool.hpp"
#include <bits/stdc++.h>
#include <QByteArray>
#include <qdebug.h>
#include <QPainter>

class requireEnoughUseableStake: public std::exception{
  virtual const char* what() const throw()
  {
    return "The user doesn't have enough useable stake to perform this operation";
  }
}reus;

int User::count = 0;

User::User(GenesisBlock& geblock)
{
  id = count;
  totalStakes = 0;
  useableStakes = 0;
  pooledStakes = 0;
  createKeys(publicKey,privateKey);
  geblock.addPublicKey(publicKey);
  connectedNode = NULL;
  setCursor(Qt::PointingHandCursor);
  count++;
};

User::~User(){}

const std::tuple<long long, long long, long long> User::getPrivateKey() const {
  return privateKey;
}

void User::addUseableStakes(float addus){
  useableStakes += addus;
}
void User::addtotalStakes(float addts){
  totalStakes += addts;
}

Transaction User::createTransaction(User* m_receiver, int m_amount){

  Transaction t(this,m_receiver,m_amount);
  QString s = s.fromStdString(t.toString());
  QByteArray hash = QCryptographicHash::hash(s.toLocal8Bit(),QCryptographicHash::Sha256);
  qDebug()<< hash.toHex();
  std::string hashString = hash.toHex(0).toStdString();
  long long ll = hashtoll(hashString);
  long long signature = encrypt(ll,publicKey,privateKey);
  t.setSignature(signature);
  return t;
}

NodeClass* User::createNode(NodeClass onlineNode, int stake){
  
  try{
    if(stake<useableStakes){
      throw reus; 
    }
  }
  catch(exception &e){
    cout << e.what() << '\n';
  }
  NodeClass* node = new NodeClass(this,onlineNode.getBlockChain(),onlineNode.getLedger(),stake);
  connectedNode = node;
  return node;
}

void User::joinStakePool(StakePool& sp, int stake){
  
  try{
    if(stake<useableStakes){
      throw reus; 
    }
  }
  catch(exception &e){
    cout << e.what() << '\n';
  }
  connectedPool = &sp;
  sp.addUser(this,stake);
}

long long hashtoll(std::string hash){

  std::string sResult = "";

  for(std::string::iterator it = hash.begin();it!=hash.end();++it){
    if(*it>47 && *it<58){
      sResult += *it;    
    }
  }
  return std::stoll(sResult.substr(sResult.size()-5));
}

void User::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setBrush(Qt::red);
    painter.drawRect(QRect(0,0,30,30));
    painter.drawText(QRect(10,10,30,30),"U");
}
