set(PROJECT_NAME freshner)
project(${PROJECT_NAME} C CXX)
set(${PROJECT_NAME}_SRCS freshner.cpp)
generate_arduino_firmware(${PROJECT_NAME})
