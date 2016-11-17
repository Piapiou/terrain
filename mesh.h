#ifndef MESH_H
#define MESH_H

#include <QMainWindow>
#include <QObject>
#include <QVector>
#include <point.h>
#include <QMatrix4x4>
#include <triangle.h>
#include <QSharedDataPointer>
#include <QWidget>

/**
 * Représente un maillage d'objet tridimensionnel
 */
class Mesh
{
public:
    /**
     * Instancie un maillage.
     */
    Mesh();

    /**
     * Instancie un clone d'un maillage existant.
     */
    Mesh(const Mesh &);

    /**
     * Instancie un maillage à partir d'un fichier externe.
     * @param fileName : Chemin du fichier à importer.
     */
    Mesh(QString fileName);

    /**
     * Instancie le maillage d'un parallélépipède rectangle.
     * La génération se fait à partir de deux points opposés du parallélépipède.
     * @param p1 : Premier point d'extrémité du parallélépipède.
     * @param p2 : Deuxième point d'extrémité du parallélépipède.
     * @return Le maillage d'un parallélépipède rectangle.
     */
    static Mesh makeBox(const Point p1, const Point p2);

    /**
     * Instancie le maillage d'une sphère
     * @param center : Centre de la sphère.
     * @param rayon : Rayon de la sphère.
     * @param pointByArc : Nombre de points composant chaque arc de cercle.
     * @return Le maillage d'une sphère.
     */
    static Mesh makeSphere(const Point center, float rayon, int pointByArc);

    /**
     * Instancie le maillage d'un cylindre.
     * @param center : Centre de la base du cylindre.
     * @param height : Hauteur du cylindre.
     * @param rayon : Rayon de la base du cylidnre.
     * @param pointByArc : Nombre de points composant chaque arc de cercle.
     * @return Le maillage d'un cylidnre.
     */
    static Mesh makeCylinder(const Point center, float height, float rayon, int pointByArc);

    /**
     * Instancie le maillage d'un cône
     * @param center : Centre de la base du cône.
     * @param height : Hauteur du cône.
     * @param rayon : Rayon de la base du cône.
     * @param pointByArc : Nombre de points composant chaque arc de cercle.
     * @return
     */
    static Mesh makeCone(const Point center, float height, float rayon, int pointByArc);

    /**
     * Définition de l'affectation d'un maillage.
     * @return Un maillage.
     */
    Mesh operator=(const Mesh &);

    /**
     * Renvoie le centre de gravité du maillage.
     * @return Le centre de gravité du maillage.
     */
    Point getMiddle();

    /**
     * Détruit une instance de maillage.
     */
    ~Mesh();

    /**
     * Renvoie le vecteur de sommets du maillage.
     * @return Un vecteur de Point.
     */
    QVector<Point> * getVertices();

    /**
     * Renvoie le vecteur de triangles du maillage.
     * @return Un vecteur de Triangle.
     */
    QVector<Triangle> * getTriangles();

    /**
     * Ajoute un sommet au vecteur de sommets du maillage.
     * @param v : Un sommet.
     */
    void addVertice(Point v);

    /**
     * Ajoute un sommet au vecteur de triangles du maillage.
     * @param t : Un triangle.
     */
    void addTriangle(Triangle t);

    /**
     * Évalue la distance du maillage à un point.
     * @param p : %Point.
     * @return La distance du maillage au point.
     */
    float distance(const Point p);

    /**
     * Effectue une translation du maillage selon un vecteur tridimensionnel.
     * @param v : Un vecteur tridimensionnel.
     */
    void translate(const Point v);

    /**
     * Effectue une rotation du mailage selon une matrice de rotation.
     * @param m : Matrice de rotation.
     */
    void rotate(const QMatrix4x4 m);

    /**
     * Redimensionne le maillage selon une échelle unique.
     * @param scale : Échelle de redimensionnement.
     */
    void scale(float scale);

    /**
     * Redimensionne le maillage selon un vecteur tridimensionnel.
     * Chaque dimension du vecteur correspond à l'échelle du redimensionnement dans la dimension correspondante.
     * @param scale : Vecteur tridimensionnel.
     */
    void scale(const Point scale);

    /**
     * Permet de fusionner deux maillages.
     * Le maillage passé en paramètre est intégré au maillage actuel.
     * Les nouveaux sommets et triangles sont ajoutés au vecteur de sommets et de triangles.
     * @param m : Maillage à intégrer.
     */
    void merge(Mesh m);

    /**
     * Définit les adjacences de chaque triangle du vecteur de triangles du maillage.
     */
    void setAdjTri();

    /**
     * Convertit et enregistre le maillage sous forme d'un fichier OBJ.
     * @param filePath : Chemin du fichier OBJ à exporter.
     */
    void toOBJ(QString filePath);

private:
    QVector<Point> vertices;
    QVector<Triangle> triangles;
};

#endif // MESH_H
