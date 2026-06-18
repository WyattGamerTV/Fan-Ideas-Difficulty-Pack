cmake_minimum_required(VERSION 3.25)


if(DEFINED ENV{GEODE_SDK})
    list(APPEND CMAKE_PREFIX_PATH "$ENV{GEODE_SDK}")
endif()

project(FanIdeasDifficultyPack)

find_package(Geode REQUIRED)

add_geode_mod(
    wyattgamertv.fan_ideas_difficulties
    VERSION v1.0.0
    CONTAINS src/main.cpp
)
