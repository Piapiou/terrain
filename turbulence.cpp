#include "turbulence.h"
#include <iostream>

Turbulence::Turbulence()
{
    vp = QVector<Perlin>();
    vp.append(Perlin(100.0 ,1.0/100.0)); // COMMENT CA MARCHE : Premier paramètre : Hauteur max de la heightmap sur cette couche
                                         //                     Deuxième paramètre : Fréquence de récupération de données dans le bruit
                                         //                        A SAVOIR : 1/X -> X Correspond Au nombre de metres par valeur de la fonction de bruit
    vp.append(Perlin(10.0  ,1.0/20.0));
    vp.append(Perlin(1.0   ,1.0/4.0));
    vp.append(Perlin(0.1   ,1.0/1.0));
}

float Turbulence::eval(float x, float y) {

    float z = 0;
    for (int i = 0; i < vp.length(); i++) {
        z += vp[i].eval(x,y);
    }
    return z;
}
