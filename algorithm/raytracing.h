#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc32-c"
#ifndef RENDERENGINE_RAYTRACING_H
#define RENDERENGINE_RAYTRACING_H

#include <vector>
#include <random>

#include <cfloat>

#include "../primitives/geometry.h"
#include "../shapes/shape.h"
#include "../materials/material.h"
#include "bundle.h"
#include "random.h"

bool ShapeIntersectsWithRay(const Ray &ray, float t_min, float t_max, const std::vector<Shape *> &shapes,
                            ShapeIntersectionBundle &bundle) {
    ShapeIntersectionBundle tempBundle;
    bool intersected = false;
    float closest = t_max;

    for (auto shape : shapes) {
        if (shape->intersect(ray, t_min, closest, tempBundle)) {
            intersected = true;
            closest = tempBundle.time;
            bundle = tempBundle;
        }
    }
    return intersected;
}

Vector3f TraceRay(const Ray &ray, const std::vector<Shape *> &shapes, const int depth) {
    ShapeIntersectionBundle bundle;

    if (ShapeIntersectsWithRay(ray, 0.001f, FLT_MAX, shapes, bundle)) {
        Ray scattered;
        Vector3f attenuation;

        if (depth < 50 && bundle.material->Scatter(ray, bundle, attenuation, scattered)) {
            return attenuation * TraceRay(scattered, shapes, depth + 1);
        } else {
            return Vector3f(0);
        }

        Vector3f unitSphereVector = GenerateRandomVectorOnUnitSphere();
        Vector3f target(bundle.point + bundle.normal + unitSphereVector);
        return TraceRay(Ray(bundle.point, target - bundle.point), shapes, depth + 1) * 0.5;
    } else {
        // TODO [Placeholder] - Remove this when actual background colors get added
        Vector3f unitDirection = Normalize(ray.direction);
        double t = 0.5 * (unitDirection.y + 1.0);
        return (Vector3f(1.0) * (1.0 - t) + Vector3f(0.5, 0.7, 1.0) * (t));
    }
}


#endif //RENDERENGINE_RAYTRACING_H