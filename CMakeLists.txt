cmake_minimum_required(VERSION 3.5)

project(utilLib CXX ASM)

set(CMAKE_CXX_STANDARD 20)

pico_sdk_init()

add_library( utilLib
    disable_interrupt.hpp
    disable_interrupt.cpp
    )

target_link_libraries( utilLib
  pico_stdlib 
  
  # Using Pico W
  pico_cyw43_arch_none
)

target_include_directories(utilLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
