#ifndef FLOWMAP_H
#define FLOWMAP_H

#include "terrain.h"

class Terrain;

/**
 * Permet d'instancier et de calculer la carte d'écoulement des eaux sur le terrain.
 */
class Flowmap
{
public:

    /**
     * Instancie une carte d'écoulement des eaux.
     * @param T : Le terrain auquel correspond la carte.
     * @param nbIteration : Nombre d'itérations sur lesquelles la carte est générée.
     */
    Flowmap(Terrain * T, int nbIteration);

    /**
     * Génère la carte d'écoulement du terrain.
     * À chaque itération, est calculé pour chaque point du terrain le déplacement de l'eau, jusqu'à aboutir à l'emplacement final des cours d'eau.
     */
    void generateFlowMap();

private:
    void drop(int i, int j);
    bool move();

    Terrain * T;
    int nbIteration;
    int x, y;
};

#endif // FLOWMAP_H
