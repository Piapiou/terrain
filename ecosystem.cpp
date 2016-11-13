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
    for (int i = 0; i < n; i++) {
        int x = rand()%T->getWidth();
        int y = rand()%T->getLength();
        VT.append(Tree(rand()%3,rand()%50,x,y));

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
        if (VT[i].getSickness() > 10) {
            VT.remove(i--);
        }
    }
}

void Ecosystem::exportImg(QString path) {
    QImage img = QImage(T->getWidth()*10,T->getLength()*10,QImage::Format_RGB32);
    QPainter p(&img);
    p.setPen( QPen( Qt::white, 3.0 ) );
    for (int i = 0; i < VT.size(); i++) {
        if (VT[i].getType() == Tree::TYPE_APPLETREE)
            p.setPen( QPen( Qt::red, 3.0 ) );
        if (VT[i].getType() == Tree::TYPE_PINETREE)
            p.setPen( QPen( Qt::green, 3.0 ) );
        if (VT[i].getType() == Tree::TYPE_BUSH)
            p.setPen( QPen( Qt::blue, 3.0 ) );
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
