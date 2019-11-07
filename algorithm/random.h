#ifndef RENDERENGINE_RANDOM_H
#define RENDERENGINE_RANDOM_H

#include <random>
#include "../primitives/geometry.h"

float GenerateRandomNumber() {
    return rand() / (RAND_MAX + 1.0);
}


Vector3f GenerateRandomVectorOnUnitSphere() {
    Vector3f p;
    do {
        p = (Vector3f(GenerateRandomNumber(), GenerateRandomNumber(), GenerateRandomNumber()) * 2.0) - Vector3f(1.0);
    } while (p.LengthSquared() >= 1.0);
    return p;
}

#endif //RENDERENGINE_RANDOM_H
