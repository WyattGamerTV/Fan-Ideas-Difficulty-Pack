cmake_minimum_required(VERSION 3.25)

project(FanIdeasDifficultyPack)

include(FetchContent)
FetchContent_Declare(
    GeodeCMake
    URL "https://github.com/geode-sdk/cmake/archive/main.zip"
)
FetchContent_MakeAvailable(GeodeCMake)

find_package(Geode REQUIRED)

add_geode_mod(
    wyattgamertv.fan_ideas_difficulties
    VERSION v1.0.0
    CONTAINS src/main.cpp
)
