#ifndef DISPLAY3R_UTIL_H
#define DISPLAY3R_UTIL_H

#define _USE_MATH_DEFINES
#include <cmath>

#include <glm/glm.hpp>
#include <iostream>

#define SQUARE(x) ((x)*(x))

#ifdef MAX
#undef MAX
#endif
#define MAX(x,y) ((x) < (y) ? (y) : (x))

#ifdef MIN
#undef MIN
#endif
#define MIN(x,y) ((x) < (y) ? (x) : (y))

#define DEGREE_TO_RADIAN(x) (((float)(x)) * M_PI / 180.)

namespace display3r {

glm::vec3 ParseVec3(std::string const &);

};

namespace std {

static inline ostream &operator<<(ostream &s, glm::vec3 const &v)
{
    s << v.x << " " << v.y << " " << v.z;
    return s;
}

static inline ostream &operator<<(ostream &s, glm::vec2 const &v)
{
    s << v.x << " " << v.y;
    return s;
}

};


#endif //DISPLAY3R_UTIL_H
