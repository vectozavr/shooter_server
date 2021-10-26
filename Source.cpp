//
// Created by Иван Ильин on 22.09.2021.
//

#include <fstream>
#include <utility>
#include <iostream>
#include "Server.h"
#include "engine/utils/Time.h"
#include "engine/utils/Log.h"
#include "engine/Consts.h"

using namespace std;

void InitServer(Server& server)
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

    server.start(serverPort);
    if(server.isWorking())
        server.generateBonuses();
}

int main() {
    Time::init();
    Server server{};

    Log::log("Initializing the server...");
    InitServer(server);

    double lastTryReconnecting = 0;

    while (true) {
        if(!server.isWorking() && (Time::time() - lastTryReconnecting > Consts::NETWORK_TIMEOUT)) {
            lastTryReconnecting = Time::time();
            server.stop();
            Log::log("Restarting the server...");
            InitServer(server);
        }
        Time::update();
        server.update();
    }

    return 0;
}
