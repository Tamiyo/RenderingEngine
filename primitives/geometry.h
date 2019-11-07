#ifndef RENDERENGINE_GEOMETRY_H
#define RENDERENGINE_GEOMETRY_H

#include <iostream>
#include "linmath.h"

#include <fmt/format.h>
// This import is needed to allow for overrided ostream operators
// (according to {fmt}), but it does not directly do anything.
#include <fmt/ostream.h>

template<typename T>
class Vector3 {
public:
    /* Constructors */
    Vector3() { x = y = z = 0; }

    explicit Vector3(T vv) : x(vv), y(vv), z(vv) { assert(IsNotNull()); }

    Vector3(T x, T y, T z) : x(x), y(y), z(z) {
//        fmt::print("{}, {}, {}\n", x, y, z);
        assert(IsNotNull());
    }

    Vector3(const Vector3<T> &p) {
        assert(p.IsNotNull());
        x = p.x;
        y = p.y;
        z = p.z;
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


    /* Operators */
    Vector3<T> &operator=(const T &s) {
        assert(!std::isnan(s));
        x = x * s;
        y = y * s;
        z = z * s;
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

    Vector3<T> operator*(const Vector3<T> &v) const {
        return Vector3<T>(x * v.x, y * v.y, z * v.z);
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

    Vector3<T> operator-() const { return Vector3<T>(-x, -y, -z); }

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

class Ray {
public:
    Ray() {
        origin = direction = 0;
    }

    Ray(const Vector3f &origin, const Vector3f &direction) : origin(origin), direction(direction) {
        assert(origin.IsNotNull() && direction.IsNotNull());
    }

    Vector3f pointOnRayAtTime(float time) const { return origin + direction * time; }

    Vector3f origin;
    Vector3f direction;
};

#endif //RENDERENGINE_GEOMETRY_H
