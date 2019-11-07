#ifndef RENDERENGINE_SHAPE_H
#define RENDERENGINE_SHAPE_H

#include "../primitives/geometry.h"

class ShapeIntersectionBundle {
public:
    ShapeIntersectionBundle(float time, const Vector3f &point, const Vector3f &normal) :
            time(time), point(point), normal(normal) {
        assert (!std::isnan(time) && point.IsNotNull() && normal.IsNotNull());
    }

    float time;
    Vector3f point, normal;
};

class Shape {
public:
    virtual ShapeIntersectionBundle *intersect(const Ray &ray, const double &t_min, const double &t_max) const = 0;

    virtual ~Shape() = default;

    Shape() = default;
};


#endif //RENDERENGINE_SHAPE_H
