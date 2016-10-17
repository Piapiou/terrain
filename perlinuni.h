#ifndef PERLINUNI_H
#define PERLINUNI_H

#include <Qimage>
#include <point.h>

class PerlinUni
{
public:
    PerlinUni();
    float eval(float x, float y);

private:
    QImage img;
};

#endif // PERLINUNI_H
