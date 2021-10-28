//
// Created by Иван Ильин on 13.01.2021.
//

#ifndef ENGINE_MESH_H
#define ENGINE_MESH_H

#include <utility>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Object.h"

class Mesh : public Object {
public:
    explicit Mesh(ObjectNameTag nameTag) : Object(std::move(nameTag)) {};
    ~Mesh() override = default;
};

#endif //INC_3DZAVR_MESH_H
