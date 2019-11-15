#ifndef RENDERENGINE_SPHERE_H
#define RENDERENGINE_SPHERE_H

#include <cmath>

#include "shape.h"

class Sphere : public Shape {
public:

    Sphere() {
        radius = 0;
        center = 0;
        material = nullptr;
    }

    Sphere(const Vector3f &center, float radius, Material *material) : center(center), radius(radius),
                                                                       material(material) {
        assert(!std::isnan(radius) && center.IsNotNull() && material);
    }

    bool intersect(const Ray &ray, const double &t_min, const double &t_max,
                   ShapeIntersectionBundle &bundle) const override {

        Vector3f oc = ray.origin - center;

        float a = DotProduct(ray.direction, ray.direction);
        float b = DotProduct(oc, ray.direction);
        float c = DotProduct(oc, oc) - radius * radius;
        float discriminant = b * b - a * c;

        if (discriminant > 0) {
            auto t = float((-b - std::sqrt(discriminant)) / a);
            if (t < t_max && t > t_min) {
                bundle.time = t;
                bundle.point = ray.pointOnRayAtTime(t);
                bundle.normal = (bundle.point - center) / radius;
                bundle.material = material;
                return true;
            }
            t = float((-b + std::sqrt(discriminant)) / a);
            if (t < t_max && t > t_min) {
                bundle.time = t;
                bundle.point = ray.pointOnRayAtTime(t);
                bundle.normal = (bundle.point - center) / radius;
                bundle.material = material;
                return true;
            }
        }
        return false;
    }

    float radius;
    Vector3f center;
    Material *material;
};

#endif //RENDERENGINE_SPHERE_H
