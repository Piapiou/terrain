#ifndef TURBULENCE_H
#define TURBULENCE_H

#include <perlin.h>
#include <QVector>

/**
 * @brief Permet d'intialiser et d'évaluer le cumul de trois fonctions de %Perlin.
 */
class Turbulence
{
public:

    /**
     * @brief Instancie un objet turbulence.
     * Cumule dans un vecteur trois fonctions de %Perlin, respectivement :
     * -> D'amplitude 10 et de fréquence 1/20
     * -> D'amplitude 1 et de fréquence 1/4
     * -> D'amplitude 0,1 et de fréquence 1
     */
    Turbulence();

    /**
     * @brief Évalue la valeur d'une turbulence en un point donné.
     * @param x : Abscisse du point à évaluer
     * @param y : Ordonnée du point à évaluer
     * @return Hauteur du point évalué
     */
    float eval(float x, float y);

private:
    QVector<Perlin> vp;
};

#endif // TURBULENCE_H
