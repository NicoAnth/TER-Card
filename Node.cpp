#include "Include/Node.hpp"
#include "Include/StakePool.hpp"
#include "Include/GenesisBlock.hpp"
#include "Include/BlockchainDraw.hpp"
#include "Include/mainwindow.h"
#include <stdlib.h> 
#include <time.h>
#include <QCryptographicHash>
#include <qdebug.h>
#include <QPainter>
#include <QMenu>
#include <QPushButton>
#include <QFormLayout>
#include <QSpinBox>

using namespace std;

class requireMinimalStake: public std::exception{
  virtual const char* what() const throw()
  {
    return "The minimal stake is not respected, cannot create a new node";
    
  }
}rms;

QList <Transaction> ledg;
QList <Block*> *init_blockChain;
QList <Block*>* NodeClass::blockChain = init_blockChain;
QList <Transaction> NodeClass::ledger = ledg;

NodeClass::NodeClass(User* m_owner,QList<Block*> *m_blockChain,QList <Transaction> m_ledger, float m_stake,QMainWindow* mw):owner(m_owner),m_mw(mw){
  
  try{
    if(m_stake < MINIMAL_STAKE){
      throw rms;
    }
  }
  catch (exception& e)
  {
    cout << e.what() << '\n';
  }
  blockChain = m_blockChain;
  ledger= m_ledger;
  GenesisBlock& geBlock = dynamic_cast<GenesisBlock&> (*blockChain->first());
  geBlock.addStaker(this,m_stake);
  stake = m_stake;
  online = true;
  isSlotLeader = false;
  setCursor(Qt::PointingHandCursor);
  setContextMenuPolicy(Qt::CustomContextMenu);
  setMouseTracking(true);
  setMaximumSize(30,30);
  setToolTip(getInfos()); 
  update();
  connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), 
        this, SLOT(ShowContextMenu(const QPoint &)));
  
}

NodeClass* NodeClass::electSlotLeader()
{
  GenesisBlock& geBlock = dynamic_cast<GenesisBlock&> (*blockChain->first());
  QListIterator<std::pair<NodeClass*,float>> i(geBlock.getStakers());
  float sum=0;

  srand (time(NULL));

  float totalStake=0;
  while(i.hasNext()){
    totalStake += i.next().second;
  }

  int nextSlotLeader = rand() % (static_cast<int>(totalStake) + 1 - 0) + 0;

  i.toFront();
  while(i.hasNext())
  { 
    std::pair<NodeClass*,float> next = i.next();
    sum += next.second;
    if(nextSlotLeader < sum ){
      this->isSlotLeader = false;
      next.first->isSlotLeader = true;
      //Tool tip settings
      next.first->setToolTip(next.first->getInfos());
      next.first->repaint();
      update();
      setToolTip(getInfos());
      return next.first;
    }
  }
  return this;
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
      if(i->getSender()->useableStakes < i->getAmount()){
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
      float totalFees=0;
      for(i=(ledger.begin()+ledger.size())-TRANSACTION_MAX;i!= ledger.end();++i){
        execTransaction(i->getSender(),i->getReceiver(),i->getAmount(),i->getFees());
        blockTransaction.append(*i);
        totalFees += i->getFees();
      }
        Block* newBlock = new Block((*blockChain->last()).getHash(),signBlock(),computeLastBlockHash(),blockTransaction,
        (*blockChain->last()).getPositionx(),(*blockChain->last()).getPositiony(),((MainWindow*)m_mw)->blockchainDraw);
        blockChain->append(newBlock);
        stake += totalFees;
        setToolTip(getInfos());
        electSlotLeader();
        ((MainWindow*)m_mw)->blockchainDraw->repaint();
        return true;
    }
    else{
      qDebug()<<"Node not allow to perform such operation or unvalid block";
      electSlotLeader();
      return false;
    }
}

void NodeClass::execTransaction(User* sender, User* receiver, int amount, float fees)
{
  sender->useableStakes -= amount+fees;
  sender->totalStakes -= amount+fees;
  receiver->useableStakes += amount;
  receiver->totalStakes += amount;
  sender->setToolTip(sender->getInfos());
  receiver->setToolTip(receiver->getInfos());
}

bool NodeClass::verifySignature( User* m_user,Transaction t, long long encryptedHash){

  QString s = s.fromStdString(t.toString());
  QByteArray hash = QCryptographicHash::hash(s.toLocal8Bit(),QCryptographicHash::Sha256);
  std::string hashString = hash.toHex(0).toStdString();
  long long ll = hashtoll(hashString);
  long long decryptedHash = decrypt(encryptedHash,m_user->publicKey);
  
  return ll == decryptedHash; 
}

QByteArray NodeClass::computeLastBlockHash(){
    
    QString transactionSeed;

    //Compute ledger Hash
    QList<Transaction>::iterator i;
    for(i=(ledger.begin()+ledger.size())-TRANSACTION_MAX;i!= ledger.end();++i){
        transactionSeed += transactionSeed.fromStdString(i->toString());
    }
    return QCryptographicHash::hash(transactionSeed.toLocal8Bit(),QCryptographicHash::Sha256);

}

long long NodeClass::signBlock(){

  if(isSlotLeader){
  QByteArray hash = computeLastBlockHash();
  std::string hashString = hash.toHex(0).toStdString();
  long long ll = hashtoll(hashString);
    return encrypt(ll,owner->publicKey,owner->getPrivateKey());
  }
  else qDebug()<< "The node must be the slot leader to sign a block";
  return -1;
}

void NodeClass::receiveTransactionRequest(Transaction t){
    ledger.append(t);
    
}
void NodeClass::addStake(float nStake){
  stake +=nStake;
}

QString NodeClass::getInfos(){
  QString infos="";
  infos += "Stake: " + QString::number(stake) + "\n";
  if(online){
    infos += "En ligne: oui \n";
  }
  else infos += "En ligne: non \n";

  if(isSlotLeader){
    infos += "Slot Leader: oui \n";
  }
  else infos += "Slot Leader: non \n";
  
  return infos;
}

void NodeClass::paintEvent(QPaintEvent *){
  QPainter painter(this);
  QPen pen;
  pen.setColor(Qt::black);
  if(isSlotLeader){
    painter.setBrush(QColor(255,195,51));
  }
  else painter.setBrush(QColor(153,50,255));
  painter.drawRect(QRect(0,0,30,30));
  painter.setPen(pen);
  painter.drawText(QRect(10,8,30,30),"N");
}

void NodeClass::ShowContextMenu(const QPoint &pos){

  QMenu contextMenu(tr("Context menu"), this);
  if(isSlotLeader){
  QAction action1("Créer un bloc", this);
  connect(&action1, SIGNAL(triggered()), this, SLOT(createBlock()));
  contextMenu.addAction(&action1);

  contextMenu.exec(mapToGlobal(pos));
  }


}