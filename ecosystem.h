#ifndef ECOSYSTEM_H
#define ECOSYSTEM_H


#include <QVector>
#include <tree.h>

class Terrain;

class Ecosystem
{
public:
    Ecosystem();
    void init(int n, Terrain * T);
    void step();
    void exportImg(QString path);
    Mesh generateMesh();

private:
    QVector<Tree> VT;
    Terrain * T;
};

#endif // ECOSYSTEM_H
