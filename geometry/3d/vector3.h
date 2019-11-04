#ifndef RENDERENGINE_VECTOR3_H
#define RENDERENGINE_VECTOR3_H

#include <iostream>
#include <cmath>
#include <cassert>

#include "normal3.h"
#include "point3.h"

template<typename T> class Point3;
template<typename T> class Normal3;

template<typename T>
class Vector3 {
public:
    /* Constructors */
    Vector3() { x = y = z = 0; }

    Vector3(T x, T y, T z) : x(x), y(y), z(z) { assert(IsNotNull()); }

    explicit Vector3(const Point3<T> &p) {
        assert(p.IsNotNull());
        x = p.x;
        y = p.y;
        z = p.z;
    }

    explicit Vector3(const Normal3<T> &n) {
        assert(n.IsNotNull());
        x = n.x;
        y = n.y;
        z = n.z;
    }

    T operator[](int i) const {
        assert(i >= 0 && i < 3);
        if (i == 0) return x;
        if (i == 1) return y;
        return z;
    }

    T &operator[](int i) {
        assert(i >= 0 && i < 3);
        if (i == 0) return x;
        if (i == 1) return y;
        return z;
    }

    /* Debug */
    friend std::ostream &operator<<(std::ostream &os, const Vector3<T> &v) {
        os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
        return os;
    }

    bool IsNotNull() const { return !(std::isnan(x) || std::isnan(y) || std::isnan(z)); }

    /* Operators */
    Vector3<T> &operator=(const Vector3<T> &v) {
        assert(v.IsNotNull());
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }

    Vector3<T> operator+(const Vector3<T> &v) const {
        assert(v.IsNotNull());
        return Vector3<T>(x + v.x, y + v.y, z + v.z);
    }

    Vector3<T> &operator+=(const Vector3<T> &v) {
        assert(v.IsNotNull());
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vector3<T> operator-(const Vector3<T> &v) const {
        assert(v.IsNotNull());
        return Vector3<T>(x - v.x, y - v.y, z - v.z);
    }

    Vector3<T> &operator-=(const Vector3<T> &v) {
        assert(v.IsNotNull());
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    Vector3<T> operator*(const T &s) const {
        return Vector3<T>(x * s, y * s, z * s);
    }

    Vector3<T> &operator*=(const T &s) {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    Vector3<T> operator/(const T &s) const {
        assert(s != 0);
        return Vector3<T>(x / s, y / s, z / s);
    }

    Vector3<T> &operator/=(T s) {
        assert(s != 0);
        x /= s;
        y /= s;
        z /= s;
        return *this;
    }

    bool operator==(const Vector3<T> &v) const {
        return x == v.x && y == v.y && z == v.z;
    }

    bool operator!=(const Vector3<T> &v) const {
        return x != v.x || y != v.y || z != v.z;
    }

    float LengthSquared() const {
        return x * x + y * y + z * z;
    }

    float Length() const {
        return std::sqrt(LengthSquared());
    }

    /* Data */
    T x, y, z;

};

typedef Vector3<float> Vector3f;
typedef Vector3<int> Vector3i;

#endif //RENDERENGINE_VECTOR3_H
