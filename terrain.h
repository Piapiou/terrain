#ifndef TERRAIN_H
#define TERRAIN_H

#include <QVector>
#include <point.h>
#include <mesh.h>
#include <QImage>
#include <turbulence.h>
#include <flowmap.h>
#include <ecosystem.h>


class Ecosystem;

class Terrain
{
public:
    Terrain(const Point p1, const Point p2, Turbulence T, int length, int width);
    void initSoil(float maxSoil, float facteurDiffSoil);
    void setSoilAt(int i, int j, float h);
    void makeFlowMap(int nbIteration);
    void addFlowMap(int x, int y, float z);
    float getFlowMap(int x, int y);
    void setFlowMap(int x, int y, float z);
    int getWidth();
    int getLength();
    float getWidthRatio();
    float getLengthRatio();
    float getBedrockAt(int i, int j);
    float getSoilAmountAt(int i, int j);
    float getSoilLevelAt(int i, int j);
    void simulateEcosystem(int time);
    Point* getOrigin();
    Mesh toMesh();
    void saveHeightImg(QString s);
    void saveSoilImg(QString s);
    void saveFlowmapImg(QString s);

private:
    QVector<float> bedrock;
    QVector<float> soil;
    QVector<float> flowmap;
    Point a;
    Point b;
    int width;
    int length;
    float zMin;
    float zMax;
    Ecosystem es;

};


#endif // TERRAIN_H
