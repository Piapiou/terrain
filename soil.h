#ifndef SOIL_H
#define SOIL_H

#include <QVector>

class Soil
{
public:
    Soil(float maxSoil);
    void rotateKernel();

private:
    float maxSoil;

};

#endif // SOIL_H
