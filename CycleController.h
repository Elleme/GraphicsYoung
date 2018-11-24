﻿#ifndef CYCLECONTROLLER_H
#define CYCLECONTROLLER_H
#include "FigureController.h"

class CycleController : public FigureController
{
public:
    CycleController();
    void mousePressEvent(QPainter* painter, QMouseEvent *e, QPen pen);
    void mouseMoveEvent(QPainter* painter, QMouseEvent *e, QPen pen);
    void mouseReleaseEvent(QPainter* painter,QMouseEvent *e,  QPen pen);
    void MyDrawCycleMidpoint(QPainter* painter,QPoint &start,QPoint &end);
    void MyDrawCycleBresenham(QPainter* painter,QPoint &start,QPoint &end);
    void drawEighthCycle(QPainter* painter,int x0, int y0, int x, int y);
};

#endif // CYCLECONTROLLER_H
