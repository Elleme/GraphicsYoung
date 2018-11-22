﻿#include "LineController.h"

LineController::LineController()
{
    this->curLine = NULL;
    this->painter = NULL;
}

void LineController::mousePressEvent(QPainter *painter, QMouseEvent *e, QPen pen)
{
    qDebug()<<"LineController::mousePressEvent"<<endl;
    qDebug()<<"2"<<endl;
    if(curLine!=NULL){
        qDebug()<<"curLine!=NULL"<<endl;
    }else{
        qDebug()<<"curLine==NULL"<<endl;
    }
    if(e->button()==Qt::LeftButton)
    {
        if(curLine!=NULL)
        {
            if(curLine->startPoint.distanceToPoint(e->pos())<=5)
            {
                qDebug()<<"SETBEGIN"<<endl;
                setLP = SETBEGIN;
                return;
            }
            else if(curLine->endPoint.distanceToPoint(e->pos())<=5)
            {
                qDebug()<<"SETEND"<<endl;
                setLP = SETEND;
                return;
            }
            else if(curLine->centerPoint.distanceToPoint(e->pos())<=5)
            {
                setLP = SETCENTER;
                return;
            }
            else if(curLine->rotatePoint.distanceToPoint(e->pos())<=5)
            {
                setLP = SETHANDLE;
                return;
            }
            //setLP = SETNULL;
            return;
//            else if(curLine->isOn(curPoint))
//            {
//                return;
//            }
        }
        Point curPoint(e->pos().x(),e->pos().y());
        curLine = new Line();
        curLine->startPoint = curPoint;
        curLine->endPoint = curPoint;
        qDebug()<<"3"<<endl;
        setLP = SETEND;
    }
    qDebug()<<"4"<<endl;
}

void LineController::mouseMoveEvent(QPainter *painter, QMouseEvent *e, QPen pen)
{
    qDebug()<<"LineController::mouseMoveEvent"<<endl;
    this->painter = painter;
    Point curPoint(e->pos().x(),e->pos().y());
    if (curLine == NULL)
        return;
    switch(setLP){
        case SETBEGIN: this->setStartPoint(curPoint); break;
        case SETEND: this->setEndPoint(curPoint); break;
//        case SETCENTER: curLine->translate(curPoint-curLine->getCenterPoint()); break;
//        case SETHANDLE: curLine->setHandlePointByRef(curPoint); break;
        default:
            qDebug()<<"Error setLP"<<endl;
    }
}

void LineController::mouseReleaseEvent(QPainter *painter, QMouseEvent *e, QPen pen)
{
    this->painter = painter;
    qDebug()<<"LineController::mouseReleaseEvent"<<endl;
    MyDrawLineDDA(painter,curLine->startPoint.point,curLine->endPoint.point);
}



void LineController::MyDrawLineBresenham(QPainter *painter, QPoint &start, QPoint &end)
{
    //首先先在这里实现我的直线算法
    qDebug()<<"MyDrawLine Bresenham"<<endl;

    int x1 = start.x();
    int y1 = start.y();
    int x2 = end.x();
    int y2 = end.y();

    int x,y,dx,dy,p;
    x=x1;
    y=y1;
    dx=x2-x1;
    dy=y2-y1;
    p=2*dy-dx;
    for(;x<=x2;x++)
    {
        QPoint temPt(x,y);
        painter->drawPoint(temPt);
        if(p>=0)
        {     y++;
            p+=2*(dy-dx);
        }
        else
        {
            p+=2*dy;
        }
    }
}

void LineController::MyDrawLineDDA(QPainter *painter, QPoint &start, QPoint &end)
{
    //首先先在这里实现我的直线算法
    qDebug()<<"MyDrawLine DDA"<<endl;
    qDebug()<< "before"<<endl;
    int x1 = start.x();
    qDebug()<< "after"<<endl;
    int y1 = start.y();
    int x2 = end.x();
    int y2 = end.y();

    double dx=x2-x1;
    double dy=y2-y1;
    double e=(fabs(dx)>fabs(dy))?fabs(dx):fabs(dy);
    double x=x1;
    double y=y1;

    dx/=e;
    dy/=e;

    for(int i=1;i<=e;i++){

        QPoint temPt((int)(x+0.5), (int)(y+0.5));
        painter->drawPoint(temPt);

        x+=dx;
        y+=dy;
    }
}

void LineController::setStartPoint(Point point)
{
    qDebug() << "setStartPoint("<<endl;
    curLine->startPoint = point;
    curLine->startPoint.DrawCyclePoint(painter,pen);
    curLine->endPoint.DrawCyclePoint(painter,pen);
    qDebug() << "StartPoint(" <<curLine->startPoint.point.x()<<","<<curLine->startPoint.point.y()<<")"<<endl;
    qDebug() << "EndPoint(" <<curLine->endPoint.point.x()<<","<<curLine->endPoint.point.y()<<")"<<endl;
    MyDrawLineDDA(painter,curLine->startPoint.point,curLine->endPoint.point);
}

void LineController::setEndPoint(Point point)
{
    qDebug() << "setEndPoint("<<endl;

    curLine->endPoint = point;
    curLine->startPoint.DrawCyclePoint(painter,pen);
    curLine->endPoint.DrawCyclePoint(painter,pen);
    qDebug() << "StartPoint(" <<curLine->startPoint.point.x()<<","<<curLine->startPoint.point.y()<<")"<<endl;
    qDebug() << "EndPoint(" <<curLine->endPoint.point.x()<<","<<curLine->endPoint.point.y()<<")"<<endl;
    MyDrawLineDDA(painter,curLine->startPoint.point,curLine->endPoint.point);
}
