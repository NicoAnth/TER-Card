#include "Include/User.hpp"
#include "Include/Transaction.hpp"
#include "Include/GenesisBlock.hpp"
#include "Include/StakePool.hpp"
#include "Include/Simulation.hpp"
#include <bits/stdc++.h>
#include <QByteArray>
#include <qdebug.h>
#include <QPainter>
#include <QMenu>
#include <QPushButton>
#include <QFormLayout>
#include <QSpinBox>
#include <QDialog>

class requireEnoughUseableStake: public std::exception{
  virtual const char* what() const throw()
  {
    return "The user doesn't have enough useable stake to perform this operation or couldn't find any online node";
  }
}reus;

int User::count = 0;
QList<NodeClass*>* User::existingNodes = new QList<NodeClass*>;

User::User(GenesisBlock& geblock,QMainWindow* mw, int graphicLine):m_mw(mw),m_graphicLine(graphicLine)
{
  id = count;
  totalStakes = 0;
  useableStakes = 0;
  pooledStakes = 0;
  createKeys(publicKey,privateKey);
  geblock.addPublicKey(publicKey);
  connectedNode = NULL;
  connectedPool = NULL;
  giveMoney(*this,1000);
  setContextMenuPolicy(Qt::CustomContextMenu);
  setMouseTracking(true);
  setToolTip(getInfos());
  setCursor(Qt::PointingHandCursor);
  setMaximumSize(30,30);
  count++;

  connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(ShowContextMenu(const QPoint &)));
};

User::~User(){}

const std::tuple<long long, long long, long long> User::getPrivateKey() const {
  return privateKey;
}

void User::addUseableStakes(float addus){
  useableStakes += addus;
  setToolTip(getInfos());
}
void User::addtotalStakes(float addts){
  totalStakes += addts;
  setToolTip(getInfos());
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
  //Simulate ledger job (send to user address)
  ((MainWindow*)m_mw)->firstNode->receiveTransactionRequest(t);
  
  return t;
}

NodeClass* User::createNode(int stake){
  
  QList<NodeClass*>::iterator it;
  for(it = existingNodes->begin(); (*it)->isOnline() != true;++it){}
  NodeClass* onlineNode = *it;

  try{
    if(stake<useableStakes || *it == NULL){
      throw reus; 
    }
    if(connectedNode != NULL){
      throw reus;
    }
  }
  catch(exception &e){
    cout << e.what() << '\n';
  }
  NodeClass* node = new NodeClass(this,onlineNode->getBlockChain(),onlineNode->getLedger(),stake,m_mw);
  useableStakes-= stake;
  connectedNode = node;
  existingNodes->append(node);
  ((MainWindow*)m_mw)->addNode(node,this);
  setToolTip(getInfos());
  return node;
}

StakePool* User::createStakePool(int stake){
  
  QList<NodeClass*>::iterator it;
  for(it = existingNodes->begin(); (*it)->isOnline() != true;++it){}
  NodeClass* onlineNode = *it;

  try{
    if(stake<useableStakes || *it == NULL){
      throw reus; 
    }
    if(connectedNode != NULL){
      throw reus;
    }
  }
  catch(exception &e){
    cout << e.what() << '\n';
  }
  StakePool* sp = new StakePool(this,onlineNode->getBlockChain(),onlineNode->getLedger(),stake,m_mw);
  useableStakes-= stake;
  connectedPool = sp;
  existingNodes->append(sp);
  ((MainWindow*)m_mw)->addStakePool(sp,this);
  setToolTip(getInfos());
  return sp;
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
  setToolTip(getInfos());
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

void User::setConnectedNode(NodeClass* cNode){
  connectedNode = cNode;
  setToolTip(getInfos());
}

void User::setConnectedPool(StakePool* cStakePool){
  connectedPool= cStakePool;
  setToolTip(getInfos());
}

QString User::getInfos(){

  QString infos= "Identifiant: " + QString::number(id) + "\n";
  infos += "Stakes totaux: " + QString::number(totalStakes) + "\n";
  infos += "Stakes utilisables: " + QString::number(useableStakes)+"\n";
  infos += "Stakes investis dans une pool stake: " + QString::number(pooledStakes)+"\n";
  if(connectedNode != NULL){
    infos += "Connecté à un noeud: oui \n";
  }
  else infos += "Connecté à un noeud: non \n";

  if(connectedPool != NULL){
    infos += "Connecté à une stake pool: oui \n";
  }
  else infos += "Connecté à une stake pool: non \n";
  
  return infos;
}

void User::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setBrush(QColor(0,204,102));
    painter.drawRect(QRect(0,0,30,30));
    painter.drawText(QRect(10,10,30,30),"U");
}

