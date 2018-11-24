﻿#include "CycleController.h"

CycleController::CycleController()
{

}

bool CycleController::isOperationing(QMouseEvent *e, QPoint &start, QPoint &end)
{

}

void CycleController::mousePressEvent(QPainter *painter, QMouseEvent *e, QPen pen)
{

}

void CycleController::mouseMoveEvent(QPainter* painter, QMouseEvent *e, QPen pen)
{

}

void CycleController::mouseReleaseEvent(QPainter* painter,QMouseEvent *e,  QPen pen)
{

}

void CycleController::setStartPoint(Point point)
{

}

void CycleController::setEndPoint(Point point)
{

}

void CycleController::moveToPoint(Point point)
{

}

void CycleController::rotateToPoint(Point point)
{

}

void CycleController::setState(DRAW_STATE *state)
{

}

void CycleController::drawHandle(QPainter *painter, QPen pen)
{

}

void CycleController::clearState()
{

}

void CycleController::MyDrawCycleBresenham(QPainter *painter, QPoint &start, QPoint &end)//
{
    //首先先在这里实现我的画圆算法
    qDebug()<<"MyDrawCycle "<<endl;
    int x0 = start.x();
    int y0 = start.y();
    double R = this->getLength(start,end);
    int x,y,p;
    x=0;
    y=R;
    p=3-2*R;
    for(;x<=y;x++)
    {
        this->drawEighthCycle(painter,x0,y0,x,y);
        if(p>=0){
           p+=4*(x-y)+10;
           y--;
        }else{
            p+=4*x+6;
        }
    }
}

void CycleController::MyDrawCycleMidpoint(QPainter *painter, QPoint &start, QPoint &end)
{
    //首先先在这里实现我的画圆算法
    qDebug()<<"MyDrawCycle "<<endl;

    int x0 = start.x();
    int y0 = start.y();
    double R = this->getLength(start,end);
    int x,y;
    double d;
    x = 0;
    y = R;
    d = 1-R;
    int deltaX = 3;
    int deltaY = 5-2*R;
    this->drawEighthCycle(painter,x0,y0,x,y);

    while(x<y){
        if(d<0){
            d+=deltaX;
            deltaX+=2;
            deltaY+=2;
            x++;
        }
        else
        {
            d+=deltaY;
            deltaX+=2;
            deltaY+=4;
            x++;
            y--;
        }
        this->drawEighthCycle(painter,x0,y0,x,y);
    }
}


void CycleController::drawEighthCycle(QPainter *painter, int x0, int y0, int x, int y)
{
    QPoint temPt1(x0+x,y0+y);
    QPoint temPt2(x0+y,y0+x);
    QPoint temPt3(x0+x,y0-y);
    QPoint temPt4(x0+y,y0-x);
    QPoint temPt5(x0-x,y0-y);
    QPoint temPt6(x0-y,y0-x);
    QPoint temPt7(x0-x,y0+y);
    QPoint temPt8(x0-y,y0+x);

    painter->drawPoint(temPt1);
    painter->drawPoint(temPt2);
    painter->drawPoint(temPt3);
    painter->drawPoint(temPt4);
    painter->drawPoint(temPt5);
    painter->drawPoint(temPt6);
    painter->drawPoint(temPt7);
    painter->drawPoint(temPt8);
}