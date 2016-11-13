#include "mainwindow.h"
#include <QApplication>
#include "gldisplay.h"
#include "mesh.h"
#include "terrain.h"
#include "turbulence.h"

int main(int argc, char *argv[])
{
    // Pour les TP de maillage et modé
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();

    // Pour les TP de modélisation avancé.

    Turbulence T = Turbulence();
    Terrain ter = Terrain(Point(0.0f,0.0f,0.0f),Point(1000.0f,1000.0f,0.0f),T,300,300);
    ter.initSoil(3.0,1.0);
    //ter.makeFlowMap(2);
    ter.simulateEcosystem(100);

    Mesh m = ter.toMesh();
    m.toOBJ("C:/Users/toshiba/Desktop/test.obj");
    ter.saveHeightImg("C:/Users/toshiba/Desktop/height.png");
    ter.saveSoilImg("C:/Users/toshiba/Desktop/soil.png");
    ter.saveFlowmapImg("C:/Users/toshiba/Desktop/flowMap.png");
    return 0;
}
