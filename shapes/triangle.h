#ifndef RENDERENGINE_TRIANGLE_H
#define RENDERENGINE_TRIANGLE_H

#include "shape.h"

class Triangle : public Shape {
public:
    Triangle() {
        p1 = p2 = p3 = 0;
        material = nullptr;
    }

    Triangle(const Vector3f &p1, const Vector3f &p2, const Vector3f &p3, Material *material) : p1(p1), p2(p2), p3(p3),
                                                                                               material(material) {
        assert(p1.IsNotNull() && p2.IsNotNull() && p3.IsNotNull());
    }

    bool intersect(const Ray &ray, const double &t_min, const double &t_max,
                   ShapeIntersectionBundle &bundle) const override {
        Vector3f edge1 = (p2 - p1);
        Vector3f edge2 = (p3 - p1);
        Vector3f h = CrossProduct(ray.direction, edge2);
        float a = DotProduct(edge1, h);

        // Check the the ray is parallel to the triangle
        if (a > -EPSILON && a < EPSILON) return false;

        float f = 1.0f / a;
        Vector3f s = ray.origin - p1;
        float u = f * DotProduct(s, h);
        if (u < 0.0f || u > 1.0) return false;

        Vector3f q = CrossProduct(s, edge1);
        float v = f * DotProduct(ray.direction, q);
        if (v < 0.0 || u + v > 1.0) return false;

        float t = f * DotProduct(edge2, q);
        if (t > EPSILON && t < 1 / EPSILON && t < t_max && t > t_min) {
            bundle.time = t;
            bundle.point = ray.pointOnRayAtTime(t);
            bundle.normal = CrossProduct(edge1, edge2);
            bundle.material = material;
            return true;
        } else {
            return false;
        }

    }

    Vector3f p1, p2, p3;
    Material *material;

    // For Moller-Trumbore Intersection
    const float EPSILON = 0.0000001;
};

#endif //RENDERENGINE_TRIANGLE_H
