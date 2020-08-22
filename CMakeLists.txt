CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE-CXX-STANDARD 11)

ADD_EXECUTABLE(test
	tests/unit_test.cpp
	src/line.cpp
	src/rectangle.cpp
	src/character.cpp
	src/flyweight.cpp
	src/window.cpp
	src/prompt_selector.cpp
	src/parse_novice.cpp
	src/parse_intermediate.cpp
	src/parse_advanced.cpp
	src/parse_random.cpp
)

ADD_EXECUTABLE(sim
	src/sim.cpp
        src/line.cpp
        src/rectangle.cpp
        src/character.cpp
        src/char_iterator.cpp
        src/flyweight.cpp
        src/window.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
