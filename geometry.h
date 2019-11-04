#ifndef RENDERENGINE_GEOMETRY_H
#define RENDERENGINE_GEOMETRY_H

#include <cmath>
#include <cassert>

template<typename T>
class Point2;

template<typename T>
class Point3;

template<typename T>
class Vector2;

template<typename T>
class Vector3;

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
    friend std::ostream &operator<<(std::ostream &os, const Point3<T> &v) {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
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
class Point3 {
public:
    /* Constructors */
    Point3() { x = y = z = 0; }

    Point3(T x, T y, T z) : x(x), y(y), z(z) {}

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

    Point3<T> operator-() const { return Point3<T>(-x, -y, -z); }

    T x, y, z;
};

template<typename T>
inline float Distance(const Point3<T> &p1, const Point3<T> &p2) {
    return (p1 - p2).Length();
}

template<typename T>
inline float Distance(const Point2<T> &p1, const Point2<T> &p2) {
    return (p1 - p2).Length();
}

template<typename T>
class Vector2 {
public:
    /* Constructors */
    Vector2() { x = y = z = 0; }

    Vector2(T x, T y, T z) : x(x), y(y), z(z) {}

    T operator[](int i) const {
        assert(i >= 0 && i < 2);
        if (i == 0) return x;
        if (i == 1) return y;
        return z;
    }

    T &operator[](int i) {
        assert(i >= 0 && i < 2);
        if (i == 0) return x;
        if (i == 1) return y;
        return z;
    }

    /* Debug */
    friend std::ostream &operator<<(std::ostream &os, const Vector3<T> &v) {
        os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
        return os;
    }

    bool IsNotNull() const { return !(std::isnan(x) || std::isnan(y)); }

    /* Operators */
    Vector2<T> &operator=(const Vector2<T> &v) {
        assert(v.IsNotNull());
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }

    Vector2<T> operator+(const Vector2<T> &v) const {
        assert(v.IsNotNull());
        return Vector2<T>(x + v.x, y + v.y, z + v.z);
    }

    Vector2<T> &operator+=(const Vector2<T> &v) {
        assert(v.IsNotNull());
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vector2<T> operator-(const Vector2<T> &v) const {
        assert(v.IsNotNull());
        return Vector2<T>(x - v.x, y - v.y, z - v.z);
    }

    Vector2<T> &operator-=(const Vector2<T> &v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    Vector2<T> operator*(T s) const {
        return Vector3<T>(x * s, y * s, z * s);
    }

    Vector2<T> &operator*=(T s) {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    Vector2<T> operator/(T s) const {
        return Vector2<T>(x / s, y / s, z / s);
    }

    Vector2<T> &operator/=(T s) {
        x /= s;
        y /= s;
        z /= s;
        return *this;
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

    Vector3<T> operator*(T s) const {
        return Vector3<T>(x * s, y * s, z * s);
    }

    Vector3<T> &operator*=(T s) {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    Vector3<T> operator/(T s) const {
        return Vector3<T>(x / s, y / s, z / s);
    }

    Vector3<T> &operator/=(T s) {
        x /= s;
        y /= s;
        z /= s;
        return *this;
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
inline Vector2<T> Normalize(const Vector2<T> &v) {
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

template<typename T>
inline Vector2<T> CrossProduct(const Vector2<T> &v1, const Vector2<T> &v2) {
    T v1x = v1.x, v1y = v1.y, v1z = 0;
    T v2x = v2.x, v2y = v2.y, v2z = 0;

    return Vector2<T>((v1y * v2z) - (v1z * v2y),
                      (v1z * v2x) - (v1x * v2z));
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

#endif //RENDERENGINE_GEOMETRY_H
