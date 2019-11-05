#ifndef RENDERENGINE_RAYTRACING_H
#define RENDERENGINE_RAYTRACING_H

#include <vector>
#include "../primitives/geometry.h"
#include "../shapes/shape.h"

bool trace(const Vector3f &origin, const Vector3f &direction, std::vector<Shape *> &shapes, float &tNear,
           const Shape *&hitShape) {
    tNear = INFINITY;
    return false;
}

Vector3f castRay(const Vector3f &origin, const Vector3f &direction, std::vector<Shape *> shapes) {
    Vector3f hitColor = 0;
    const Shape *hitShape = nullptr;
    float t;

    if (trace(origin, direction, shapes, t, hitShape)) {
        Vector3f Phit = origin + direction * t;
        Vector3f Nhit;
    }

    return hitColor;

}

#endif //RENDERENGINE_RAYTRACING_H
