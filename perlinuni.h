#ifndef PERLINUNI_H
#define PERLINUNI_H

#include <Qimage>
#include <point.h>

/**
 * @brief Permet d'intialiser et d'évaluer une fonction de Perlin.
 */
class PerlinUni
{
public:

    /**
     * @brief Instancie un objet fonction de Perlin.
     * Initialise l'image utilisée par la fonction de Perlin.
     */
    PerlinUni();

    /**
     * @brief Évalue la valeur d'une fonction de Perlin en un point donné.
     * @param x : Abscisse du point à évaluer
     * @param y : Ordonnée du point à évaluer
     * @return Hauteur du point évalué
     */
    float eval(float x, float y);

private:
    QImage img;
};

#endif // PERLINUNI_H
