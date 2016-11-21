#include "flowmap.h"
#include <iostream>

Flowmap::Flowmap(Terrain * T, int nbIteration)
{
    this->T = T;
    this->nbIteration = nbIteration;
}

void Flowmap::generateFlowMap() {


    for (int k = 0; k < nbIteration; k++) {
        for (int i = 0; i < T->getWidth(); i++) {
            for (int j = 0; j < T->getLength(); j++) {
                drop(i,j);
                T->addFlowMap(x,y,1.0);
                while (move()) {
                    T->addFlowMap(x,y,1.0);
                }
            }
        }
    }
    float max = 0.0f;
    for (int i = 0; i < T->getWidth(); i++)
        for (int j = 0; j < T->getLength(); j++)
            max = std::max(max,T->getFlowMap(i,j));

    for (int i = 0; i < T->getWidth(); i++)
        for (int j = 0; j < T->getLength(); j++)
            T->setFlowMap(i,j,T->getFlowMap(i,j)/max);
}

void Flowmap::drop(int i, int j) {
    x = i;
    y = j;
}

bool Flowmap::move() {

    float zSoil = T->getSoilLevelAt(x,y);
    float diff = 0.0f;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i != 0 || j != 0) && x+i >= 0 && x+i < T->getWidth() && y+j >= 0 && y+j < T->getLength()) {
                diff += std::max(0.0f,zSoil-T->getSoilLevelAt(x+i,y+j));
            }
        }
    }

    if (diff == 0.0f) {
        return false;
    }
    float r = 0;
    while (r == 0) {
        r = (float)rand()/((((float)RAND_MAX)/diff));
    }


    diff = 0.0f;
    int i = -1;
    int j = -2;

    do {
        j++;
        if (j > 1) {
            j = -1;
            i++;
        }

        if ((i != 0 || j != 0) && x+i >= 0 && x+i < T->getWidth() && y+j >= 0 && y+j < T->getLength()) { 
            diff += std::max(0.0f,zSoil-T->getSoilLevelAt(x+i,y+j));
        }
    } while(diff < r && i < 2);

    if (i >= 2 || !(x+i >= 0 && x+i < T->getWidth() && y+j >= 0 && y+j < T->getLength())) {
        std::cerr << "ERREUR GENERATION FLOWMAP -> "<<x<<","<<y<<" ==> "<<x+i<<","<<y+j<<" ("<<diff<<","<<r<<")\n" << std::flush;

        std::cerr << T->getSoilLevelAt(x-1,y-1) << "\t" << T->getSoilLevelAt(x-1,y) << "\tS" << T->getSoilLevelAt(x-1,y+1) <<"\n" << std::flush;
        std::cerr << T->getSoilLevelAt(x,y-1) << "\t" << T->getSoilLevelAt(x,y) << "\t" << T->getSoilLevelAt(x,y+1) <<"\n" << std::flush;
        std::cerr << T->getSoilLevelAt(x+1,y-1) << "\t" << T->getSoilLevelAt(x+1,y) << "\t" << T->getSoilLevelAt(x+1,y+1) <<"\n" << std::flush;
        return false;
    }

    x = x+i;
    y = y+j;
    return true;
}
