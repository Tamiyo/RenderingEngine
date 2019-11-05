#ifndef RENDERENGINE_GEOMETRY_H
#define RENDERENGINE_GEOMETRY_H

#include <iostream>
#include "linmath.h"

template<typename T>
class Point3 {
public:
    /* Constructors */
    Point3() { x = y = z = 0; }

    Point3(T vv) : x(vv), y(vv), z(vv) { assert(IsNotNull()); }

    Point3(T x, T y, T z) : x(x), y(y), z(z) { assert(IsNotNull()); }

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
    friend std::ostream &operator<<(std::ostream &os, const Point3<T> &v) {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }

    bool IsNotNull() const { return !(std::isnan(x) || std::isnan(y) || std::isnan(z)); }

    /* Operators */
    Point3<T> &operator=(const Point3<T> &p) {
        assert(p.IsNotNull());
        x = p.x;
        y = p.y;
        z = p.z;
        return *this;
    }

    Point3<T> operator+(const Vector3<T> &v) const {
        assert(v.IsNotNull());
        return Point3<T>(x + v.x, y + v.y, z + v.z);
    }

    Point3<T> &operator+=(const Vector3<T> &v) {
        assert(v.IsNotNull());
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vector3<T> operator-(const Point3<T> &p) const {
        assert(p.IsNotNull());
        return Vector3<T>(x - p.x, y - p.y, z - p.z);
    }

    Point3<T> operator-(const Vector3<T> &v) const {
        assert(v.IsNotNull());
        return Point3<T>(x - v.x, y - v.y, z - v.z);
    }

    Point3<T> &operator-=(const Vector3<T> &v) {
        assert(v.IsNotNull());
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    Point3<T> &operator+=(const Point3<T> &p) {
        assert(p.IsNotNull());
        x += p.x;
        y += p.y;
        z += p.z;
        return *this;
    }

    Point3<T> operator+(const Point3<T> &p) const {
        assert(p.IsNotNull());
        return Point3<T>(x + p.x, y + p.y, z + p.z);
    }

    bool operator==(const Point3<T> &p) const {
        assert(p.IsNotNull());
        return x == p.x && y == p.y && z == p.z;
    }

    bool operator!=(const Point3<T> &p) const {
        assert(p.IsNotNull());
        return x != p.x || y != p.y || z != p.z;
    }

    T x, y, z;
};

typedef Point3<float> Point3f;
typedef Point3<int> Point3i;

template<typename T>
class Vector3 {
public:
    /* Constructors */
    Vector3() { x = y = z = 0; }

    Vector3(T vv) : x(vv), y(vv), z(vv) { assert(IsNotNull()); }

    Vector3(T x, T y, T z) : x(x), y(y), z(z) { assert(IsNotNull()); }

    explicit Vector3(const Point3<T> &p) {
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
    Ray(const Vector3f &origin, const Vector3f &direction) : origin(origin), direction(direction) {
        assert(origin.IsNotNull() && direction.IsNotNull());
    }

    Vector3f origin;
    Vector3f direction;
};

#endif //RENDERENGINE_GEOMETRY_H
