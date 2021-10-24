//
// Created by Иван Ильин on 14.03.2021.
//

#include "Player.h"
#include "engine/utils/Log.h"

Player::Player() {
}

void Player::setFullHealth() {
    _health = ShooterConsts::HEALTH_MAX;
}

void Player::setFullAbility() {
    _ability = ShooterConsts::ABILITY_MAX;
}
