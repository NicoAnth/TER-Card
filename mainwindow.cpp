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

    ui->widget->setMinimumSize(1600,900);
    
    geBlock->setParent(ui->blockW);
    ui->h2->addWidget(firstUser);
    ui->h2->addWidget(firstNode);

}
Ui::MainWindow* MainWindow::getUi(){
    return ui;
}
MainWindow::~MainWindow()
{
    delete ui;
}
