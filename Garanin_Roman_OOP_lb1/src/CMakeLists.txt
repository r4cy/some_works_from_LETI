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
        message_log_win.cc
        message_log_lose.cc
        message_log_new_game.cc
        message_log_new_game.cc
        message_key_push.cc
        message_key_not_work.cc
        log_of_file.cc
        log_of_terminal.cc)

set_target_properties(Garanin_Roman_OOP_lb PROPERTIES
        OUTPUT_NAME main
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/..")
