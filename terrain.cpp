#include "terrain.h"
#include <math.h>
#include <QImage>
#include <iostream>
#include <turbulence.h>

Terrain::Terrain(const Point p1, const Point p2, Turbulence T, int length, int width)
{

    std::cout << "Building terrain "<< width <<"x"<< length <<"...\n" << std::flush;
    bedrock = QVector<float>(length*width);
    soil = QVector<float>(length*width);
    water = QVector<float>(length*width);

    a = Point(p1);
    b = Point(p2);

    this->length = length;
    this->width = width;

    for(int i = 0; i < soil.length(); i++){
        soil[i] = 0;
    }


    for(int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            bedrock[i*width+j] = T.eval((b.x()-a.x())*i/length+a.x(),(b.y()-a.y())*j/width+a.y());
        }
    }
}

void Terrain::setSoil() {


}

Mesh Terrain::toMesh() {

    std::cout << "Building Mesh...\n" <<  std::flush;
    Mesh m = Mesh();

    int i = 0;
    for (int j = 0; j < width; j++) {
        m.addVertice(Point((b.x()-a.x())*((float)i/length)+a.x(),(b.y()-a.y())*((float)j/width)+a.y(), a.z()+bedrock[j]+soil[j]));
    }

    for (int i = 1; i < length; i++) {
        int j = 0;

        m.addVertice(Point((b.x()-a.x())*((float)i/length)+a.x(),(b.y()-a.y())*((float)j/width)+a.y(), a.z()+bedrock[i*length]+soil[i*length]));
        for (int j = 1; j < width; j++) {
            std::cout << std::flush;
            m.addVertice(Point((b.x()-a.x())*((float)i/length)+a.x(),(b.y()-a.y())*((float)j/width)+a.y(), a.z()+bedrock[j+i*length]+soil[j+i*length]));
            m.addTriangle(Triangle((i-1)*width+j-1,i*width+j,i*width+j-1));
            m.addTriangle(Triangle((i-1)*width+j-1,(i-1)*width+j,i*width+j));
        }
    }
    return m;
}
