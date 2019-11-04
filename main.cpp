#include <fmt/format.h>
#include <fmt/ostream.h>

#include "geometry.h"

int main() {
    Point3<float> p1 = Point3<float>(0, 1, 2);
    Point3<float> p2 = Point3<float>(1, 3, 6);

    Vector3<float> v1 = Vector3<float>(5, 7, 9);
    Vector3<float> v2 = Vector3<float>(6, 10, 4);

    fmt::print("{}\n", Distance(p1, p2));
    fmt::print("{}\n", v1[0]);
    fmt::print("{}, {}, {}, {}", p1, p2, v1, v2);
}