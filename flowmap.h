#ifndef FLOWMAP_H
#define FLOWMAP_H

#include "terrain.h"

class Terrain;

class Flowmap
{
public:
    Flowmap(Terrain * T, int nbIteration);
    void generateFlowMap();

private:
    void drop(int i, int j);
    bool move();

    Terrain * T;
    int nbIteration;
    int x, y;
};

#endif // FLOWMAP_H
