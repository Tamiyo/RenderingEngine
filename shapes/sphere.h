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

    Sphere(const Vector3f &center, float radius) : center(center), radius(radius) {
        assert(!std::isnan(radius) && center.IsNotNull());
    }

    ShapeIntersectionBundle *intersect(const Ray &ray, const double &t_min, const double &t_max) const override {

        Vector3f oc = ray.origin - center;

        float a = DotProduct(ray.direction, ray.direction);
        float b = DotProduct(oc, ray.direction);
        float c = DotProduct(oc, oc) - radius * radius;
        float discriminant = b * b - a * c;

        if (discriminant > 0) {
            auto temp = float(-b - std::sqrt(b * b - a * c) / a);
            if (temp < t_max && temp > t_min) {
                float time = temp;
                Vector3f point = ray.pointOnRayAtTime(time);
                Vector3f normal = (point - center) / radius;
                return new ShapeIntersectionBundle(time, point, normal);
            }
            temp = float(-b + std::sqrt(b * b - a * c) / a);
            if (temp < t_max && temp > t_min) {
                float time = temp;
                Vector3f point = ray.pointOnRayAtTime(time);
                Vector3f normal = (point - center) / radius;
                return new ShapeIntersectionBundle(time, point, normal);
            }
        }
        return nullptr;
    }

    float radius;
    Vector3f center;
};

#endif //RENDERENGINE_SPHERE_H
