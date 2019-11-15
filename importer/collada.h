#ifndef RENDERENGINE_COLLADA_H
#define RENDERENGINE_COLLADA_H

#include <fstream>
#include <cstring>
#include "../shapes/shape.h"
#include "../rapidxml/rapidxml.hpp"

#include <algorithm>
#include <iterator>
#include <sstream>

class ColladaImporter {
public:
    explicit ColladaImporter(const char *documentPath) {
        std::ifstream in(documentPath);

        if (!in) {
            fmt::print("Error Opening File: {}\n", documentPath);
            exit(1);
        }

        std::string contents((std::istreambuf_iterator<char>(in)),
                             std::istreambuf_iterator<char>());

        char *body = new char[contents.length() + 1];
        strcpy(body, contents.c_str());

        doc.parse<0>(body);
    }

    std::vector<Shape *> GetShapes() {
        fmt::print("Begun Importing Document\n");

        rapidxml::xml_node<> *root_node;
        root_node = doc.first_node("COLLADA");


        // Create transformation matrix
        char *matrix_values = root_node->first_node("library_visual_scenes")->first_node(
                "visual_scene")->first_node("node")->first_node("matrix")->value();

        std::istringstream issm(matrix_values);
        std::vector<std::string> matrix_str(std::istream_iterator<std::string>{issm},
                                            std::istream_iterator<std::string>());

        std::vector<float> m_results;
        for (const std::string &token : matrix_str) {
            m_results.push_back(stof(token));
        }

        Vector3f m_a(m_results[0], m_results[1], m_results[2], m_results[3]);
        Vector3f m_c(m_results[4], m_results[5], m_results[6], m_results[7]);
        Vector3f m_b(m_results[8], m_results[9], m_results[10], m_results[11]);
        Vector3f m_d(m_results[12], m_results[13], m_results[14], m_results[15]);

//        fmt::print("m1 {}\n", m_a);
//        fmt::print("m2 {}\n", m_b);
//        fmt::print("m3 {}\n", m_c);
//        fmt::print("m4 {}\n", m_d);

        Matrix4f translation_matrix(m_a, m_b, m_c, m_d);


        // Create vectors
        char *float_array_str = root_node->first_node("library_geometries")->first_node(
                "geometry")->first_node("mesh")->first_node("source")->first_node(
                "float_array")->value();

        std::istringstream iss(float_array_str);
        std::vector<std::string> vert_ss(std::istream_iterator<std::string>{iss},
                                         std::istream_iterator<std::string>());

        std::vector<float> results;
        for (const std::string &token : vert_ss) {
            results.push_back(stof(token));
        }

//        fmt::print("Number of Imported Vertices: {}\n", results.size());

        std::vector<Vector3f> vert;
        for (int i = 0; i < results.size(); i += 3) {
            Vector3f a(results[i], results[i + 2], results[i + 1]);
            a = translation_matrix * a;
            vert.push_back(a);
        }


        // Create Shapes
        char *vert_shape_array = root_node->first_node("library_geometries")->first_node(
                "geometry")->first_node("mesh")->first_node("triangles")->first_node(
                "p")->value();

//        fmt::print("Shape Array: {}\n", vert_shape_array);

        std::istringstream iss_sh(vert_shape_array);
        std::vector<std::string> sh_ss(std::istream_iterator<std::string>{iss_sh},
                                       std::istream_iterator<std::string>());

        std::vector<int> results_sh;
        for (const std::string &token : sh_ss) {
            results_sh.push_back(stoi(token));
        }

        std::vector<Shape *> shapes;
//        fmt::print("Shape Size {}\n", results_sh.size());
        for (int i = 0; i < results_sh.size(); i += 9) {
            auto a = vert[results_sh[i]];
            auto b = vert[results_sh[i + 3]];
            auto c = vert[results_sh[i + 6]];
            auto *t = new Triangle(a, b, c, new Lambertian(Vector3f(0.8, 0.3, 0.3)));
            shapes.push_back(t);
        }

        fmt::print("Finished Importing Document : Imported {} Shapes\n", shapes.size());
        return shapes;

    }

    rapidxml::xml_document<> doc;
};

#endif //RENDERENGINE_COLLADA_H
