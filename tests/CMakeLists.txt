# Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
# Licensed under the MIT License
#

set(TEST_FILES
  ${TEST_FILES_DIR}/main_test.cpp
  ${TEST_FILES_DIR}/hand_test.cpp
  ${TEST_FILES_DIR}/poker_combinations_test.cpp
)

find_package(Boost 
  COMPONENTS unit_test_framework
  REQUIRED 
)

add_executable(SimplePlayingCardsGameTests ${TEST_FILES} ${SOURCE_FILES})

target_include_directories(SimplePlayingCardsGameTests PRIVATE ${SOURCE_FILES_DIR})

target_link_libraries(SimplePlayingCardsGameTests 
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
