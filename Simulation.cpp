#include "Include/Simulation.hpp"

void giveMoney(User& muser, int amount){
    muser.addtotalStakes(amount);
    muser.addUseableStakes(amount);
}