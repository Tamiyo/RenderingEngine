#ifndef RENDERENGINE_VECTOR2_H
#define RENDERENGINE_VECTOR2_H

#include <iostream>
#include <cmath>
#include <cassert>

#include "point2.h"

template<typename T> class Point2;

template<typename T>
class Vector2 {
public:
    /* Constructors */
    Vector2() { x = y = 0; }

    Vector2(T x, T y) : x(x), y(y) { assert(IsNotNull()); }

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
        return Vector2<T>(x * s, y * s);
    }

    Vector2<T> &operator*=(const T &s) {
        x *= s;
        y *= s;
        return *this;
    }

    Vector2<T> operator/(const T &s) const {
        assert(s != 0);
        return Vector2<T>(x / s, y / s);
    }

    Vector2<T> &operator/=(const T &s) {
        assert(s != 0);
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

typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;

#endif //RENDERENGINE_VECTOR2_H
