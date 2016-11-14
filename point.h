#ifndef POINT_H
#define POINT_H

#include <QVector3D>

/**
 * Représente un Point dans l'espace.
 */
class Point : public QVector3D
{
public:

    /**
     * Instancie un Point dans l'espace.
     */
    Point();

    /**
     * Instancie un Point dans l'espace selon un vecteur à trois dimensions.
     * @param p : Vecteur à 3 dimensions (abscisse, profondeur, ordonnée)
     */
    Point(const QVector3D p);

    /**
     * Instancie un Point dans l'espace selon trois coordonnées
     * @param x : Abscisse du point
     * @param y : Profondeur du point
     * @param z : Ordonnée du point
     */
    Point(float x, float y, float z);

};

#endif // POINT_H
