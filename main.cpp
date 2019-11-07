#include <fmt/format.h>
// This import is needed to allow for overrided ostream operators
// (according to {fmt}), but it does not directly do anything.
#include <fmt/ostream.h>

#include <cmath>
#include <vector>
#include <random>

#include <fstream>

#include "primitives/geometry.h"
#include "film/camera.h"
#include "film/color.h"
#include "shapes/sphere.h"
#include "algorithm/raytracing.h"
#include "materials/material.h"


int screenWidth = 200;
int screenHeight = 100;
float aspectRatio = (float) screenWidth / (float) screenHeight;
float fov = 90;

int samples = 100;

int main() {
    /*-------------*/
    /* Frame Setup */
    /*-------------*/

    fmt::print("Rendering a {}x{} image...\n", screenWidth, screenHeight);

    // File that we write our image out to
    std::ofstream out(R"(D:\Documents\RenderEngine\images\out.ppm)");
    out << "P3\n" << screenWidth << " " << screenHeight << "\n255\n";

    /*--------------*/
    /* Camera Setup */
    /*--------------*/
    // Camera position at coordinate (0, 0, 0)
    Camera camera(Vector3f(0, 0, 0), screenWidth, screenHeight);

    /*-------------*/
    /* Shape Setup */
    /*-------------*/
    std::vector<Shape *> shapes;
    shapes.push_back(new Sphere(Vector3f(0, 0, -1), 0.5, new Lambertian(Vector3f(0.8, 0.3, 0.3))));
    shapes.push_back(new Sphere(Vector3f(0, -100.5, -1), 100, new Lambertian(Vector3f(0.8, 0.8, 0.0))));
    shapes.push_back(new Sphere(Vector3f(1, 0, -1), 0.5, new Metal(Vector3f(0.8, 0.6, 0.2))));
    shapes.push_back(new Sphere(Vector3f(-1, 0, -1), 0.5, new Metal(Vector3f(0.8, 0.8, 0.8))));


    /*-----------*/
    /* Rendering */
    /*-----------*/
    // For each pixel
    int previous = -1;
    for (int y = screenHeight - 1; y >= 0; y--) {

        /* DEBUG */
        int percent = (int) std::round(((float) (screenHeight - y) / (float) screenHeight) * 100);
        if (percent % 10 == 0 && percent > previous) {
            fmt::print("Rendering {}% Complete\n", percent);
            previous = percent;
        }

        for (int x = 0; x < screenWidth; x++) {

            // Creating the background color
            Vector3f color(0, 0, 0);

            // For each sample, get a better pixel value by averaging the average color values instead of
            // performing only a single iteration.
            for (int i = 0; i < samples; i++) {
                // Cast a ray from the camera "eye" origin through each pixel
                float u = (float(x) + GenerateRandomNumber()) / float(screenWidth);
                float v = (float(y) + GenerateRandomNumber()) / float(screenHeight);

                Ray ray = camera.GetRay(u, v);
                color += TraceRay(ray, shapes, 0);
            }

            color = (color / float(samples));
            color = Vector3f(std::sqrt(color.x), std::sqrt(color.y), std::sqrt(color.z));
            color = Vector3f(color.x * 255.99, color.y * 255.99, color.z * 255.99);
            out << (int) color.x << " " << (int) color.y << " " << (int) color.z << "\n";

            // distanceMin = infinity
            // For every object in the scene
            //      If distance = intersect(ray, object)
            //          if distance < distanceMin
            //              closestObject = object
            //              distanceMin = distance

            // If distanceMin > infinityThreshold
            //      pixelColor = background color
            // Else
            //      pixelColor = color of object at distanceMin along ray

        }
        // Compute color at the intersection point
    }
    out.close();
    return 0;
}






