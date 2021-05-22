#ifndef SIMULATION_H
#define SIMULATION_H
#include "User.hpp"
#include "mainwindow.h"

class Simulation: QWidget{
public:
    MainWindow* m_mainWindow;
    GenesisBlock* m_gblock;
    Simulation(MainWindow* mainWindow, GenesisBlock* gblock);

public slots:
    User* createUser();
};
void giveMoney(User& mUser, int amount);

#endif