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
        assert(IsNotNull());
    }

    Vector3(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {
        assert(IsNotNull());
    }

    Vector3(const Vector3<T> &p) {
        assert(p.IsNotNull());
        x = p.x;
        y = p.y;
        z = p.z;
        w = p.w;
    }

    T operator[](int i) const {
        assert(i >= 0 && i < 4);
        if (i == 0) return x;
        if (i == 1) return y;
        if (i == 2) return z;
        return w;
    }

    T &operator[](int i) {
        assert(i >= 0 && i < 4);
        if (i == 0) return x;
        if (i == 1) return y;
        if (i == 2) return z;
        return w;
    }

    /* Debug */
    friend std::ostream &operator<<(std::ostream &os, const Vector3<T> &v) {
        os << "[" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << "]";
        return os;
    }

    bool IsNotNull() const { return !(std::isnan(x) || std::isnan(y) || std::isnan(z)); }


    Vector3<T> &operator=(const Vector3<T> &v) {
        assert(v.IsNotNull());
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
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
    T w = 1;

};

typedef Vector3<float> Vector3f;
typedef Vector3<int> Vector3i;

template<typename T>
class Matrix4 {
public:
    /* Constructors */
    Matrix4() { m1 = m2 = m3 = m4 = 0; }

//    explicit Matrix4(T vv) : m1(vv), m2(vv), m3(vv), m4(vv) { assert(IsNotNull()); }

    Matrix4(Vector3<T> x, Vector3<T> y, Vector3<T> z, Vector3<T> w) {
        m1 = x;
        m2 = y;
        m3 = z;
        m4 = w;
        assert(IsNotNull());
    }

    /* Debug */
    bool IsNotNull() const { return m1.IsNotNull() && m2.IsNotNull() && m3.IsNotNull() && m4.IsNotNull(); }

    /* Operators */
    Vector3<T> operator*(const Vector3<T> &v) const {
        float a = DotProduct4(m1, v);
//        fmt::print("{} DOT {} = {}\n", m1, v, a);
        float b = DotProduct4(m2, v);
        float c = DotProduct4(m3, v);
        float d = DotProduct4(m4, v);


        Vector3<T> result(a / d, b / d, c / d, 1);

        return result;
    }

    Vector3<T> m1;
    Vector3<T> m2;
    Vector3<T> m3;
    Vector3<T> m4;
};

typedef Matrix4<float> Matrix4f;

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
