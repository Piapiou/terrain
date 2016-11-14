#include "perlinuni.h"
#include <iostream>

PerlinUni::PerlinUni()
{
    img = QImage(":/img/terrain3.png");
}

float PerlinUni::eval(float x, float y) {

    while (x < 0) x += img.width();
    while (y < 0) y += img.height();

    float dx = 1-(x - (int)x);
    float dy = 1-(y - (int)y);

    dx = 3*dx*dx - 2*dx*dx*dx;
    dy = 3*dy*dy - 2*dy*dy*dy;

    // Traitement
    float pixel1 = (float)img.pixelColor((int)x%img.width(),(int)y%img.height()).red()*dx*dy;
    float pixel2 = (float)img.pixelColor((int)(x+1)%img.width(),(int)y%img.height()).red()*(1.0-dx)*dy;
    float pixel3 = (float)img.pixelColor((int)x%img.width(),(int)(y+1)%img.height()).red()*dx*(1.0-dy);
    float pixel4 = (float)img.pixelColor((int)(x+1)%img.width(),(int)(y+1)%img.height()).red()*(1.0-dx)*(1.0-dy);
    float pz = pixel1 + pixel2 + pixel3 + pixel4;

    float pixel = pz/255;

    float seuil = 0.95;

    if (pixel > seuil) {
        pixel = seuil*2-pixel;
    }

    return pixel;
}
