#include "Include/Simulation.hpp"

void giveMoney(User muser, int amount){
    muser.useableStakes += amount;
}