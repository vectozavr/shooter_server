//
// Created by Иван Ильин on 22.09.2021.
//

#include "Shooter.h"
#include <fstream>
#include <utility>
#include "engine/utils/Time.h"
#include "ShooterConsts.h"

using namespace std;

void Shooter::InitServer()
{
    sf::Uint16 serverPort;
    std::ifstream connectFile("server.txt", std::ifstream::in);

    if (!connectFile.is_open() || !(connectFile >> serverPort))
    {
        connectFile.close();
        // Create file and write default settings
        serverPort = 54000;
        std::ofstream temp("server.txt", std::ofstream::out);
        temp << serverPort;
        temp.close();
    }
    connectFile.close();

    server->start(serverPort);
    if(server->isWorking())
        server->generateBonuses();
}

void Shooter::start() {
    server = std::make_shared<Server>();

    InitServer();
}

void Shooter::update() {
    // This code executed every time step:
    server->update();
}
