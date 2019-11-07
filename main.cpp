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
    shapes.push_back(new Sphere(Vector3f(0, 0, -1), 0.5));
    shapes.push_back(new Sphere(Vector3f(0, -100.5, -1), 100));



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
            Color color(0, 0, 0);

            // For each sample, get a better pixel value. Note this will be replaced on a per-object basis
            for (int i = 0; i < samples; i++) {
                // Cast a ray from the camera "eye" origin through each pixel
                float u = (float(x) + GenerateRandomNumber()) / float(screenWidth);
                float v = (float(y) + GenerateRandomNumber()) / float(screenHeight);

                Ray ray = camera.GetRay(u, v);
                color = color + TraceRay(camera, ray, shapes);
            }

            color = (color / samples);
            color = Color(std::sqrt(color.r), std::sqrt(color.g), std::sqrt(color.b));
            color = Color(int(color.r * 255.99), int(color.g * 255.99), int(color.b * 255.99));
            out << (int) color.r << " " << (int) color.g << " " << (int) color.b << "\n";

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






