#include "Include/BlockchainDraw.hpp"
#include <QPainter>
#include <QBrush>
#include <QPaintEvent>

BlockchainDraw::BlockchainDraw(QList<Block*> *blockchain):m_blockChain(blockchain){}

void BlockchainDraw::paintEvent(QPaintEvent *){

    QPainter p(this);
    p.setBrush(Qt::blue);
    int positionx =0;
    int positiony =0;
    p.drawRect(QRect(positionx,positiony,100,100));
    for(int i=0;i<m_blockChain->count()-1;i++){

        p.drawRect(QRect(positionx,positiony,100,100));
        p.drawLine(QLine(positionx-50,positiony+50,positionx,positiony+50));
        positionx += 150;
    }
}
void BlockchainDraw::appendBlockchain(Block* blockToAppend){
    m_blockChain->append(blockToAppend);
}