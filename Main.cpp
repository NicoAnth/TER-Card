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
#include "ui_mainwindow.h"
#include <QPaintEvent>

using namespace std;

int main (int argc, char **argv )
{
  QApplication app(argc, argv);

  MainWindow* window = new MainWindow();
  User blop(*(window->geBlock),window,window->userLine);
  window->firstNode->receiveTransactionRequest(window->firstUser->createTransaction(&blop,1));
  window->firstNode->receiveTransactionRequest(window->firstUser->createTransaction(&blop,2));
  window->firstNode->receiveTransactionRequest(window->firstUser->createTransaction(&blop,3));
  
  window->show();

  return app.exec();
}
