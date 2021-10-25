//
// Created by Иван Ильин on 15.03.2021.
//

#include "Object.h"
#include "utils/Log.h"

void Object::translate(const Vec3D &dv) {
    _position = std::make_unique<Vec3D>(*_position + dv);
}

void Object::rotate(const Vec3D &r) {
    _angle = std::make_unique<Vec3D>(*_angle + r);
}

void Object::translateToPoint(const Vec3D &point) {
    translate(point - *_position);
}

void Object::rotateToAngle(const Vec3D &v) {
    rotate(v - *_angle);
}
