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
        char * matrix_values = root_node->first_node("library_visual_scenes")->first_node(
                "visual_scene")->first_node("node")->first_node("matrix")->value();

        std::istringstream issm(matrix_values);
        std::vector<std::string> matrix_str(std::istream_iterator<std::string>{issm},
                                             std::istream_iterator<std::string>());

        std::vector<float> m_results;
        for (const std::string &token : matrix_str) {
            m_results.push_back(stof(token));
        }

        Vector3f m_a(m_results[0], m_results[2], m_results[1]);
        Vector3f m_b(m_results[3], m_results[5], m_results[4]);
        Vector3f m_c(m_results[6], m_results[8], m_results[7]);
        Vector3f m_d(m_results[9], m_results[11], m_results[10]);

//        Matrix4f matrix4(m_a, m_b, m_c);


        // Create shape vectors
        char *float_array_str = root_node->first_node("library_geometries")->first_node(
                "geometry")->first_node("mesh")->first_node("source")->first_node(
                "float_array")->value();

        std::istringstream iss(float_array_str);
        std::vector<std::string> results_str(std::istream_iterator<std::string>{iss},
                                             std::istream_iterator<std::string>());

        std::vector<float> results;
        for (const std::string &token : results_str) {
            results.push_back(stof(token) * 0.2f);
        }

        fmt::print("Number of Imported Vertices: {}\n", results.size());

        std::vector<Shape *> shapes;
        for (int i = 0; i < results.size(); i += 9) {
            int iter = i;
            Vector3f a(results[i], results[i + 2], results[i + 1]);
            Vector3f b(results[i + 3], results[i + 5], results[i + 4]);
            Vector3f c(results[i + 6], results[i + 8], results[i + 7]);


//            Triangle *t = new Triangle(,
//                                       ,
//                                       ,
//                                       new Lambertian(Vector3f(0.8, 0.3, 0.3)));
//            shapes.push_back(t);
        }

        fmt::print("Finished Importing Document\n");
        return shapes;

    }

    rapidxml::xml_document<> doc;
};

#endif //RENDERENGINE_COLLADA_H
