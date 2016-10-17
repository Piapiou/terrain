#include "perlin.h"
#include <iostream>

Perlin::Perlin()
{
    amp = 1.0;
    fre = 1.0;
}

Perlin::Perlin(float a, float f)
{
    amp = a;
    fre = f;
}

float Perlin::eval(float x, float y) {
    float z = amp*PerlinUni::eval(fre*x,fre*y);
    return z;
}
