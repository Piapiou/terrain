#ifndef TERRAIN_H
#define TERRAIN_H

#include <QVector>
#include <point.h>
#include <mesh.h>
#include <QImage>
#include <turbulence.h>
#include <flowmap.h>
#include <ecosystem.h>


class Ecosystem;

/**
 * Représente un terrain.
 */
class Terrain
{
public:

    /**
     * Instancie et initialise un terrain.
     * @param p1 : %Point d'extrêmité du terrain.
     * @param p2 : %Point d'extrêmité opposée du terrain.
     * @param T : Focntion de turbulence.
     * @param length : Nombre de subdivisions en longueur.
     * @param width : Nombre de subdivisions en largeur.
     */
    Terrain(const Point p1, const Point p2, Turbulence T, int length, int width);

    /**
     * Initialise la couche de sédiments du terrain.
     * @param maxSoil : Hauteur maximale de la couche de sédiments.
     * @param facteurDiffSoil : Rapport entre l'inclinaison du terrain et la quantité de sédiments présents.
     */
    void initSoil(float maxSoil, float facteurDiffSoil);

    /**
     * Définit le niveau de sédiments en un point spécifique du terrain.
     * @param i : Abscisse du point à modifier.
     * @param j : Ordonée du point à modifier.
     * @param h : Niveau de sédiments à affecter.
     */
    void setSoilAt(int i, int j, float h);

    /**
     * Génère une carte d'écoulement des eaux pour le terrain.
     * @param nbIteration : Nombre d'itérations sur lesquelles s'effectue la génération.
     */
    void makeFlowMap(int nbIteration);

    /**
     * Augmente le niveau d'humidité en un point spécifique du terrain.
     * @param x : Abscisse du point à modifier.
     * @param y : Ordonée du point à modifier.
     * @param z : Niveau d'humidité à ajouter.
     */
    void addFlowMap(int x, int y, float z);

    /**
     * Renvoie le niveau d'humidité en un point spécifique du terrain.
     * @param x : Abscisse du point à évaluer.
     * @param y : Ordonée du point à évaluer.
     * @return Le niveau d'humidité.
     */
    float getFlowMap(int x, int y);

    /**
     * Définit le niveau d'humidité en un point spécifique du terrain.
     * @param x : Abscisse du point à modifier.
     * @param y : Ordonée du point à modifier.
     * @param z : Niveau d'humidité à affecter.
     */
    void setFlowMap(int x, int y, float z);

    /**
     * Renvoie le nombre de subdivisions en largeur.
     * @return Le nombre de subdivisions en largeur.
     */
    int getWidth();

    /**
     * Renvoie le nombre de subdivisions en longueur.
     * @return Le nombre de subdivisions en longueur.
     */
    int getLength();

    /**
     * Renvoie la largeur d'une subdivision en largeur.
     * @return La largeur d'une subdivision en largeur.
     */
    float getWidthRatio();

    /**
     * Renvoie la largeur d'une subdivision en longueur.
     * @return La largeur d'une subdivision en longueur.
     */
    float getLengthRatio();

    /**
     * Renvoie la hauteur de la bedrock en un point spécifique du terrain.
     * @param i : Abscisse du point à évaluer.
     * @param j : Ordonée du point à évaluer.
     * @return La hauteur de la bedrock.
     */
    float getBedrockAt(int i, int j);

    /**
     * Renvoie la hauteur de la couche de sédiments en un point spécifique du terrain.
     * @param i : Abscisse du point à évaluer.
     * @param j : Ordonée du point à évaluer.
     * @return La hauteur de la couche de sédiments.
     */
    float getSoilAmountAt(int i, int j);

    /**
     * Renvoie la hauteur de la bedrock cumulée à la couche de sédiments en un point spécifique du terrain.
     * @param i : Abscisse du point à évaluer.
     * @param j : Ordonée du point à évaluer.
     * @return La hauteur de la bedrock cumulée à la couche de sédiments.
     */
    float getSoilLevelAt(int i, int j);

    /**
     * Génère une couche de végétation pour le terrain.
     * @param time : Nombre d'itérations sur lesquelles s'effectue la génération.
     * @param nbTree : Nombre d'arbres à générer.
     */
    void simulateEcosystem(int time, int nbTree);

    /**
     * Renvoie le premier point d'extrêmité du terrain.
     * @return Le premier point d'extrêmité du terrain.
     */
    Point* getOrigin();

    /**
     * Renvoie un objet Mesh représentant les couches de bedrock et de sédiments.
     * La composition et l'apparence de l'objet Mesh dépendent des caractéristiques du terrain, de sa couche de bedrock, et de sa couche de sédiments.
     * @return Un objet Mesh.
     */
    Mesh toMesh();

    /**
     * Renvoie un objet Mesh représentant la couche de bedrock.
     * La composition et l'apparence de l'objet Mesh dépendent des caractéristiques du terrain et de sa couche de bedrock.
     * @return Un objet Mesh.
     */
    Mesh bedRockMesh();

    /**
     * Renvoie un objet Mesh représentant la couche de végétation.
     * La composition et l'apparence de l'objet Mesh dépendent des caractéristiques du terrain et de sa couche de végétation.
     * @return Un objet Mesh.
     */
    Mesh getESMesh();

    /**
     * Génère une image représentant les altitudes de la couche de bedrock.
     * Les altitudes élevées sont représentées sur l'image générée par des zones claires, et les altitudes basses par des zones sombres.
     * @param s : Chemin du dossier d'enregistrement de l'image.
     */
    void saveHeightImg(QString s);

    /**
     * Génère une image représentant le niveau de la couche de sédiments.
     * Les zones rouges de l'image indiquent la présence de sédiments ; plus la zone est sombre, moins le niveau de sédiments est élevé.
     * @param s : Chemin du dossier d'enregistrement de l'image.
     */
    void saveSoilImg(QString s);

    /**
     * Génère une image représentant l'écoulement des eaux sur le terrain.
     * Les zones bleues de l'image indiquent la présence d'humidité ; plus la zone est sombre, moins le niveau d'humidité est élevé.
     * @param s
     */
    void saveFlowmapImg(QString s);

private:
    QVector<float> bedrock;
    QVector<float> soil;
    QVector<float> flowmap;
    Point a;
    Point b;
    int width;
    int length;
    float zMin;
    float zMax;
    Ecosystem es;

};


#endif // TERRAIN_H
