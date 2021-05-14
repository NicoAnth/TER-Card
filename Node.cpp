#include "Include/Node.hpp"
#include "Include/StakePool.hpp"
#include <QCryptographicHash>
#include <qdebug.h>

using namespace std;

int NodeClass::electSlotLeader(void)
{
  return 0;
}

bool NodeClass::slotLeaderVerification()
{
  QList<Transaction>::Iterator i;
  for(i=(ledger.begin()+ledger.size())-TRANSACTION_MAX; i != ledger.end(); ++i){
      if(!verifySignature(i->getSender(),*i,i->getSignature())){
        return false;
      }
  }
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
  QByteArray hash = computeLastBlockHash();
  std::string hashString = hash.toHex(0).toStdString();
  long long ll = std::stoll(hashString);
  return encrypt(ll,owner->publicKey,owner->getPrivateKey());
}