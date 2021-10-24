//
// Created by Иван Ильин on 09.10.2021.
//

#include "Vec3D.h"
#include <cmath>
#include <stdexcept>

Vec3D::Vec3D(const Vec3D &vec) {
    _arr_point[0] = vec.x();
    _arr_point[1] = vec.y();
    _arr_point[2] = vec.z();
}

Vec3D::Vec3D (double x, double y, double z) {
    _arr_point[0] = x;
    _arr_point[1] = y;
    _arr_point[2] = z;
}

Vec3D Vec3D::operator-() const {
    return Vec3D(-x(), -y(), -z());
}

// Operations with Vec3D
Vec3D Vec3D::operator+(const Vec3D& vec) const {
    return Vec3D(x()+vec.x(), y()+vec.y(), z()+vec.z());
}
Vec3D Vec3D::operator-(const Vec3D& vec) const {
    return Vec3D(*this) + -vec;
}

// Other useful methods
double Vec3D::sqrAbs() const {
    return x()*x() + y()*y() + z()*z();
}

double Vec3D::abs() const {
    return sqrt(sqrAbs());
}

double Vec3D::dot(const Vec3D& vec) const {
    return vec.x() * x() + vec.y() * y() + vec.z() * z();
}

Vec3D Vec3D::cross(const Vec3D& vec) const {
    return Vec3D{y() * vec.z() - vec.y() * z(),
                 z() * vec.x() - vec.z() * x(),
                 x() * vec.y() - vec.x() * y()};
}
