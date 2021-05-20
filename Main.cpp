#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <Include/mainwindow.h>
#include "Include/Node.hpp"
#include "Include/User.hpp"
#include "Include/Rsa.h"
#include "Include/GenesisBlock.hpp"
#include "Include/Simulation.hpp"
#include <QPaintEvent>

using namespace std;

int main (int argc, char **argv )
{
  QApplication app(argc, argv);

  MainWindow* window = new MainWindow();
  window->show();

 /*  //Init
  GenesisBlock geBlock;
  QList <Block*> blockChain;
  QList<Transaction> transaction;
  blockChain.append(&geBlock);
  User toto(geBlock),Lolo(geBlock);

  //Give money
  giveMoney(toto,1000);
  giveMoney(Lolo,500);


  //Create Node
  NodeClass* firstNode = new NodeClass(&toto,blockChain, transaction,10);
  firstNode->setSlotLeader(true);

  //Create transact'
  firstNode->receiveTransactionRequest(toto.createTransaction(&Lolo,50));
  firstNode->receiveTransactionRequest(Lolo.createTransaction(&toto,20));
  firstNode->receiveTransactionRequest(toto.createTransaction(&Lolo,40));

  firstNode->createBlock();
  firstNode->createBlock();

  auto myWindow= new QWidget();
  myWindow->setMinimumHeight(750);
  myWindow->setMinimumWidth(1400);
  myWindow->resize(1800,1000);
  
  QList<Block *>::iterator i;
  for(i=firstNode->getBlockChain().begin();i!=firstNode->getBlockChain().end();++i){
    (*(*i)).setParent(myWindow);
  }
  myWindow->show(); */
  return app.exec();
}
