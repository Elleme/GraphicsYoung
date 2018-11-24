﻿#ifndef ELLIPSECONTROLLER_H
#define ELLIPSECONTROLLER_H
#include "FigureController.h"


class EllipseController : public FigureController
{
public:
    EllipseController();
    //继承的抽象方法
    bool isOperationing(QMouseEvent *e,QPoint &start,QPoint &end);
    void mousePressEvent(QPainter* painter, QMouseEvent *e, QPen pen);
    void mouseMoveEvent(QPainter* painter, QMouseEvent *e, QPen pen);
    void mouseReleaseEvent(QPainter* painter,QMouseEvent *e,  QPen pen);
    void setStartPoint(Point point);
    void setEndPoint(Point point);
    void moveToPoint(Point point);
    void rotateToPoint(Point point);
    void setState(DRAW_STATE *state);
    void drawHandle(QPainter* painter, QPen pen);
    void clearState();
    //该类的特有方法
    void drawQuarterEllipse(QPainter* painter,int x0, int y0, int x, int y);
    void MyDrawEllipse(QPainter* painter,QPoint &start,QPoint &end);
};

#endif // ELLIPSECONTROLLER_H