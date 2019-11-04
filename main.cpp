#include <fmt/format.h>

// This import is needed to allow for overrided ostream operators
// (according to {fmt}), but it does not directly do anything.
#include <fmt/ostream.h>

#include "geometry/2d/vector2.h"
#include "geometry/3d/point3.h"
#include "geometry/3d/vector3.h"
#include "geometry/arithmetic.h"

int main() {
    Vector3<float> v1 = Vector3<float>(5, 7, 9);
    Vector3<float> v2 = Vector3<float>(6, 10, 4);
    Vector3<float> v3 = v1;

    Vector2<float> _v1 = Vector2<float>(1, 2);
    Vector2<float> _v2 = Vector2<float>(3, 5);
    Vector2<float> _v3 = _v1;

    fmt::print("v1 {} == v3 {} : {}\n", v1, v3, v1 == v3);
    fmt::print("v1 X v3 : {}\n", CrossProduct(v1, v2));
}