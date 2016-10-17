#include "pointcirculator.h"
#include "triangleiterator.h"
#include "triangle.h"

PointCirculator::PointCirculator(Mesh &m, int sommet)
{
    i = 0;
    QVector<Triangle> * tri = m.getTriangles();
    TriangleIterator triangles = TriangleIterator(m);
    while (triangles.hasNext()) {
        Triangle t = triangles.next();
        if (t.x() == sommet || t.y() == sommet || t.z() == sommet) {
            v = QVector<int>();
            int firstT;
            int p2;
            if (t.x() == sommet) {
                firstT = t.getAdj(3);
                p2 = t.y();
            } else if (t.y() == sommet) {
                firstT = t.getAdj(1);
                p2 = t.z();
            } else {
                firstT = t.getAdj(2);
                p2 = t.x();
            }
            int actualT = firstT;
            do {
                v.append(p2);
                Triangle t = tri->at(actualT);
                if (t.x() == sommet) {
                    actualT = t.getAdj(3);
                    p2 = t.y();
                } else if (t.y() == sommet) {
                    actualT = t.getAdj(1);
                    p2 = t.z();
                } else {
                    actualT = t.getAdj(2);
                    p2 = t.x();
                }
            } while (actualT != firstT);
            break;
        }
    }
}

void PointCirculator::reinit() {
    i = 0;
}

bool PointCirculator::hasNext() {
    return (i < v.length());
}

int PointCirculator::next() {
    if (i >= v.length())
        throw "ERROR : NO MORE POINT";
    return (v[i++]);
}

void PointCirculator::goTo(int n) {
    if (n >= v.length())
        throw "ERROR : OUT OF BOUND";
    i = n;
}

int PointCirculator::first() {
    return 0;
}

int PointCirculator::last() {
    return v.length()-1;
}
