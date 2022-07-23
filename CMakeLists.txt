cmake_minimum_required(VERSION 3.17)
project(shooter_server)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(shooter_server
        # game:
        Source.cpp
        Player.cpp
        Player.h
        network/ShooterServer.cpp
        network/ShooterServer.h
        ShooterConsts.h
        network/ShooterMsgType.cpp
        network/ShooterMsgType.h
        network/Chat.cpp
        network/Chat.h
        # 3d engine:
        engine/Consts.h
        engine/Vec3D.cpp
        engine/Vec3D.h
        engine/Mesh.h
        engine/utils/Log.h
        engine/utils/Log.cpp
        engine/utils/Time.h
        engine/utils/Time.cpp
        engine/physics/RigidBody.h
        engine/Object.cpp
        engine/Object.h
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
    set(SFML_DIR "C:/Libraries/SFML/lib/cmake/SFML")
    set(SFML_STATIC_LIBRARIES TRUE)
endif()

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
endif()

target_link_libraries(shooter_server sfml-graphics sfml-network)
