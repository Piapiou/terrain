#include "perlinuni.h"
#include <iostream>

PerlinUni::PerlinUni()
{
    img = QImage(":/img/terrain3.png");
}
/*
Point bezier (Point p1, Point p2, float d) {
    QVector<Point> p = QVector<Point>();
    p.append(Point(p1));
    p.append(Point((p2.x()+6*p1.x())/7,(p2.y()+6*p1.y())/7,p1.z()));
    p.append(Point((p2.x()*6+p1.x())/7,(p2.y()*6+p1.y())/7,p2.z()));
    p.append(Point(p2));

    while (p.length()>1) {
        for (int i = 0; i < p.length()-1; i++) {
            p[i].setX(p[i].x()*d+p[i+1].x()*(1.0-d));
            p[i].setY(p[i].y()*d+p[i+1].y()*(1.0-d));
            p[i].setZ(p[i].z()*d+p[i+1].z()*(1.0-d));
        }
        p.removeLast();
    }

//    printf("(%f,%f,%f) (%f,%f,%f) %f -> (%f,%f,%f)\n",p1.x(),p1.y(),p1.z(),
//                                                      p2.x(),p2.y(),p2.z(), d,
//                                                      p[0].x(),p[0].y(),p[0].z());

    return Point(p[0]);
}*/

float PerlinUni::eval(float x, float y) {

    while (x < 0) x += img.width();
    while (y < 0) y += img.height();

    float dx = 1-(x - (int)x);
    float dy = 1-(y - (int)y);

    dx = 3*dx*dx - 2*dx*dx*dx;
    dy = 3*dy*dy - 2*dy*dy*dy;

    // Traitement
    float pixel1 = (float)img.pixelColor((int)x%img.width(),(int)y%img.height()).red()*dx*dy;
    float pixel2 = (float)img.pixelColor((int)(x+1)%img.width(),(int)y%img.height()).red()*(1.0-dx)*dy;
    float pixel3 = (float)img.pixelColor((int)x%img.width(),(int)(y+1)%img.height()).red()*dx*(1.0-dy);
    float pixel4 = (float)img.pixelColor((int)(x+1)%img.width(),(int)(y+1)%img.height()).red()*(1.0-dx)*(1.0-dy);
    float pz = pixel1 + pixel2 + pixel3 + pixel4;

    float pixel = pz/255;

    float seuil = 0.95;

    if (pixel > seuil) {
        pixel = seuil*2-pixel;
    }

    return pixel;
}
