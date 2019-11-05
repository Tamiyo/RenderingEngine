#ifndef RENDERENGINE_INTERSECTION_H
#define RENDERENGINE_INTERSECTION_H

#include "../primitives/geometry.h"

bool intersectPlane(const Vector3f &n, const Vector3f &p0, const Vector3f &l0, const Vector3f &l, float &t) {
    float denominator = DotProduct(n, l);
    if (denominator > 1e-6) {
        Vector3f p0l0 = p0 - l0;
        t = DotProduct(p0l0, n) / denominator;
        return (t >= 0);
    }

    return false;
}

bool intersectDisk(const Vector3f &n, const Vector3f &p0, const float &radius, const Vector3f &l0, const Vector3f &l) {
    float t = 0;
    if (intersectPlane(n, p0, l0, l, t)) {
        Vector3f p = l0 + l * t;
        Vector3f v = p - p0;
        float d2 = DotProduct(v, v);
        return (sqrtf(d2) <= radius);
    }

    return false;
}

#endif //RENDERENGINE_INTERSECTION_H
