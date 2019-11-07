#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc32-c"
#ifndef RENDERENGINE_RAYTRACING_H
#define RENDERENGINE_RAYTRACING_H

#include <vector>
#include <random>

#include <cfloat>

#include "../primitives/geometry.h"
#include "../shapes/shape.h"


float GenerateRandomNumber() {
//    std::mt19937 randomNumberGenerator;
//    randomNumberGenerator.seed(3);
//
//    std::uniform_real_distribution<float> uniformRealDistribution(0, 1);
//    return uniformRealDistribution(randomNumberGenerator);
     return rand() / (RAND_MAX + 1.0);
}


Vector3f GenerateRandomVectorOnUnitSphere() {
    Vector3f p;
    do {
        p = (Vector3f(GenerateRandomNumber(), GenerateRandomNumber(), GenerateRandomNumber()) * 2.0) - Vector3f(1.0);
    } while (p.LengthSquared() >= 1.0);
    return p;
}

ShapeIntersectionBundle *
ShapeIntersectsWithRay(const Ray &ray, float t_min, float t_max, const std::vector<Shape *> &shapes) {
    float closest = t_max;

    ShapeIntersectionBundle *intersectionBundle = nullptr;

    for (auto shape : shapes) {
        ShapeIntersectionBundle *tempBundle = shape->intersect(ray, t_min, closest);
        if (tempBundle && tempBundle->time > 0.0) {
            if (tempBundle->time < closest) {
                closest = tempBundle->time;
                intersectionBundle = tempBundle;
            }
        }
    }
    return intersectionBundle;
}

Color TraceRay(const Camera &camera, const Ray &ray, const std::vector<Shape *> &shapes) {
    ShapeIntersectionBundle *intersectionBundle = ShapeIntersectsWithRay(ray, 0.001f, FLT_MAX, shapes);

    if (intersectionBundle != nullptr) {
        Vector3f unitSphereVector = GenerateRandomVectorOnUnitSphere();
        Vector3f target(intersectionBundle->point + intersectionBundle->normal + unitSphereVector);
        return (TraceRay(camera, Ray(intersectionBundle->point, target - intersectionBundle->point), shapes) * 0.5);
    } else {
        // TODO [Placeholder] - Remove this when actual background colors get added
        Vector3f unit_direction = Normalize(ray.direction);
        double t = 0.5 * (unit_direction.y + 1.0);
        return Color((Vector3f(1.0) * (1.0 - t) + Vector3f(0.5, 0.7, 1.0) * (t)));
    }
}


#endif //RENDERENGINE_RAYTRACING_H