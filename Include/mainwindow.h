#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "Block.hpp"
#include "GenesisBlock.hpp"
#include "Transaction.hpp"
#include "User.hpp"
#include "Node.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initialize();

private:
    Ui::MainWindow *ui;
    GenesisBlock* geBlock;
    QList <Block*> *blockchain;
    QList<Transaction> *ledger;
    User *firstUser;
    NodeClass *firstNode;
};

#endif // MAINWINDOW_H
