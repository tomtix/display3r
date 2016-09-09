#ifndef DISPLAY3R_OBJ_3D_H
#define DISPLAY3R_OBJ_3D_H

#include <glm/glm.hpp>

namespace display3r {

using namespace glm;

struct Vertex {
    vec3 position;
    vec3 normal;
    vec2 texcoord;
    Vertex() {}
    Vertex(vec3 const &p, vec3 const &n, vec2 const &t):
        position(p), normal(n), texcoord(t) {}
};

struct Segment {
    vec3 A;
    vec3 B;
    Segment(vec3 const& a, vec3 const& b): A(a), B(b) {}
};

struct Face {
    Vertex A;
    Vertex B;
    Vertex C;
    Face(Vertex const& a, Vertex const& b, Vertex const& c): A(a),B(b),C(c) {}
};

};

#endif // DISPLAY3R_OBJ_3D_H