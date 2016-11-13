#include <terrain.h>
#include <soil.h>
#include <math.h>
#include <QImage>
#include <iostream>
#include <turbulence.h>

Terrain::Terrain(const Point p1, const Point p2, Turbulence T, int length, int width)
{
    std::cout << "Building terrain "<< width <<"x"<< length <<"...\n" << std::flush;
    bedrock = QVector<float>(length*width);
    soil = QVector<float>(length*width);
    flowmap = QVector<float>(length*width);
    es = Ecosystem();

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

void Terrain::initSoil(float maxSoil, float facteurDiffSoil) {

    std::cout << "Set soil...\n" << std::flush;
    Soil s = Soil(this, maxSoil, facteurDiffSoil);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            s.setSoil(i,j);
        }
    }
}

void Terrain::makeFlowMap(int nbIteration) {

    std::cout << "Set flowmap...\n" << std::flush;
    Flowmap flow = Flowmap(this,nbIteration);
    flow.generateFlowMap();
}

void Terrain::addFlowMap(int x, int y, float z) {
    flowmap[x*width+y] += z;
}

float Terrain::getFlowMap(int x, int y) {
    return flowmap[x*width+y];
}

void Terrain::setFlowMap(int x, int y, float z) {
    flowmap[x*width+y] = z;
}

int Terrain::getWidth() {
    return width;
}

int Terrain::getLength() {
    return length;
}

float Terrain::getWidthRatio() {
    return std::abs(a.x()-b.x())/width;
}

float Terrain::getLengthRatio() {
    return std::abs(a.y()-b.y())/length;
}

void Terrain::setSoilAt(int i, int j, float h) {
    soil[i*width+j] = h;    
}

float Terrain::getBedrockAt(int i, int j) {
    return bedrock[i*width+j];
}

float Terrain::getSoilAmountAt(int i, int j) {
    return soil[i*width+j];
}

float Terrain::getSoilLevelAt(int i, int j) {
    return bedrock[i*width+j]+soil[i*width+j];
}

Point* Terrain::getOrigin() {
    return &a;
}

void Terrain::simulateEcosystem(int time) {

    std::cout <<"Start generating Ecosystem\n" << std::flush;
    es.init(1000,this);
    es.exportImg(QString::asprintf("C:/Users/toshiba/Desktop/ES/eco0.bmp"));

    std::cout <<"Simulating Ecosystem\n" << std::flush;
    for (int i = 0; i < time; i++) {
        es.step();
        if (i%10 == 9)
            es.exportImg(QString::asprintf("C:/Users/toshiba/Desktop/ES/eco%d.bmp",i+1));
    }
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

void Terrain::saveHeightImg(QString s) {

    float max = 0.0;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            max = std::max(max,bedrock[i*width+j]+soil[i*width+j]);
        }
    }

    std::cout << "Export height img...\n" <<  std::flush;
    QImage img = QImage(length,width,QImage::Format_RGB32);

    for(int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            img.setPixelColor(i,j,QColor((bedrock[i*width+j]+soil[i*width+j])/max*255,(bedrock[i*width+j]+soil[i*width+j])/max*255,(bedrock[i*width+j]+soil[i*width+j])/max*255));
        }
    }
    img.save(s);
}

void Terrain::saveSoilImg(QString s) {

    std::cout << "Export Soil img...\n" <<  std::flush;

    QImage img = QImage(length,width,QImage::Format_RGB32);

    for(int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            img.setPixelColor(i,j,QColor(soil[i*width+j],0,0));
        }
    }
    img.save(s);
}

void Terrain::saveFlowmapImg(QString s) {

    std::cout << "Export flowmap img...\n" <<  std::flush;

    QImage img = QImage(length,width,QImage::Format_RGB32);

    for(int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            img.setPixelColor(i,j,QColor(0,0,flowmap[i*width+j]*255));
        }
    }
    img.save(s);
}
