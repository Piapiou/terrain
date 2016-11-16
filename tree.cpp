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
        return 2.0+sqrt(age)*0.05;
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

float Tree::lifeOdds(float height, float soil, float flowmap) {
    float odds = 1.0;
    if (type == this->TYPE_APPLETREE) {
        odds *= 1.0-std::min(std::max(height-50.0,0.0)/20.0,1.0);
        odds *= std::min(std::max(soil-1.0,0.0),1.0);
        odds *= std::min(std::max(std::sqrt(flowmap)-0.03,0.0)*1000,1.0);
    } else if (type == this->TYPE_PINETREE) {
        odds *= std::min(std::max(height-40.0,0.0)/20.0,1.0);
        odds *= std::min(std::max(soil-1.5,0.0),1.0);
        odds *= std::min(std::max(std::sqrt(flowmap)-0.02,0.0)*500,1.0);
    } else if (type == this->TYPE_BUSH) {
        odds *= std::min(std::max(soil-1.0,0.0),1.0);
        odds *= std::min(std::max(std::sqrt(flowmap)-0.01,0.0)*1000,1.0);
        odds *= 0.7;
    }
    //std::cout << "Tree "<< type <<" - Flowmap : "<< sqrt(flowmap) <<" - Odds : "<< odds <<"...\n" << std::flush;
    return odds;
}

Mesh Tree::toMesh() {
    Mesh m = Mesh();

    if (type == this->TYPE_APPLETREE) {
        m.merge(Mesh::makeCylinder(Point(0,0,0),width()*2.5,width()/3.0,20));
        m.merge(Mesh::makeSphere(Point(0,0,width()*2.5),width(),20));
    } else if (type == this->TYPE_PINETREE) {
        m.merge(Mesh::makeCylinder(Point(0,0,0),width()*0.5,width()/2.0,20));
        m.merge(Mesh::makeCone(Point(0,0,width()*0.5),width()*3.0,width(),20));
    } else if (type == this->TYPE_BUSH) {
        m.merge(Mesh::makeSphere(Point(0,0,0),width(),20));
    }
    return m;
}
