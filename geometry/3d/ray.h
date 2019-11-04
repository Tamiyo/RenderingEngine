#ifndef RENDERENGINE_RAY_H
#define RENDERENGINE_RAY_H

#include "point3.h"
#include "vector3.h"

class Ray {
public:
    Point3f origin;
    Vector3f direction;
};

#endif //RENDERENGINE_RAY_H
