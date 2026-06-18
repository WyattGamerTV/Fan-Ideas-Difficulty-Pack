cmake_minimum_required(VERSION 3.25)

set(Geode_DIR "$ENV{GEODE_SDK}/loader")
find_package(Geode REQUIRED)

project(FanIdeasDifficultyPack)

add_geode_mod(
    wyattgamertv.fan_ideas_difficulties
    VERSION v1.0.0
    CONTAINS src/main.cpp
)
