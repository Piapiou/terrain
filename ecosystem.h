#ifndef ECOSYSTEM_H
#define ECOSYSTEM_H


#include <QVector>
#include <tree.h>

class Terrain;

/**
 * Représente la couche de végétation du terrain.
 */
class Ecosystem
{
public:

    /**
     * Instancie une couche de végétation.
     */
    Ecosystem();

    /**
     * Initialise la couche de végétation.
     * Insère dans un vecteur d'arbres un certain nombre d'arbres à des positions aléatoires du terrain.
     * Le vecteur d'arbres représente la couche de végétation du terrain.
     * @param n : Nombre d'arbres initiaux.
     * @param T : Terrain auquel correspond la couche de végétation.
     */
    void init(int n, Terrain * T);

    /**
     * Incrémente le cycle de vie de la végétation.
     * Fait progresser l'âge et le niveau de maladie de chaque arbre, et gère leur propagation et leur décès.
     */
    void step();

    /**
     * Ajoute un arbre à la couche de végétation.
     * L'arbre est inséré dans le vecteur d'arbre représentant la couche de végétation.
     * La probabilité que l'arbre soit inséré dans le vecteur est égale à la probabilité d'existence de l'arbre à la position indiquée.
     * Si l'arbre n'a pas la place d'exister à la position indiquée, il n'est pas inséré.
     * @param x : Position en abscisse de l'arbre.
     * @param y : Position en ordonnée de l'arbre.
     * @param age : Âge de l'arbre.
     * @param type : Type de l'arbre.
     */
    void plant(int x, int y, int age, int type);

    /**
     * Génère une image représentant la répartition de la végétation.
     * Chaque type d'arbre est représenté sur la carte par une couleur différente.
     * @param Chemin du dossier d'enregistrement de l'image.
     */
    void exportImg(QString path);

    /**
     * Renvoie un objet Mesh dépendant du vecteur d'arbres.
     * Chaque arbre du vecteur est converti en Mesh, et integré au Mesh gloal renvoyé.
     * @return Un objet Mesh.
     */
    Mesh generateMesh();

private:
    QVector<Tree> VT;
    Terrain * T;
};

#endif // ECOSYSTEM_H
