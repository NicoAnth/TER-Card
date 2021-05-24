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

  window->show();

  return app.exec();
}
