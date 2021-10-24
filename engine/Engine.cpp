//
// Created by Иван Ильин on 14.01.2021.
//

#include "Engine.h"
#include "utils/Time.h"
#include <iostream>

Engine::Engine() {
    Time::init();
}

void Engine::create() {

    Log::log("Engine::create(): started server.");
    Time::update();

    start();

    while (true) {
        Time::update();
        update();
    }
}

void Engine::exit() {
    Time::free();
    Log::log("Engine::exit(): exit server.");
}
