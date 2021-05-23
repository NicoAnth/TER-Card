#include "Include/mainwindow.h"
#include "ui_mainwindow.h"
#include "Include/Simulation.hpp"
#include <QSpacerItem>

int MainWindow::userLine =1;

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow){

    ui->setupUi(this);
    geBlock = new GenesisBlock();
    blockchain = new QList <Block*>;
    ledger = new QList<Transaction>;
    blockchain->append(geBlock);
    firstUser = new User(*geBlock);
    giveMoney(*firstUser,100);
    firstNode = new NodeClass(firstUser,blockchain,*ledger,100);
    blockchainDraw = new BlockchainDraw(blockchain);
    firstUser->connectedNode = firstNode;
    firstNode->setSlotLeader(true);
    repaint();

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

    User* newUser = new User(*geBlock);
    ui->gl->addWidget(newUser,0,userLine);
    userLine++;
    return newUser;
}


void MainWindow::on_pushButton_clicked()
{
    createUser();
}
