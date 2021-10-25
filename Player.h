//
// Created by Иван Ильин on 14.03.2021.
//

#ifndef SHOOTER_PLAYER_H
#define SHOOTER_PLAYER_H

#include <SFML/Audio/Sound.hpp>
#include <utility>
#include "ShooterConsts.h"
#include "engine/physics/RigidBody.h"
#include "ShooterConsts.h"

class Player final : public RigidBody{
private:
    double _health = ShooterConsts::HEALTH_MAX;
    double _ability = ShooterConsts::ABILITY_MAX;

    double _headAngle = 0;

    int _kills = 0;
    int _deaths = 0;
public:
    Player() = default;

    void setHealth(double h) { _health = h; }
    void setAbility(double a) { _ability = a; }

    [[nodiscard]] double health() const { return _health; }
    [[nodiscard]] double ability() const { return _ability; }


    void setFullHealth() { _health = ShooterConsts::HEALTH_MAX; }
    void setFullAbility() { _ability = ShooterConsts::ABILITY_MAX; }

    [[nodiscard]] int kills() const { return _kills; }
    [[nodiscard]] int deaths() const { return _deaths; }

    void addKill() { _kills++; }
    void addDeath() { _deaths++; }

    // This is for situation when you want to store the position of the head but you dont have attached camera
    void setHeadAngle(double a) { _headAngle = a; }
    [[nodiscard]] double headAngle() const { return _headAngle; };
};


#endif //MINECRAFT_3DZAVR_PLAYER_H
