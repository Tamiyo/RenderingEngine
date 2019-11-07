#ifndef RENDERENGINE_LINMATH_H
#define RENDERENGINE_LINMATH_H

#include <fmt/format.h>
#include <fmt/ostream.h>

#include <cmath>
#include <cassert>

template<typename T>
class Vector3;

template<typename T>
T DotProduct(const Vector3<T> &v1, const Vector3<T> &v2) {
    assert (v1.IsNotNull() && v2.IsNotNull());
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template<typename T>
Vector3<T> CrossProduct(const Vector3<T> &v1, const Vector3<T> &v2) {
    assert (v1.IsNotNull() && v2.IsNotNull());
    T v1x = v1.x, v1y = v1.y, v1z = v1.z;
    T v2x = v2.x, v2y = v2.y, v2z = v2.z;

    return Vector3<T>((v1y * v2z) - (v1z * v2y),
                      (v1z * v2x) - (v1x * v2z),
                      (v1x * v2y) - (v1y * v2x));
}

template<typename T>
Vector3<T> Normalize(const Vector3<T> &v) {
    assert (v.IsNotNull());
    return v / v.Length();
}

#endif //RENDERENGINE_LINMATH_H
