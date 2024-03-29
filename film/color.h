#ifndef RENDERENGINE_COLOR_H
#define RENDERENGINE_COLOR_H

#include <cmath>
#include <cassert>

class Color {
public:
    Color() { r = g = b = 0.0; }

    Color(double r, double g, double b) : r(r), g(g), b(b) {
        assert(!std::isnan(r) && !std::isnan(g) && !std::isnan(b));
    }

    explicit Color(const Vector3f &v) : r(v[0]), g(v[1]), b(v[2]) {
        assert(v.IsNotNull());
    }

    Color operator+(const Color &c) {
        return {r + c.r, g + c.g, b + c.b};
    }

    Color operator*(const double &d) {
        return {r * d, g * d, b * d};
    }

    Color operator/(const double &d) {
        assert (d != 0);
        return {r / d, g / d, b / d};
    }

    Color clamp255() {
        return {(r > 255) ? 255 : (r < 0) ? 0 : r,
                (g > 255) ? 255 : (g < 0) ? 0 : g,
                (b > 255) ? 255 : (b < 0) ? 0 : b};
    }

    double r, g, b;

};

#endif //RENDERENGINE_COLOR_H
