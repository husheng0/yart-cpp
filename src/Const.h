#ifndef CONST_HEADER
#define CONST_HEADER

#include <cstdio>
#define DEBUG(...) printf(__VA_ARGS__)
//#define DEBUG(...)

#include <iostream>

#include <vector>
#include <memory>
using namespace std;

#include "glm\glm.hpp"
using namespace glm;

#define CONST_FAR 1000000.0f
#define CONST_NEAR 0.001f
#define CONST_EPSILON 0.000001f
#define PI 3.14159265f
#define INV_PI 0.318309f

inline vec3 applyMatrix(const mat4 &trans, const vec3 &v) {
    vec4 temp = vec4(v, 1.0f);
    temp = trans * temp;
    temp = temp / temp[3];
    return vec3(temp);
}

inline pair<vec3, vec3> buildLocalCoordinate(const vec3 &normal) {
    vec3 tangent = normalize(normal.x > 0.5f ? vec3(normal.y, -normal.x, 0.0f) : vec3(0.0f, -normal.z, normal.y));
    vec3 cotangent = cross(normal, tangent);
    return make_pair(tangent, cotangent);
}

#endif