#include "Include/mainwindow.h"
#include "ui_mainwindow.h"
#include "Include/Simulation.hpp"
#include <QSpacerItem>

int MainWindow::userLine =1;

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow){

    ui->setupUi(this);
    users = new QList<User*>;
    geBlock = new GenesisBlock();
    blockchain = new QList <Block*>;
    ledger = new QList<Transaction>;
    blockchain->append(geBlock);
    firstUser = new User(*geBlock,this,userLine);
    users->append(firstUser);
    giveMoney(*firstUser,100);
    firstNode = new NodeClass(firstUser,blockchain,*ledger,100,this);
    blockchainDraw = new BlockchainDraw(blockchain);
    firstUser->connectedNode = firstNode;
    firstUser->existingNodes->append(firstNode);
    firstUser->setToolTip(firstUser->getInfos());
    firstNode->setSlotLeader(true);
    firstNode->setToolTip(firstNode->getInfos());
    ui->widget->setMinimumSize(1000,600);
    ui->h1->addWidget(blockchainDraw);
    ui->gl->addWidget(firstUser,1,0);
    ui->gl->addWidget(firstNode,0,0);

}
Ui::MainWindow* MainWindow::getUi(){
    return ui;
}
MainWindow::~MainWindow()
{
    delete ui;
}

User* MainWindow::createUser(){

    User* newUser = new User(*geBlock,this,userLine);
    users->append(newUser);
    ui->gl->addWidget(newUser,1,userLine);
    userLine++;
    return newUser;
}

void MainWindow::addNode(NodeClass* node, User* user){
    ui->gl->addWidget(node,0,user->m_graphicLine);
}
QList<User*>* MainWindow::getUsers(){
     return users;
 }

void MainWindow::on_pushButton_clicked()
{
    createUser();
}
