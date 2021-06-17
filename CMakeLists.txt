# Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
# Licensed under the MIT License
#

cmake_minimum_required(VERSION 3.16)

project(SimplePlayingCardsGame 
  VERSION 0.9
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)

message(STATUS "Build configuration: " ${CMAKE_BUILD_TYPE})

set(SOURCE_FILES_DIR
  ${CMAKE_SOURCE_DIR}/src
)

set(TEST_FILES_DIR
  ${CMAKE_SOURCE_DIR}/tests
)

set(MAIN_SOURCE_FILES
  ${SOURCE_FILES_DIR}/main.cpp
) 

set(SOURCE_FILES 
  ${SOURCE_FILES_DIR}/game.cpp
  ${SOURCE_FILES_DIR}/playingcards/card.cpp
  ${SOURCE_FILES_DIR}/playingcards/deck.cpp
  ${SOURCE_FILES_DIR}/playingcards/hand.cpp
  ${SOURCE_FILES_DIR}/playingcards/poker_combinations.cpp
  ${SOURCE_FILES_DIR}/ui/console/cards_hand_view.cpp
  ${SOURCE_FILES_DIR}/ui/console/game_view.cpp
  ${SOURCE_FILES_DIR}/ui/console/label.cpp
  ${SOURCE_FILES_DIR}/ui/console/menu_option_input.cpp
  ${SOURCE_FILES_DIR}/ui/console/menu_option.cpp
  ${SOURCE_FILES_DIR}/ui/console/menu.cpp
  ${SOURCE_FILES_DIR}/ui/console/widgets_container.cpp
)

add_executable(SimplePlayingCardsGame ${MAIN_SOURCE_FILES} ${SOURCE_FILES})

target_include_directories(SimplePlayingCardsGame PRIVATE ${SOURCE_FILES_DIR})

#### Tests ####

add_subdirectory(${TEST_FILES_DIR})

enable_testing()

add_test(NAME SimplePlayingCardsGameTests
  COMMAND SimplePlayingCardsGameTests 
)
