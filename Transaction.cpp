#include "Include/Transaction.hpp"
#include "Include/User.hpp"

int Transaction::count = 0;

std::string Transaction::toString(){
    return std::to_string(this->amount) + std::to_string(this->id);
}

Transaction::Transaction(User& m_sender, User& m_receiver, int m_amount):sender(m_sender),receiver(m_receiver),id(count){
    
    amount = m_amount;
    fees = 0.0001*amount;
    count ++;
    
}

User& Transaction::getSender(){
    return sender;
}
User& Transaction::getReceiver(){
    return receiver;
}

long long Transaction::getSignature(){
    return signature;
}

void Transaction::setSignature(long long m_signature){
    signature = m_signature;
}