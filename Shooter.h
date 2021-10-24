//
// Created by Иван Ильин on 22.09.2021.
//

#ifndef SHOOTER_SHOOTER_H
#define SHOOTER_SHOOTER_H

#include "engine/Engine.h"
#include "Player.h"

#include "Server.h"

class Shooter final : public Engine {
private:
    std::shared_ptr<Server> server;

    void start() override;
    void update() override;

    void InitServer();

    double lastUpdateTime = -std::numeric_limits<double>::max();
public:
    Shooter() {};
};


#endif //SHOOTER_SHOOTER_H
