cmake_minimum_required(VERSION 3.27)
project(CombatSim)

set(CMAKE_CXX_STANDARD 17)

add_executable(CombatSim main.cpp
        Characters/Character.h
        Items/Items.h
        Characters/Character.cpp
        Characters/Player.h
        Characters/Enemy.h
        Environments/World.cpp
        Environments/World.h
)
