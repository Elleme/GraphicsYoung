﻿#ifndef CANVAS_GL_H
#define CANVAS_GL_H

#include "constParams.h"
#include "Line.h"
#include "Cycle.h"
#include "Ellipse.h"
#include "LineController.h"
#include "CycleController.h"
#include "EllipseController.h"
#include "Point.h"

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QtDebug>

#include <QMouseEvent>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QPixmap>
#include <QPoint>
#include <QPainter>
#include <QPalette>

#include <QFileDialog>
#include <QMessageBox>



class Canvas_GL : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit Canvas_GL(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *) Q_DECL_OVERRIDE;    //鼠标点击时操作
    void mouseMoveEvent(QMouseEvent *) Q_DECL_OVERRIDE;     //鼠标移动时操作（先点击为前提）
    void mouseReleaseEvent(QMouseEvent *) Q_DECL_OVERRIDE;  //鼠标释放时操作
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *) Q_DECL_OVERRIDE;
    void saveImage(); //保存当前画布内容（pix内容）
    void clearImage(); //清空当前画布内容
    void recallImage();//撤销上一步操作
    void setMode(FIGURE_TYPE type); //设置图形
    QPixmap *getPixCopy();              //得到当前画布的拷贝
    QPixmap *getPixCopy(QPixmap* pic);  //得到指定pic的拷贝
protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int width, int height) Q_DECL_OVERRIDE;


signals:

public slots:
    void setColor(QColor);  //槽函数，用于实现画笔颜色的改变

private:
    QPixmap *pix;       //画布
    QPixmap *pixToMove; //用于实现图形随着鼠标动态移动的画布缓冲区
    QPen pen;           //画笔，默认颜色为黑色，大小为1像素，样式为solid，实现像素级绘图

    QPoint startPos;    //捕捉画图的起始点
    QPoint endPos;      //捕捉画图的终止点
    QPoint regPos;      //缓冲点
    int style;          //画笔样式
    int weight;         //画笔粗细
    QColor color;       //画笔颜色

    //QPainter *painter;
    QVector<QPixmap*> reVec;    //存储画布内容，用于实现撤销操作
    QVector<Figure*> figureVec; //存储当前画布的图形
    LineController lineController;      //控制直线的行为
    CycleController cycleController;    //控制圆的行为
    EllipseController ellipseController;//控制椭圆的行为

    FIGURE_TYPE figureMode;     //当前画图系统模式
    DRAW_STATE drawState;       //当前画图状态


};

#endif // CANVAS_GL_H