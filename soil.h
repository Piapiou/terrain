#ifndef SOIL_H
#define SOIL_H

#include <QVector>
#include <terrain.h>

/**
 * Représente la couche de sédiments du terrain.
 */
class Soil
{
public:
    /**
     * Instancie une couche de sédiments.
     * @param T : Terrain à sédimenter.
     * @param maxSoil : Hauteur maximum de la couche de sédiments.
     * @param facteurDiffSoil : Rapport entre l'inclinaison du terrain et la quantité de sédiments présents.
     */
    Soil(Terrain * T, float maxSoil, float facteurDiffSoil);

    /**
     * Calcule et définit la hauteur des sédiments en un point donné du terrain.
     * @param x : Abscisse du point du terrain.
     * @param y : Ordonnée du point du terrain.
     */
    void setSoil(int x, int y);

private:
    float maxSoil;
    float fDiffSoil;
    Terrain * T;

};

#endif // SOIL_H
