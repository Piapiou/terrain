#include "vector3d.h"

Vector3D::Vector3D(const Point p1, const Point p2) {
    this->p1 = Point(p1);
    this->p2 = Point(p2);
}

Point Vector3D::getP1() {
    return p1;
}

Point Vector3D::getP2() {
    return p2;
}

void Vector3D::setP1(Point p) {
    p1 = Point(p);
}

void Vector3D::setP2(Point p) {
    p2 = Point(p);
}
