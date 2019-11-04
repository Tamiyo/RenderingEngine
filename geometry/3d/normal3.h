#ifndef RENDERENGINE_NORMAL3_H
#define RENDERENGINE_NORMAL3_H

#include "vector3.h"

template<typename T>
class Normal3 {
public:

    /* Constructors */
    Normal3() { x = y = z = 0; }

    Normal3(T x, T y, T z) : x(x), y(y), z(z) { assert(IsNotNull()); }

    explicit Normal3(const Vector3<T> &v) {
        assert(IsNotNull());
        x = v.x;
        y = v.y;
        z = v.z;
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
    friend std::ostream &operator<<(std::ostream &os, const Normal3<T> &n) {
        os << "[" << n.x << ", " << n.y << ", " << n.z << "]";
        return os;
    }

    bool IsNotNull() const { return !(std::isnan(x) || std::isnan(y) || std::isnan(z)); }

    /* Operators */
    Normal3<T> &operator=(const Normal3<T> &n) {
        assert(n.IsNotNull());
        x = n.x;
        y = n.y;
        z = n.z;
        return *this;
    }

    Normal3<T> operator+(const Normal3<T> &n) const {
        assert(n.IsNotNull());
        return Normal3<T>(x + n.x, y + n.y, z + n.z);
    }

    Normal3<T> &operator+=(const Normal3<T> &n) {
        assert(n.IsNotNull());
        x += n.x;
        y += n.y;
        z += n.z;
        return *this;
    }

    Normal3<T> operator-(const Normal3<T> &n) const {
        assert(n.IsNotNull());
        return Normal3<T>(x - n.x, y - n.y, z - n.z);
    }

    Normal3<T> &operator-=(const Normal3<T> &n) {
        assert(n.IsNotNull());
        x -= n.x;
        y -= n.y;
        z -= n.z;
        return *this;
    }

    Normal3<T> operator*(const T &s) const {
        return Normal3<T>(x * s, y * s, z * s);
    }

    Normal3<T> &operator*=(const T &s) {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    Normal3<T> operator/(const T &s) const {
        assert(s != 0);
        return Normal3<T>(x / s, y / s, z / s);
    }

    Normal3<T> &operator/=(T s) {
        assert(s != 0);
        x /= s;
        y /= s;
        z /= s;
        return *this;
    }

    bool operator==(const Normal3<T> &n) const {
        return x == n.x && y == n.y && z == n.z;
    }

    bool operator!=(const Normal3<T> &n) const {
        return x != n.x || y != n.y || z != n.z;
    }

    float LengthSquared() const {
        return x * x + y * y + z * z;
    }

    float Length() const {
        return std::sqrt(LengthSquared());
    }

    T x, y, z;
};

#endif //RENDERENGINE_NORMAL3_H
