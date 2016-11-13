#ifndef SOIL_H
#define SOIL_H

#include <QVector>
#include <terrain.h>

class Soil
{
public:
    Soil(Terrain * T, float maxSoil, float facteurDiffSoil);
    void setSoil(int x, int y);

private:
    float maxSoil;
    float fDiffSoil;
    Terrain * T;

};

#endif // SOIL_H
