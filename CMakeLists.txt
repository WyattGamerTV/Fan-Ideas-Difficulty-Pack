cmake_minimum_required(VERSION 3.25)

if(DEFINED env{GEODE_SDK})
    list(APPEND CMAKE_PREFIX_PATH "$ENV{GEODE_SDK}")
else()
    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone")
endif()

project(FanIdeasDifficultyPack)

find_package(Geode REQUIRED)

add_geode_mod(
    wyattgamertv.fan_ideas_difficulties
    VERSION v1.0.0
    CONTAINS src/main.cpp
)
