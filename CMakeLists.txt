#set(ARDUINO_DEFAULT_BOARD uno)

set(ARDUINO_DEFAULT_BOARD pro)
set(ARDUINO_CPU 16MHzatmega328)

set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake)

cmake_minimum_required(VERSION 2.8)

project(SmartAirFreshener C CXX)

link_directories(${CMAKE_CURRENT_LIST_DIR}/libs)

add_subdirectory(blink)
add_subdirectory(anabiosis)
add_subdirectory(freshener)
