#include "Include/Transaction.hpp"
#include "Include/User.hpp"

std::string Transaction::toString(){
    return std::to_string(this->amount) + std::to_string(this->id);
}

Transaction::Transaction(){
    id = 1;
}

Transaction::Transaction(User* m_sender, User* m_receiver, int m_amount, int m_id){
    sender = m_sender;
    receiver = m_receiver;
    amount = m_amount;
    id = m_id;
}