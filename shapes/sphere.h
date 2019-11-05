#ifndef RENDERENGINE_SPHERE_H
#define RENDERENGINE_SPHERE_H

#include <cmath>

#include "shape.h"

class Sphere : public Shape {
public:

    Sphere() {
        radius = 0;
        center = 0;
    }

    Sphere(Vector3f center, float radius) : center(center), radius(radius) {
        assert(!std::isnan(radius) && center.IsNotNull());
    }

    bool intersect(const Ray &ray, double &t) const override {
        Vector3f ray_origin = ray.origin;
        Vector3f ray_direction = ray.direction;
        Vector3f oc = ray_origin - center;

        double b = 2 * DotProduct(oc, ray_direction);
        double c = DotProduct(oc, oc) - radius * radius;
        double disc = b * b - c * 4;

        if (disc < 0) return false;
        else {
            disc = sqrt(disc);
            double t0 = -b - disc;
            double t1 = -b + disc;

            t = (t0 < t1) ? t0 : t1;
            return true;
        }
    }

    Vector3f GetNormalVectorAtPoint(Vector3f pointOfIntersection) {
        return Vector3f((pointOfIntersection - center) / radius);
    }

    float radius;
    Vector3f center;
};

#endif //RENDERENGINE_SPHERE_H
