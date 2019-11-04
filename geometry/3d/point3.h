#ifndef RENDERENGINE_POINT3_H
#define RENDERENGINE_POINT3_H

#include "../base/base.h"

template<typename T>
class Point3 {
public:
    /* Constructors */
    Point3() { x = y = z = 0; }

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


#endif //RENDERENGINE_POINT3_H
