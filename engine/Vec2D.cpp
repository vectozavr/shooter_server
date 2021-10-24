//
// Created by Иван Ильин on 10.10.2021.
//

#include <cmath>
#include "Vec2D.h"

Vec2D::Vec2D(const Vec2D &vec) {
    _arr_point[0] = vec.x();
    _arr_point[1] = vec.y();
}

Vec2D::Vec2D (double x, double y) {
    _arr_point[0] = x;
    _arr_point[1] = y;
}


Vec2D Vec2D::operator-() const {
    return Vec2D(-x(), -y());
}

Vec2D Vec2D::operator+(const Vec2D& vec) const {
    return Vec2D(x()+vec.x(), y()+vec.y());
}
Vec2D Vec2D::operator-(const Vec2D& vec) const {
    return Vec2D(*this) + -vec;
}

Vec2D Vec2D::operator*(double number) const {
    return Vec2D(x()*number, y()*number);
}

// Other useful methods
double Vec2D::sqrAbs() const {
    return x()*x() + y()*y();
}

double Vec2D::abs() const {
    return sqrt(sqrAbs());
}

double Vec2D::dot(const Vec2D& vec) const {
    return vec.x() * x() + vec.y() * y();
}
