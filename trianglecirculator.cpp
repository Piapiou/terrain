#include "trianglecirculator.h"
#include "triangleiterator.h"

TriangleCirculator::TriangleCirculator(Mesh &m, int sommet)
{
    i = 0;
    QVector<Triangle> * tri = m.getTriangles();

    TriangleIterator it = TriangleIterator(m);
    while (it.hasNext()) {
        Triangle t = it.next();
        if (t.x() == sommet || t.y() == sommet || t.z() == sommet) {
            v = QVector<int>();
            int firstT;
            if (t.x() == sommet) {
                firstT = t.getAdj(3);
            } else if (t.y() == sommet) {
                firstT = t.getAdj(1);
            } else {
                firstT = t.getAdj(2);
            }
            int actualT = firstT;
            do {
                v.append(actualT);
                Triangle t = tri->at(actualT);
                if (t.x() == sommet) {
                    actualT = t.getAdj(3);
                } else if (t.y() == sommet) {
                    actualT = t.getAdj(1);
                } else {
                    actualT = t.getAdj(2);
                }
            } while (actualT != firstT);
            break;
        }
    }
}

void TriangleCirculator::reinit() {
    i = 0;
}

bool TriangleCirculator::hasNext() {
    return (i < v.length());
}

int TriangleCirculator::next() {
    if (i >= v.length())
        throw "ERROR : NO MORE TRIANGLE";
    return (v[i++]);
}

void TriangleCirculator::goTo(int n) {
    if (n >= v.length())
        throw "ERROR : OUT OF BOUND";
    i = n;
}

int TriangleCirculator::first() {
    return 0;
}

int TriangleCirculator::last() {
    return v.length()-1;
}
