cmake_minimum_required(VERSION 3.10)

project(shooter VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/game.cpp
)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED graphics window system)
target_link_libraries(${PROJECT_NAME}
        ${SFML_LIBRARIES}
        ${SFML_DEPENDENCIES}
)
