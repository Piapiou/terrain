#include "soil.h"

Soil::Soil(Terrain T, float maxSoil)
{
    this->T = T;
    this->maxSoil = maxSoil;
}

void Soil::setSoil(float x, float y) {

    float zSoil = 0;
    float zBed = T.getBedrockAt(x,y);

    //calcul

    if (zSoil > maxSoil){
        zSoil = maxSoil;
    }

    T.setSoilAt(x,y,zSoil);

}
