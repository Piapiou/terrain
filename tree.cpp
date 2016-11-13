#include "tree.h"
#include <iostream>
#include <math.h>

Tree::Tree() {

}

Tree::Tree(int type, int initAge, int x, int y)
{
    this->type = type;
    age = initAge;
    this->x = x;
    this->y = y;
    sickness = 0;
}

void Tree::life() {
    age++;
    sickness = std::max(0,sickness-1);
    if (type == this->TYPE_APPLETREE && age > 70) {
        sick();
    } else if (type == this->TYPE_PINETREE && age > 90) {
        sick();
    } else if (type == this->TYPE_BUSH && age > 40) {
        sick();
    }
}

float Tree::width() {
    if (type == this->TYPE_APPLETREE) {
        return 3.0+sqrt(age)*0.1;
    } else if (type == this->TYPE_PINETREE) {
        return 3.5+sqrt(age)*0.15;
    } else if (type == this->TYPE_BUSH) {
        return 1.0+sqrt(age)*0.02;
    }
    return 0.0;
}

int Tree:: getX() {
    return x;
}

int Tree:: getY() {
    return y;
}

void Tree::sick() {
    sickness += 2;
}

int Tree::getSickness() {
    return sickness;
}

int Tree::getType() {
    return type;
}

int Tree::strengh() {

    if (type == this->TYPE_APPLETREE) {
        return age+20;
    } else if (type == this->TYPE_PINETREE) {
        return age+30;
    } else if (type == this->TYPE_BUSH) {
        return age;
    }
    return age;
}

Mesh Tree::toMesh() {
    Mesh m;

    if (type == this->TYPE_APPLETREE) {
        m = Mesh::makeCylinder(Point(0,0,0),width()*2.5,width()/3,20);
        m.merge(Mesh::makeSphere(Point(0,0,width()*2.5),width(),20));
    } else if (type == this->TYPE_PINETREE) {
        m = Mesh::makeCylinder(Point(0,0,0),width()*0.5,width()/3,20);
        m.merge(Mesh::makeCone(Point(0,0,width()*0.5),width()*3.0,width(),20));
    } else if (type == this->TYPE_BUSH) {
        m = Mesh::makeSphere(Point(0,0,0),width(),20);
    }
    return m;
}
