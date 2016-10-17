#ifndef TERRAIN_H
#define TERRAIN_H

#include <QVector>
#include <point.h>
#include "mesh.h"
#include <QImage>
#include <turbulence.h>

class Terrain
{
public:
    Terrain(const Point p1, const Point p2, Turbulence T, int length, int width);
    void setSoil();
    Mesh toMesh();

private:
    QVector<float> bedrock;
    QVector<float> soil;
    QVector<float> water;
    Point a;
    Point b;
    int width;
    int length;
    float zMin;
    float zMax;
};


#endif // TERRAIN_H
