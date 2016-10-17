#ifndef PERLIN_H
#define PERLIN_H

#include <perlinuni.h>

class Perlin : public PerlinUni
{
public:
    Perlin();
    Perlin(float a, float f);
    float eval(float x, float y);

private:
    float amp;
    float fre;
};

#endif // PERLIN_H
