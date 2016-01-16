# This configuration file outlines some of the ways Arduino CMake
# can be used. For a detailed explenation of all the options please
# reade README.rst.

set(CMAKE_TOOLCHAIN_FILE "~/proj/arduino/cmake/cmake/ArduinoToolchain.cmake") # Arduino Toolchain
list(APPEND CMAKE_MODULE_PATH "~/proj/arduino/cmake/cmake")


cmake_minimum_required(VERSION 2.8)

project(lcd C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -fno-threadsafe-statics")

set(ARDUINO_DEFAULT_BOARD leonardo) # Default Board ID, when not specified
link_directories(~/proj/arduino/libraries)


#====================================================================#
# Advanced static library exmaple
#====================================================================#
#generate_arduino_library(lcd_lib
#    SRCS lcd_lib.cpp
#    HDRS lcd_lib.h
#    BOARD leonardo)
#
#generate_arduino_library(keys_lib
#    SRCS keys.cpp
#    HDRS keys.h
#    BOARD leonardo)
#
#====================================================================#
# Advanced firwmare example
#====================================================================#
generate_arduino_firmware(moisture
    SRCS src/main.cpp
    PROGRAMMER usbasp
    BOARD leonardo)
