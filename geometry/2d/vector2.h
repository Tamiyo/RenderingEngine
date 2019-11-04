#ifndef RENDERENGINE_VECTOR2_H
#define RENDERENGINE_VECTOR2_H

#include "../base/base.h"

template<typename T>
class Vector2 {
public:
    /* Constructors */
    Vector2() { x = y = 0; }

    Vector2(T x, T y) : x(x), y(y) {}

    T operator[](int i) const {
        assert(i >= 0 && i < 2);
        if (i == 0) return x;
        else return y;
    }

    T &operator[](int i) {
        assert(i >= 0 && i < 2);
        if (i == 0) return x;
        else return y;
    }

    /* Debug */
    friend std::ostream &operator<<(std::ostream &os, const Vector2<T> &v) {
        os << "[" << v.x << ", " << v.y << "]";
        return os;
    }

    bool IsNotNull() const { return !(std::isnan(x) || std::isnan(y)); }

    /* Operators */
    Vector2<T> &operator=(const Vector2<T> &v) {
        assert(v.IsNotNull());
        x = v.x;
        y = v.y;
        return *this;
    }

    Vector2<T> operator+(const Vector2<T> &v) const {
        assert(v.IsNotNull());
        return Vector2<T>(x + v.x, y + v.y);
    }

    Vector2<T> &operator+=(const Vector2<T> &v) {
        assert(v.IsNotNull());
        x += v.x;
        y += v.y;
        return *this;
    }

    Vector2<T> operator-(const Vector2<T> &v) const {
        assert(v.IsNotNull());
        return Vector2<T>(x - v.x, y - v.y);
    }

    Vector2<T> &operator-=(const Vector2<T> &v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    Vector2<T> operator*(const T &s) const {
        return Vector3<T>(x * s, y * s);
    }

    Vector2<T> &operator*=(const T &s) {
        x *= s;
        y *= s;
        return *this;
    }

    Vector2<T> operator/(const T &s) const {
        return Vector2<T>(x / s, y / s);
    }

    Vector2<T> &operator/=(const T &s) {
        x /= s;
        y /= s;
        return *this;
    }

    bool operator==(const Vector2<T> &v) const {
        return x == v.x && y == v.y;
    }

    bool operator!=(const Vector2<T> &v) const {
        return x != v.x || y != v.y;
    }

    float LengthSquared() const {
        return x * x + y * y;
    }

    float Length() const {
        return std::sqrt(LengthSquared());
    }

    /* Data */
    T x, y;

};

template<typename T>
inline Vector2<T>

Normalize(const Vector2<T> &v) {
    return v / v.Length();
}

template<typename T>
inline T MinComponent(const Vector2<T> &v) {
    return std::min(v.x, v.y);
}

template<typename T>
inline T MaxComponent(const Vector2<T> &v) {
    return std::max(v.x, v.y);
}

template<typename T>
inline int MaxDimension(const Vector2<T> &v) {
    return (v.x > v.y) ? 0 : 1;
}

template<typename T>
inline T DotProduct(const Vector2<T> &v1, const Vector2<T> &v2) {
    return v1.x * v2.x + v1.y * v2.y;
}


#endif //RENDERENGINE_VECTOR2_H
