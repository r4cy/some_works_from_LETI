cmake_minimum_required(VERSION 3.26)
project(Garanin_Roman_OOP_lb3)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)

add_executable(Garanin_Roman_OOP_lb3
        controller.cc
        main.cpp
        player.cc
        playing_field.cc
        cell.cc
        teleport.cc
        first_aid_kit.cc
        mine.cc
        builder_field.cc)

set_target_properties(Garanin_Roman_OOP_lb3 PROPERTIES
        OUTPUT_NAME main
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/..")
