#ifndef TREE_H
#define TREE_H

#include <mesh.h>

/**
 * Représente un arbre.
 */
class Tree
{
public:

    /**
     * Instancie un arbre.
     */
    Tree();

    /**
     * Instancie un arbre selon ses caractéristiques.
     * @param type : Espèce de l'arbre.
     * @param initAge : Âge initial de l'arbre.
     * @param x : Position en abscisse de l'arbre.
     * @param y : Position en ordonnée de l'arbre.
     */
    Tree(int type, int initAge, int x, int y);

    /**
     * Incrémente le cycle de vie de l'arbre.
     * Incrémente l'âge de l'arbre, et détermine son niveau de maladie selon son espèce et son âge.
     */
    void life();

    /**
     * Renvoie la largeur de l'arbre.
     * La largeur de l'arbre est calculée selon son espèce et son âge.
     * @return La largeur de l'arbre.
     */
    float width();

    /**
     * Renvoie la position en abscisse de l'arbre.
     * @return La position en abscisse de l'arbre.
     */
    int getX();

    /**
     * Renvoie la position en ordonnée de l'arbre.
     * @return La position en ordonnée de l'arbre.
     */
    int getY();

    /**
     * Incrémente le niveau de maladie de l'arbre.
     */
    void sick();

    /**
     * Renvoie le niveau de maladie de l'arbre.
     * @return Le niveau de maladie de l'arbre.
     */
    int getSickness();

    /**
     * Renvoie l'espèce de l'arbre.
     * @return Une constante correspondant à l'espèce de l'arbre.
     */
    int getType();

    /**
     * Renvoie le potentiel de survie de l'arbre.
     * @return Le potentiel de survie de l'arbre.
     */
    int strengh();

    /**
     * Renvoie la probabilité d'existence de l'arbre.
     * La probabilité d'existence correspond aux chances d'un arbre d'exister selon un certain nombre de conditions de terrain.
     * @param height : Altitude du terrain.
     * @param soil : Hauteur de la couche de sédiments.
     * @param flowmap : Taux d'humidité.
     * @return Une probabilité entre 0 et 1.
     */
    float lifeOdds(float height, float soil, float flowmap);

    /**
     * Renvoie un objet Mesh dépendant des caractéristiques de l'arbre.
     * La composition et les paramètres de l'objet Mesh sont déterminées selon la largeur et l'espèce de l'arbre.
     * @return Un objet Mesh.
     */
    Mesh toMesh();

    /**
     * Constante d'espèce désignant un pommier.
     */
    static const int TYPE_APPLETREE = 0;
    /**
     * Constante d'espèce désignant un pin.
     */
    static const int TYPE_PINETREE = 1;
    /**
     * Constante d'espèce désignant un buisson.
     */
    static const int TYPE_BUSH = 2;

private:
    int type;
    int age;
    int x;
    int y;
    int sickness;
};

#endif // TREE_H
