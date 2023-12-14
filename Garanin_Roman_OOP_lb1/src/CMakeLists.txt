cmake_minimum_required(VERSION 3.26)
project(Garanin_Roman_OOP_lb)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)

add_executable(Garanin_Roman_OOP_lb
        controller.cc
        main.cpp
        player.cc
        playing_field.cc
        cell.cc
        teleport.cc
        first_aid_kit.cc
        mine.cc
        builder_field.cc
        input_from_keyboard.cc
        interlayer.cc
        game.cc
        tracker.cc
        terminal_render.cc
        massage_log_win.cpp
        massage_log_lose.cpp
        massage_log_new_game.cpp
        massage_log_new_game.cpp
        massage_key_push.cpp
        massage_key_not_work.cpp
        log_of_file.cpp
        log_of_terminal.cpp)

set_target_properties(Garanin_Roman_OOP_lb PROPERTIES
        OUTPUT_NAME main
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/..")
