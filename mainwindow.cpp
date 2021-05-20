#include "Include/mainwindow.h"
#include "ui_mainwindow.h"
#include "Include/Simulation.hpp"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow){

    ui->setupUi(this);
    geBlock = new GenesisBlock();
    blockchain = new QList <Block*>;
    ledger = new QList<Transaction>;
    blockchain->append(geBlock);
    firstUser = new User(*geBlock);
    giveMoney(*firstUser,100);
    firstNode = new NodeClass(firstUser,*blockchain,*ledger,100);
    firstNode->setSlotLeader(true);

    //setMinimumSize(1900,1000);
    ui->v1->addWidget(geBlock);
    ui->v1->addWidget(firstUser);
    ui->v1->addWidget(firstNode);

    /* geBlock->setParent(this);
    firstUser->setParent(this);
    firstNode->setParent(this); */

}
Ui::MainWindow* MainWindow::getUi(){
    return ui;
}
MainWindow::~MainWindow()
{
    delete ui;
}