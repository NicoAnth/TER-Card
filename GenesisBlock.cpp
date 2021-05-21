#include <Include/GenesisBlock.hpp>
#include <Include/Node.hpp>
#include <QCryptographicHash>
#include <QString>
#include <QPainter>

GenesisBlock::GenesisBlock(){
    QString hash_0("42");
    hash_cur = QCryptographicHash::hash(hash_0.toLocal8Bit(),QCryptographicHash::Sha256);
    positionx = 0;
    positiony = 100;
    count += 1;
}

QList<std::pair<long,long>> const GenesisBlock::getPublicKeys(){
    return publicKey;
}
QList<std::pair<NodeClass*,int>> const GenesisBlock::getStakers(){
    return stakers;
}

void GenesisBlock::addStaker(NodeClass* node, int stake){
    stakers.append(std::make_pair(node,stake));
}

void GenesisBlock::addPublicKey(std::pair<long,long> pK){
    publicKey.append(pK);
}

void GenesisBlock::paintEvent(QPaintEvent *){
    QPainter p(this);
    QPen pen;
    p.setBrush(Qt::blue);
    p.drawRect(QRect(positionx,positiony,100,100));
}
/* void GenesisBlock::updateStaker(NodeClass node, int stake,int prec_value ){
    stakers.replace(stakers.indexOf(std::make_pair(node,prec_value)),std::make_pair(node,prec_value));
} */    
