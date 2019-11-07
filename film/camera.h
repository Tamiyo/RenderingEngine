#ifndef RENDERENGINE_CAMERA_H
#define RENDERENGINE_CAMERA_H

#include "../primitives/geometry.h"

class Camera {
public:
    Camera(const Vector3f &origin, const int &screen_width, const int &screen_height) {
        this->origin = origin;
        horizontal = Vector3f(screen_width / 50.0, 0, 0);
        vertical = Vector3f(0, screen_height / 50.0, 0);
        lower_left_corner = Vector3f(origin - horizontal / 2.0 - vertical / 2.0 - distance);
    }

    Ray GetRay(float u, float v) {
        return {origin, lower_left_corner + (horizontal * u) + (vertical * v)};
    }

    Vector3f origin, horizontal, vertical, lower_left_corner;
    Vector3f distance = Vector3f(0, 0, 1.0f);

};

#endif //RENDERENGINE_CAMERA_H
