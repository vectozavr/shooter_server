//
// Created by Иван Ильин on 22.09.2021.
//

#include <fstream>
#include <utility>
#include <iostream>
#include "Server.h"
#include "engine/utils/Time.h"
#include "engine/utils/Log.h"
#include "engine/Keyboard.h"

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
    Keyboard keyboard;
    Server server{};

    Log::log("Initializing the server...");
    InitServer(server);

    if(server.isWorking())
        std::cout << "Type 'q' to exit the server" << std::endl;
    std::cout << "Type 'r' to restart the server" << std::endl;

    while (true) {
        if(keyboard.isKeyTapped(sf::Keyboard::Key::Q)) {
            Time::free();
            break;
        }
        if(keyboard.isKeyTapped(sf::Keyboard::Key::R)) {
            server.stop();
            Log::log("Restarting the server...");
            InitServer(server);
        }

        Time::update();
        server.update();
    }

    return 0;
}
