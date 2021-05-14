#include "Include/Node.hpp"
#include "Include/StakePool.hpp"
#include "Include/GenesisBlock.hpp"
#include <stdlib.h> 
#include <time.h>
#include <QCryptographicHash>
#include <qdebug.h>

using namespace std;


NodeClass::NodeClass(User* m_owner,QList<Block> m_blockChain,QList <Transaction> m_ledger):owner(m_owner),blockChain(m_blockChain),ledger(m_ledger){
  online = true;
  isSlotLeader = false;
}

NodeClass NodeClass::electSlotLeader()
{
  GenesisBlock& geBlock = dynamic_cast<GenesisBlock&> (blockChain.first());
  QMapIterator<NodeClass, int> i(geBlock.getStakers());
  int sum=0;

  srand (time(NULL));

  int totalStake;
  while(i.hasNext()){
    i.next();
    totalStake += i.value();
  }

  int nextSlotLeader = rand()%1+totalStake;

  i.toFront();
  while(i.hasNext())
  { 
    i.next();
    sum += i.value();
    if(nextSlotLeader < sum ){
      return i.key();
    }
  }

}

bool NodeClass::slotLeaderVerification()
{
  if(isSlotLeader){
    QList<Transaction>::Iterator i;
    for(i=(ledger.begin()+ledger.size())-TRANSACTION_MAX; i != ledger.end(); ++i){
        if(!verifySignature(i->getSender(),*i,i->getSignature())){
          qDebug()<< "Slot leader returned : Wrong Signature";
           return false;
        }
        if(i->getSender().useableStakes < i->getAmount()){
          qDebug()<< "Slot leader returned: User doesn't own enough money to perform this transaction";
          return false;
        }
    }
  }
  else qDebug()<< "Must be the slot leader";

  return true;
}

bool NodeClass::createBlock(){

    if(isSlotLeader == true && slotLeaderVerification()){
      QList<Transaction> blockTransaction;
      QList<Transaction>::iterator i;
      for(i=(ledger.begin()+ledger.size())-10;i!= ledger.end();++i){
        blockTransaction.append(*i);
      }
        Block newBlock(blockChain.last().getHash(),signBlock(),computeLastBlockHash(),blockTransaction);
        blockChain.append(newBlock);
        return true;
    }
    else{
      qDebug()<<"Node not allow to perform such operation or unvalid block";
      return false;
    }
}

void NodeClass::execTransaction(User sender, User receiver, int amount)
{
  sender.useableStakes -= amount;
  receiver.useableStakes += amount;
}

bool NodeClass::verifySignature( User m_user,Transaction t, long long encryptedHash){

  QString s = s.fromStdString(t.toString());
  QByteArray hash = QCryptographicHash::hash(s.toLocal8Bit(),QCryptographicHash::Sha256);
  std::string hashString = hash.toHex(0).toStdString();
  long long ll = std::stoll(hashString);
  long long decryptedHash = decrypt(encryptedHash,m_user.publicKey);
  
  return ll == decryptedHash; 
}

QByteArray NodeClass::computeLastBlockHash(){
    
    QString transactionSeed;

    //Compute ledger Hash
    QList<Transaction>::iterator i;
    for(i=(ledger.begin()+ledger.size())-10;i!= ledger.end();++i){
        transactionSeed += transactionSeed.fromStdString(i->toString());
    }
    return QCryptographicHash::hash(transactionSeed.toLocal8Bit(),QCryptographicHash::Sha256);

}

long long NodeClass::signBlock(){

  if(isSlotLeader){
  QByteArray hash = computeLastBlockHash();
  std::string hashString = hash.toHex(0).toStdString();
  long long ll = std::stoll(hashString);
  return encrypt(ll,owner->publicKey,owner->getPrivateKey());
  }
  else qDebug()<< "Must be the slot leader";
}