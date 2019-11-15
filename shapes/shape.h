#ifndef RENDERENGINE_SHAPE_H
#define RENDERENGINE_SHAPE_H

#include "../primitives/geometry.h"
#include "../algorithm/bundle.h"

class Shape {
public:
    virtual bool intersect(const Ray &ray, const double &t_min, const double &t_max, ShapeIntersectionBundle &bundle) const = 0;

    virtual ~Shape() = default;

    Shape() = default;
};


#endif //RENDERENGINE_SHAPE_H
