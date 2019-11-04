#ifndef RENDERENGINE_POINT2_H
#define RENDERENGINE_POINT2_H

#include "../base/base.h"

template<typename T>
class Point2 {
public:
    /* Constructors */
    Point2() { x = y = 0; }

    Point2(T x, T y) : x(x), y(y) {}

    T operator[](int i) const {
        assert(i >= 0 && i < 2);
        if (i == 0) return x;
        if (i == 1) return y;
    }

    T &operator[](int i) {
        assert(i >= 0 && i < 2);
        if (i == 0) return x;
        if (i == 1) return y;
    }

    /* Debug */
    friend std::ostream &operator<<(std::ostream &os, const Point2<T> &v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }

    bool IsNotNull() const { return !(std::isnan(x) || std::isnan(y)); }

    /* Operators */
    Point2<T> &operator=(const Point2<T> &p) {
        assert(p.IsNotNull());
        x = p.x;
        y = p.y;
        return *this;
    }

    Point2<T> operator+(const Vector2<T> &v) const {
        assert(v.IsNotNull());
        return Point2<T>(x + v.x, y + v.y);
    }

    Point2<T> &operator+=(const Vector2<T> &v) {
        assert(v.IsNotNull());
        x += v.x;
        y += v.y;
        return *this;
    }

    Vector2<T> operator-(const Point2<T> &p) const {
        assert(p.IsNotNull());
        return Vector2<T>(x - p.x, y - p.y);
    }

    Point2<T> operator-(const Vector2<T> &v) const {
        assert(v.IsNotNull());
        return Point2<T>(x - v.x, y - v.y);
    }

    Point2<T> &operator-=(const Vector2<T> &v) {
        assert(v.IsNotNull());
        x -= v.x;
        y -= v.y;
        return *this;
    }

    Point2<T> &operator+=(const Point2<T> &p) {
        assert(p.IsNotNull());
        x += p.x;
        y += p.y;
        return *this;
    }

    Point2<T> operator+(const Point2<T> &p) const {
        assert(p.IsNotNull());
        return Point2<T>(x + p.x, y + p.y);
    }

    bool operator==(const Point2<T> &p) const {
        assert(p.IsNotNull());
        return x == p.x && y == p.y;
    }

    bool operator!=(const Point2<T> &p) const {
        assert(p.IsNotNull());
        return x != p.x || y != p.y;
    }

    Point2<T> operator-() const { return Point2<T>(-x, -y); }

    T x, y;
};

template<typename T>
inline float Distance(const Point2<T> &p1, const Point2<T> &p2) {
    return (p1 - p2).Length();
}

#endif //RENDERENGINE_POINT2_H
