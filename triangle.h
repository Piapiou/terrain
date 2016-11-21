#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QVector3D>
#include <point.h>

/**
 * Représente un triangle dans l'espace.
 */
class Triangle
{
public:

    /**
     * Instancie un triangle dans l'espace.
     */
    Triangle();

    /**
     * Instancie un triangle dans l'espace selon trois indices.
     * Chaque indice corrsepond à un point du vecteur de l'ensemble des points.
     */
    Triangle(int i1, int i2, int i3);

    /**
     * Renvoit l'indice du premier sommet du triangle.
     * L'indice correspond à un point du vecteur de l'ensemble des points.
     */
    int x();

    /**
     * Renvoit l'indice du second sommet du triangle.
     * L'indice correspond à un point du vecteur de l'ensemble des points.
     */
    int y();

    /**
     * Renvoit l'indice du troisème sommet du triangle.
     * L'indice correspond à un point du vecteur de l'ensemble des points.
     */
    int z();

    /**
     * Définission de l'affectation d'un triangle.
     * @param t : Triangle à affecter.
     * @return Un triange.
     */
    Triangle operator=(Triangle t);

    /**
     * Définit l'indice du point opposé du premier triangle adjacent.
     * L'indice doit correspondre à un point du vecteur de l'ensemble des points.
     * @param i : Indice du point opposé
     */
    void setAdj1(int i);

    /**
     * Définit l'indice du point opposé du deuxième triangle adjacent.
     * L'indice doit correspondre à un point du vecteur de l'ensemble des points.
     * @param i : Indice du point opposé
     */
    void setAdj2(int i);

    /**
     * Définit l'indice du point opposé du troisième triangle adjacent.
     * L'indice doit correspondre à un point du vecteur de l'ensemble des points.
     * @param i : Indice du point opposé
     */
    void setAdj3(int i);

    /**
     * Retourne le point opposé d'un triangle adjacent
     * @param nt : Indice du triangle adjacent
     * @return L'indice du point opposé du triangle adjacent
     */
    int getAdj(int nt);
private:
    int p1, p2, p3;
    int adj1, adj2, adj3;
};

#endif // TRIANGLE_H
