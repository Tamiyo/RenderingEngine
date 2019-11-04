#ifndef RENDERENGINE_ARITHMETIC_H
#define RENDERENGINE_ARITHMETIC_H

#include "2d/point2.h"
#include "2d/vector2.h"
#include "3d/vector3.h"
#include "3d/point3.h"
#include "3d/normal3.h"


template<typename T>
inline T DotProduct(const Vector3<T> &v1, const Vector3<T> &v2) {
    assert (v1.IsNotNull() && v2.IsNotNull());
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template<typename T>
inline T DotProduct(const Vector2<T> &v1, const Vector2<T> &v2) {
    assert (v1.IsNotNull() && v2.IsNotNull());
    return v1.x * v2.x + v1.y * v2.y;
}

template<typename T>
inline T DotProduct(const Vector3<T> &v, const Normal3<T> &n) {
    assert (v.IsNotNull() && n.IsNotNull());
    return v.x * n.x + v.y * n.y + v.z * n.z;
}

template<typename T>
inline T DotProduct(const Normal3<T> &n, const Vector3<T> &v) {
    assert (v.IsNotNull() && n.IsNotNull());
    return v.x * n.x + v.y * n.y + v.z * n.z;
}

template<typename T>
inline T DotProduct(const Normal3<T> &n1, const Normal3<T> &n2) {
    assert (n1.IsNotNull() && n2.IsNotNull());
    return n1.x * n2.x + n1.y * n2.y + n1.z * n2.z;
}

template<typename T>
inline Vector3<T> CrossProduct(const Vector3<T> &v1, const Vector3<T> &v2) {
    assert (v1.IsNotNull() && v2.IsNotNull());
    T v1x = v1.x, v1y = v1.y, v1z = v1.z;
    T v2x = v2.x, v2y = v2.y, v2z = v2.z;

    return Vector3<T>((v1y * v2z) - (v1z * v2y),
                      (v1z * v2x) - (v1x * v2z),
                      (v1x * v2y) - (v1y * v2x));
}

template<typename T>
inline Vector3<T> Normalize(const Vector3<T> &v) {
    assert (v.IsNotNull());
    return v / v.Length();
}

template<typename T>
inline Vector2<T> Normalize(const Vector2<T> &v) {
    assert (v.IsNotNull());
    return v / v.Length();
}

template<typename T>
inline T MinComponent(const Vector3<T> &v) {
    assert (v.IsNotNull());
    return std::min(v.x, std::min(v.y, v.z));
}

template<typename T>
inline T MinComponent(const Vector2<T> &v) {
    assert (v.IsNotNull());
    return std::min(v.x, v.y);
}

template<typename T>
inline T MaxComponent(const Vector3<T> &v) {
    assert (v.IsNotNull());
    return std::max(v.x, std::max(v.y, v.z));
}

template<typename T>
inline T MaxComponent(const Vector2<T> &v) {
    assert (v.IsNotNull());
    return std::max(v.x, v.y);
}

template<typename T>
inline int MaxDimension(const Vector3<T> &v) {
    assert (v.IsNotNull());
    return (v.x > v.y) ? ((v.x > v.z) ? 0 : 2) :
           ((v.y > v.z) ? 1 : 2);
}

template<typename T>
inline int MaxDimension(const Vector2<T> &v) {
    assert (v.IsNotNull());
    return (v.x > v.y) ? 0 : 1;
}

template<typename T>
inline float Distance(const Point3<T> &p1, const Point3<T> &p2) {
    assert (p1.IsNotNull() && p2.IsNotNull());
    return (p1 - p2).Length();
}


template<typename T>
inline float Distance(const Point2<T> &p1, const Point2<T> &p2) {
    assert (p1.IsNotNull() && p2.IsNotNull());
    return (p1 - p2).Length();
}


#endif //RENDERENGINE_ARITHMETIC_H
