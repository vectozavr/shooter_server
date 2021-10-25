//
// Created by Иван Ильин on 15.03.2021.
//

#ifndef ENGINE_OBJECT_H
#define ENGINE_OBJECT_H

#include <map>
#include "Vec3D.h"
#include <string>
#include <utility>
#include <memory>

class Object {
protected:
    std::unique_ptr<Vec3D> _position = std::make_unique<Vec3D>(Vec3D{0, 0, 0});
    std::unique_ptr<Vec3D> _angle = std::make_unique<Vec3D>(Vec3D{0, 0, 0});
public:
    Object() = default;

    virtual void translate(const Vec3D& dv);
    virtual void translateToPoint(const Vec3D& point);
    virtual void rotate(const Vec3D& r);
    virtual void rotateToAngle(const Vec3D& v);

    [[nodiscard]] Vec3D position() const { return *_position; }
    [[nodiscard]] Vec3D angle() const { return *_angle; }

    virtual ~Object() = default;
};

#endif //MINECRAFT_3DZAVR_OBJECT_H
