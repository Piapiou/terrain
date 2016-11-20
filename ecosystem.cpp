#include "ecosystem.h"
#include <QPainter>
#include <QImage>
#include <point.h>
#include <terrain.h>
#include <iostream>

Ecosystem::Ecosystem()
{
    this->VT = QVector<Tree>();
}


void Ecosystem::init(int n, Terrain * T) {

    this->T = T;
    while (VT.size() < n) {
        int x = rand()%T->getWidth();
        int y = rand()%T->getLength();
        plant(x,y,rand()%50,rand()%3);
    }

}

void Ecosystem::step() {
    for (int i = 0; i < VT.size(); i++) {
        VT[i].life();
        float x1 = (float)VT[i].getX()*T->getWidthRatio();
        float y1 = (float)VT[i].getY()*T->getLengthRatio();

        for (int j = 0; j < VT.size(); j++) {
            float x2 = (float)VT[j].getX()*T->getWidthRatio();
            float y2 = (float)VT[j].getY()*T->getLengthRatio();
            if (j != i && pow((x2-x1),2.0)+pow((y2-y1),2.0) < pow(VT[i].width()+VT[j].width(),2.0) && VT[i].strengh() < VT[j].strengh()) {
                VT[i].sick();
            }
        }

        if (VT[i].getSickness() == 0 && VT[i].strengh()%5 == 0) {
            float angle = ((float)(rand()%360)/180)*3.14159265;
            float dist = 2.5+(float)(rand()) / (float)(RAND_MAX);
            int nx = (x1+cos(angle)*VT[i].width()*dist)/T->getWidthRatio();
            int ny = (y1+sin(angle)*VT[i].width()*dist)/T->getLengthRatio();
            if (nx > 0 && nx < T->getWidth() && ny > 0 && ny < T->getLength()) {
                plant(nx,ny,0,VT[i].getType());
            }
        }

        if (VT[i].getSickness() > 10) {
            VT.remove(i--);
        }
    }
}

void Ecosystem::plant(int x, int y, int age, int type) {
    Tree t = Tree(type,age,x,y);
    bool canPlant = true;

    float x1 = (float)t.getX()*T->getWidthRatio();
    float y1 = (float)t.getY()*T->getLengthRatio();
    for (int j = 0; canPlant && j < VT.size(); j++) {
        float x2 = (float)VT[j].getX()*T->getWidthRatio();
        float y2 = (float)VT[j].getY()*T->getLengthRatio();
        if (pow((x2-x1),2.0)+pow((y2-y1),2.0) < pow(t.width()+VT[j].width(),2.0)) {
            canPlant = false;
        }
    }

    if (canPlant && t.lifeOdds(T->getSoilLevelAt(x,y), T->getSoilAmountAt(x,y), T->getFlowMap(x,y)) > (float)(rand()) / (float)(RAND_MAX))
        VT.append(t);
}

void Ecosystem::exportImg(QString path) {
    QImage img = QImage(T->getWidth()*10,T->getLength()*10,QImage::Format_RGB32);
    QPainter p(&img);
    p.setPen( QPen( Qt::white, 3.0 ) );
    p.setBrush(QBrush( Qt::white) );
    p.drawRect(0,0,img.width(),img.height());
    for (int i = 0; i < VT.size(); i++) {
        if (VT[i].getType() == Tree::TYPE_APPLETREE)
            p.setPen( QPen( Qt::red, 2.0 ) );
        if (VT[i].getType() == Tree::TYPE_PINETREE)
            p.setPen( QPen( Qt::green, 2.0 ) );
        if (VT[i].getType() == Tree::TYPE_BUSH)
            p.setPen( QPen( Qt::blue, 2.0 ) );
        p.drawEllipse(QPoint(VT[i].getX()*10,VT[i].getY()*10),(int)VT[i].width()/T->getLengthRatio()*10,(int)VT[i].width()/T->getLengthRatio()*10);
    }
    p.end();

    img.save(path);

}

Mesh Ecosystem::generateMesh() {
    Mesh m = Mesh();
    for (int i = 0; i < VT.size(); i++) {
        Mesh mt = VT[i].toMesh();
        int x = VT[i].getX();
        int y = VT[i].getY();
        Point * o = T->getOrigin();
        mt.translate(Point(o->x()+T->getWidthRatio()*x,o->y()+T->getLengthRatio()*y,T->getSoilLevelAt(x,y)));
        m.merge(mt);
    }
    return m;
}
