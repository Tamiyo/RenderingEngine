//#include <fmt/format.h>
//
//#include <cmath>
//#include <vector>
//
//// This import is needed to allow for overrided ostream operators
//// (according to {fmt}), but it does not directly do anything.
//#include <fmt/ostream.h>
//#include <fstream>
//
//#include "primitives/geometry.h"
//#include "shapes/sphere.h"
//#include "film/color.h"
//
//
//int SCREEN_WIDTH = 500;
//int SCREEN_HEIGHT = 500;
//double ASPECT_RATIO = (double) SCREEN_WIDTH / (double) SCREEN_HEIGHT;
//
//int main2() {
//    // Frame Setup
//    fmt::print("Rendering a {}x{} image...", SCREEN_WIDTH, SCREEN_HEIGHT);
//
//    // File that we write our image out to
//    std::ofstream out(R"(D:\Documents\RenderEngine\images\out.ppm)");
//    out << "P3\n" << SCREEN_WIDTH << "\n" << SCREEN_HEIGHT << "\n" << "255\n";
//
//    // Matrix of pixels to display
//    std::vector<std::vector<Color> > pixel_collection(SCREEN_HEIGHT, std::vector<Color>(SCREEN_WIDTH));
//
//    // Default objects to use in our scene
//    Color white(255, 255, 255);
//    Color black(0, 0, 0);
//    Color red(255, 0, 0);
//    Sphere sphere(Vector3f(SCREEN_WIDTH / 2.0, SCREEN_HEIGHT / 2.0, 50), 50.0);
//
//    // Using a sphere as a light source bc we are lazy rn
//    Sphere light(Vector3f(0, 0, 50), 1);
//
//
//    // For each pixel
//    for (int y = 0; y < SCREEN_HEIGHT;
//         y++) {
//        for (int x = 0; x < SCREEN_WIDTH;
//             x++) {
//            pixel_collection[y][x] = black;
//
//            // Send a ray through each pixel
//            Ray ray(Vector3f(x, y, 0), Vector3f(0, 0, 1));
//
//            // Time T on the Ray (More on this later)
//            double t = 20000;
//
//            // Check for intersections with shapes
//            if (sphere.intersect(ray, t)) {
//
//                // Point of intersection
//                Vector3f pointOfIntersection = ray.origin + ray.direction * t;
//
//                // Color the pixel based on the light and normal vectors of an object
//                Vector3f L = light.center - pointOfIntersection;
//                Vector3f N = sphere.GetNormalVectorAtPoint(pointOfIntersection);
//                double dt = DotProduct(Normalize(L), Normalize(N));
//
//                // Assign the new color value based no the light reflection
//                Color tmp = (red + white * dt) * 0.5;
//                pixel_collection[y][x] = tmp.clamp255();
//            }
//
//            // Write the pixel data out to the file
//            out << (int) pixel_collection[y][x].r << std::endl;
//            out << (int) pixel_collection[y][x].g << std::endl;
//            out << (int) pixel_collection[y][x].b << std::endl;
//        }
//    }
//
//    out.close();
//    return 0;
//}
