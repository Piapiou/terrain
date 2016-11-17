
#include <QApplication>
#include "mesh.h"
#include "terrain.h"
#include "turbulence.h"

int main(int argc, char *argv[])
{

    Turbulence T = Turbulence();
    float sizeDistance = 1000.0;
    int sizePoint = 750;

    Terrain ter = Terrain(Point(0.0f,0.0f,0.0f),Point(sizeDistance,sizeDistance,0.0f),T,sizePoint,sizePoint);
    ter.initSoil(3.0,((float)sizePoint/sizeDistance)*1.5);
    ter.makeFlowMap(3);
    ter.simulateEcosystem(50,1000);

    ter.toMesh().toOBJ("C:/Users/toshiba/Desktop/test.obj");
    ter.bedRockMesh().toOBJ("C:/Users/toshiba/Desktop/BR.obj");
    ter.getESMesh().toOBJ("C:/Users/toshiba/Desktop/ES.obj");
    ter.saveHeightImg("C:/Users/toshiba/Desktop/height.png");
    ter.saveSoilImg("C:/Users/toshiba/Desktop/soil.png");
    ter.saveFlowmapImg("C:/Users/toshiba/Desktop/flowMap.png");
    return 0;
}
