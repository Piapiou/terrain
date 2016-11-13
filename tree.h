#ifndef TREE_H
#define TREE_H

#include <mesh.h>

class Tree
{
public:
    Tree();
    Tree(int type, int initAge, int x, int y);
    void life();
    float width();
    int getX();
    int getY();
    void sick();
    int getSickness();
    int getType();
    int strengh();
    Mesh toMesh();

    static const int TYPE_APPLETREE = 0;
    static const int TYPE_PINETREE = 1;
    static const int TYPE_BUSH = 2;

private:
    int type;
    int age;
    int x;
    int y;
    int sickness;
};

#endif // TREE_H
