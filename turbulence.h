#ifndef TURBULENCE_H
#define TURBULENCE_H

#include <perlin.h>
#include <QVector>

class Turbulence
{
public:
    Turbulence();
    float eval(float x, float y);

private:
    QVector<Perlin> vp;
};

#endif // TURBULENCE_H
