set(PROJECT_NAME anabiosis)
project(${PROJECT_NAME} C CXX)
set(${PROJECT_NAME}_SRCS anabiosis.cpp)
generate_arduino_firmware(${PROJECT_NAME})
