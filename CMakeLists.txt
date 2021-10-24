cmake_minimum_required(VERSION 3.17)
project(shooter_server)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(shooter_server
        # game:
        Source.cpp
        Player.cpp
        Player.h
        Server.cpp
        Server.h
        Bonus.cpp
        Bonus.h
        Shooter.cpp
        Shooter.h
        ShooterConsts.h
        # 3d engine:
        engine/Consts.h
        engine/Vec3D.cpp
        engine/Vec3D.h
        engine/Vec2D.cpp
        engine/Vec2D.h
        engine/Mesh.h
        engine/Mesh.cpp
        engine/utils/Log.h
        engine/utils/Log.cpp
        engine/utils/Time.h
        engine/utils/Time.cpp
        engine/Engine.h
        engine/Engine.cpp
        engine/physics/RigidBody.cpp
        engine/physics/RigidBody.h
        engine/Object.cpp
        engine/Object.h
        engine/network/ClientUDP.cpp
        engine/network/ClientUDP.h
        engine/network/MsgType.cpp
        engine/network/MsgType.h
        engine/network/ReliableMsg.cpp
        engine/network/ReliableMsg.h
        engine/network/ServerUDP.cpp
        engine/network/ServerUDP.h
        engine/network/UDPConnection.cpp
        engine/network/UDPConnection.h
        engine/network/UDPSocket.cpp
        engine/network/UDPSocket.h
        )

if(APPLE OR UNIX)
    include_directories(/usr/local/include)
else()
    set(SFML_DIR "SFML-mingw32/lib/cmake/SFML")
    set(SFML_STATIC_LIBRARIES TRUE)
endif()

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
endif()

target_link_libraries(shooter_server sfml-audio sfml-network sfml-graphics sfml-window sfml-system)

# OpenGL part for MacOS
if (APPLE OR UNIX)
    set(GLEW_H /usr/local/Cellar/glew/2.1.0/include/GL)
    set(GLFW_H /usr/local/Cellar/glfw/3.2.1/include/GLFW)
    include_directories(${GLEW_H} ${GLFW_H})

    set(GLEW_LINK /usr/local/Cellar/glew/2.1.0/lib/libGLEW.2.1.dylib)
    set(GLFW_LINK /usr/local/Cellar/glfw/3.2.1/lib/libglfw.3.dylib)
    link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})

    target_link_libraries(shooter_server "-framework OpenGL")
    target_link_libraries(shooter_server "-framework GLUT")
endif()
