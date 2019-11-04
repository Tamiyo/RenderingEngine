#ifndef RENDERENGINE_VECTOR3_H
#define RENDERENGINE_VECTOR3_H

#include "../base/base.h"

template<typename T>
class Vector3 {
public:
    /* Constructors */
    Vector3() { x = y = z = 0; }

    Vector3(T x, T y, T z) : x(x), y(y), z(z) {}

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
        return Vector3<T>(x / s, y / s, z / s);
    }

    Vector3<T> &operator/=(T s) {
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

template<typename T>
inline T DotProduct(const Vector3<T> &v1, const Vector3<T> &v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template<typename T>
inline Vector3<T> CrossProduct(const Vector3<T> &v1, const Vector3<T> &v2) {
    T v1x = v1.x, v1y = v1.y, v1z = v1.z;
    T v2x = v2.x, v2y = v2.y, v2z = v2.z;

    return Vector3<T>((v1y * v2z) - (v1z * v2y),
                      (v1z * v2x) - (v1x * v2z),
                      (v1x * v2y) - (v1y * v2x));
}

template<typename T>
inline Vector3<T> Normalize(const Vector3<T> &v) {
    return v / v.Length();
}

template<typename T>
inline T MinComponent(const Vector3<T> &v) {
    return std::min(v.x, std::min(v.y, v.z));
}

template<typename T>
inline T MaxComponent(const Vector3<T> &v) {
    return std::max(v.x, std::max(v.y, v.z));
}

template<typename T>
inline int MaxDimension(const Vector3<T> &v) {
    return (v.x > v.y) ? ((v.x > v.z) ? 0 : 2) :
           ((v.y > v.z) ? 1 : 2);
}

#endif //RENDERENGINE_VECTOR3_H
