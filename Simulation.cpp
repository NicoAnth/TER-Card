#include "Include/Simulation.hpp"
#include "Include/mainwindow.h"

Simulation::Simulation(MainWindow* mainWindow,GenesisBlock* gblock):m_gblock(gblock),m_mainWindow(mainWindow){
}

void giveMoney(User& muser, int amount){
    muser.addtotalStakes(amount);
    muser.addUseableStakes(amount);
}