#ifndef PERLIN_H
#define PERLIN_H

#include <perlinuni.h>

/**
 * @brief Permet d'intialiser et d'évaluer une fonction de Perlin, modulée par une amplitude et une fréquence.
 */
class Perlin : public PerlinUni
{
public:

    /**
     * @brief Instancie un objet fonction de Perlin.
     * Initialise l'amplitude et la fréquence à 1.
     */
    Perlin();

    /**
     * @brief Initialise la fonction de Perlin.
     * @param a : Amplitude de la fonction
     * @param f : Fréquence de la fonction
     */
    Perlin(float a, float f);

    /**
     * @brief Évalue la valeur d'une fonction de Perlin en un point donné.
     * @param x : Abscisse du point à évaluer
     * @param y : Profondeur du point à évaluer
     * @return Hauteur du point évalué
     */
    float eval(float x, float y);

private:
    float amp;
    float fre;
};

#endif // PERLIN_H
