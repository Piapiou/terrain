#include "turbulence.h"
#include <iostream>

Turbulence::Turbulence()
{
    vp = QVector<Perlin>();
    vp.append(Perlin(100.0  ,1.0/500.0));
    vp.append(Perlin(20.0  ,1.0/200.0));
    vp.append(Perlin(5.0  ,1.0/50.0));
}

float Turbulence::eval(float x, float y) {

    float z = 0;
    for (int i = 0; i < vp.length(); i++) {
        z += vp[i].eval(x,y);
    }
    return z;
}
