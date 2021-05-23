#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "Block.hpp"
#include "GenesisBlock.hpp"
#include "Transaction.hpp"
#include "User.hpp"
#include "Node.hpp"
#include "BlockchainDraw.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static int userLine;
    GenesisBlock* geBlock;
    QList <Block*> *blockchain;
    QList<Transaction> *ledger;
    User *firstUser;
    NodeClass *firstNode;
    BlockchainDraw *blockchainDraw;
    Ui::MainWindow* getUi();

private:
    Ui::MainWindow *ui;
    
public slots:
    User* createUser();
private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
