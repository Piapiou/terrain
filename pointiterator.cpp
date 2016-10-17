#include "pointiterator.h"

PointIterator::PointIterator(Mesh &m)
{
    v = m.getVertices();
    i = 0;
}

void PointIterator::reinit() {
    i = 0;
}

bool PointIterator::hasNext() {
    return (i < v->length());
}

Point PointIterator::next() {
    if (i >= v->length())
        throw "ERROR : NO MORE POINT";
    return (v->at(i++));
}

void PointIterator::goTo(int n) {
    if (n >= v->length())
        throw "ERROR : OUT OF BOUND";
    i = n;
}

int PointIterator::first() {
    return 0;
}

int PointIterator::last() {
    return v->length()-1;
}
