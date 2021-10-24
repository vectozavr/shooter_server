//
// Created by Иван Ильин on 14.01.2021.
//

#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include "utils/Log.h"
#include "Consts.h"

class Engine {
private:
    std::string _name;

    double _triPerSec = 0;
    bool _updateWorld = true;
    bool _debugText = Consts::SHOW_COORDINATES;
    bool _useOpenGL = Consts::USE_OPEN_GL;

    void printDebugText() const;
protected:
    virtual void start() {};
    virtual void update() {};

public:
    Engine();

    virtual ~Engine() = default;

    void create();
    void exit();
};


#endif //INC_3DZAVR_TDZAVR_H
