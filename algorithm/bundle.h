#ifndef RENDERENGINE_BUNDLE_H
#define RENDERENGINE_BUNDLE_H

#include "../primitives/geometry.h"

class Material;

class ShapeIntersectionBundle {
public:
    ShapeIntersectionBundle() {
        time = 0;
        point = normal = 0;
        material = nullptr;
    }

    ShapeIntersectionBundle(float time, const Vector3f &point, const Vector3f &normal, Material *material) :
            time(time), point(point), normal(normal), material(material) {
        assert(!std::isnan(time) && point.IsNotNull() && normal.IsNotNull());
    }

    float time;
    Vector3f point, normal;
    Material *material;
};

#endif //RENDERENGINE_BUNDLE_H