void User::transactionRequest(){
  QDialog* transact = new QDialog(m_mw);
  QFormLayout* mainLayout = new QFormLayout();
  QHBoxLayout* hbLayout = new QHBoxLayout();
  QPushButton* validate = new QPushButton("Validate");
  QPushButton* exit = new QPushButton("Annuler");
  transact->setWindowTitle("Nouvelle transaction");

  QSpinBox* qsb1 = new QSpinBox();
  qsb1->setMinimum(1);
  qsb1->setMaximum(useableStakes);
  QSpinBox* qsb2 = new QSpinBox();
  qsb2->setMinimum(0);
  qsb2->setMaximum(((MainWindow*)m_mw)->getUsers()->count()-1);

  hbLayout->addWidget(validate);
  hbLayout->addWidget(exit);
  mainLayout->addRow(tr("&Identifiant du bénéficiaire:"), qsb2);
  mainLayout->addRow(tr("&Montant de la transaction:"), qsb1);
  mainLayout->addRow(hbLayout);
  transact->setLayout(mainLayout);
  connect(validate,&QPushButton::clicked,transact,&QDialog::accept);
  connect(exit,&QPushButton::clicked,transact,&QDialog::reject);
  connect(validate,&QPushButton::clicked,[=](){
    QList<User*>::iterator it;
    for(it=((MainWindow*)m_mw)->getUsers()->begin(); (*it)->id != qsb2->value(); ++it){}
    createTransaction((*it),qsb1->value());
    });
  transact->exec();
}

void User::ShowContextMenu(const QPoint &pos){
  
  QMenu contextMenu(tr("Context menu"), this);
  QAction action1("Créer un noeud", this);
  QAction action2("Créer une stake pool", this);
  QAction action3("Faire une transaction", this);
  if(connectedNode == NULL){
    contextMenu.addAction(&action1);
  }
  contextMenu.addAction(&action2);
  contextMenu.addAction(&action3);
  connect(&action1, SIGNAL(triggered()), this, SLOT(createNodeSettings()));
  connect(&action2, SIGNAL(triggered()), this, SLOT(createStakePoolSettings()));
  connect(&action3, SIGNAL(triggered()), this, SLOT(transactionRequest()));

  contextMenu.exec(mapToGlobal(pos));
}

void User::createNodeSettings(){
  QDialog* settingWindow = new QDialog();
  QFormLayout* mainLayout = new QFormLayout();
  QPushButton* validate = new QPushButton("Valider");
  QPushButton* exit = new QPushButton("Annuler");
  settingWindow->setFixedSize(250,110);
  settingWindow->setWindowTitle("Nouveau noeud");
  settingWindow->move(m_mw->pos().x()+m_mw->width()/2-150,m_mw->pos().y()+m_mw->height()/2-50);

  QSpinBox* qsb = new QSpinBox();
  qsb->setMinimum(10);
  qsb->setMaximum(useableStakes);
  mainLayout->addRow(tr("&Stake de départ:"), qsb);
  mainLayout->addWidget(validate);
  mainLayout->addWidget(exit);
  settingWindow->setLayout(mainLayout);
  settingWindow->show();
  
  connect(validate,&QPushButton::clicked,[=](){createNode(qsb->value());});
  connect(validate,&QPushButton::clicked,settingWindow,&QWidget::close);
  connect(exit,&QPushButton::clicked,settingWindow,&QWidget::close);  
}

void User::createStakePoolSettings(){
  QDialog* settingWindow = new QDialog();
  QFormLayout* mainLayout = new QFormLayout();
  QPushButton* validate = new QPushButton("Valider");
  QPushButton* exit = new QPushButton("Annuler");
  settingWindow->setFixedSize(250,110);
  settingWindow->setWindowTitle("Nouvelle Stake Pool");
  settingWindow->move(m_mw->pos().x()+m_mw->width()/2-150,m_mw->pos().y()+m_mw->height()/2-50);

  QSpinBox* qsb = new QSpinBox();
  qsb->setMinimum(10);
  qsb->setMaximum(useableStakes);
  mainLayout->addRow(tr("&Stake de départ:"), qsb);
  mainLayout->addWidget(validate);
  mainLayout->addWidget(exit);
  settingWindow->setLayout(mainLayout);
  settingWindow->show();
  
  connect(validate,&QPushButton::clicked,[=](){createStakePool(qsb->value());});
  connect(validate,&QPushButton::clicked,settingWindow,&QWidget::close);
  connect(exit,&QPushButton::clicked,settingWindow,&QWidget::close);  
}


