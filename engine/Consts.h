//
// Created by Иван Ильин on 07.10.2021.
//

#ifndef SHOOTER_CONSTS_H
#define SHOOTER_CONSTS_H
#include <SFML/Graphics.hpp>


namespace Consts {
    const bool USE_LOG_FILE = false;

    const double TAP_DELAY = 0.2;
    const double LARGEST_TIME_STEP = 1.0/15.0;

    const unsigned NETWORK_VERSION = 3U;
    const int NETWORK_TIMEOUT = 5U;
    const int NETWORK_WORLD_UPDATE_RATE = 30;
    const double NETWORK_RELIABLE_RETRY_TIME = 1.0/20;
    const uint16_t NETWORK_MAX_CLIENTS = 64;
}

#endif //SHOOTER_CONSTS_H
