#include "soil.h"

Soil::Soil(Terrain * T, float maxSoil, float facteurDiffSoil)
{
    this->T = T;
    this->maxSoil = maxSoil;
    this->fDiffSoil = facteurDiffSoil;
}

void Soil::setSoil(int x, int y) {

    float zSoil = 0;
    float diff = 0;
    float zBed = T->getBedrockAt(x,y);

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (x+i >= 0 && x+i < T->getWidth() && y+j >= 0 && y+j < T->getLength())
                diff = std::max(diff,zBed-T->getBedrockAt(x+i,y+j));
        }
    }

    zSoil = maxSoil-diff*fDiffSoil;

    if (zSoil < 0){
        zSoil = 0;
    }

    T->setSoilAt(x,y,zSoil);

}
