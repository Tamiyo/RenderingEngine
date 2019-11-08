
#ifndef RENDERENGINE_MATERIAL_H
#define RENDERENGINE_MATERIAL_H

#include "../primitives/geometry.h"
#include "../algorithm/random.h"
#include "../algorithm/bundle.h"

class Material {
public:
    virtual bool Scatter(const Ray &ray, const ShapeIntersectionBundle &bundle, Vector3f &attenuation,
                         Ray &scattered) const = 0;
};

class Lambertian : public Material {
public:
    explicit Lambertian(const Vector3f &albedo) : albedo(albedo) { assert(albedo.IsNotNull()); }

    bool Scatter(const Ray &ray, const ShapeIntersectionBundle &bundle, Vector3f &attenuation,
                 Ray &scattered) const override {
        Vector3f target(bundle.point + bundle.normal + GenerateRandomVectorOnUnitSphere());
        scattered = Ray(bundle.point, target - bundle.point);
        attenuation = albedo;
        return true;
    }

    Vector3f albedo;
};

class Metal : public Material {
public:
    explicit Metal(const Vector3f &albedo) : albedo(albedo) { assert(albedo.IsNotNull()); };

    bool Scatter(const Ray &ray, const ShapeIntersectionBundle &bundle, Vector3f &attenuation,
                 Ray &scattered) const override {
        Vector3f reflected = Reflection(Normalize(ray.direction), bundle.normal);
        scattered = Ray(bundle.point, reflected);
        attenuation = albedo;
        return (DotProduct(scattered.direction, bundle.normal) > 0);
    }

private:
    Vector3f Reflection(const Vector3f &v, const Vector3f &n) const {
        return v - (n * (2.0 * DotProduct(v, n)));
    }

    Vector3f albedo;
};


#endif //RENDERENGINE_MATERIAL_H
