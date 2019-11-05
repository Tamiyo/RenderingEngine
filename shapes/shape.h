#ifndef RENDERENGINE_SHAPE_H
#define RENDERENGINE_SHAPE_H

#include "../primitives/geometry.h"

class Shape {
public:
    virtual bool intersect(const Ray &ray, double &time) const = 0;

    virtual ~Shape() = default;

    Shape() = default;
};

#endif //RENDERENGINE_SHAPE_H
