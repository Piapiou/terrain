#include "triangleiterator.h"

TriangleIterator::TriangleIterator(Mesh &m)
{
    v = m.getTriangles();
    i = 0;
}

void TriangleIterator::reinit() {
    i = 0;
}

bool TriangleIterator::hasNext() {
    return (i < v->length());
}

Triangle TriangleIterator::next() {
    if (i >= v->length())
        throw "ERROR : NO MORE TRIANGLE";
    return (v->at(i++));
}

void TriangleIterator::goTo(int n) {
    if (n >= v->length())
        throw "ERROR : OUT OF BOUND";
    i = n;
}

int TriangleIterator::first() {
    return 0;
}

int TriangleIterator::last() {
    return v->length()-1;
}
