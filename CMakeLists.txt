cmake_minimum_required(VERSION 3.21)
project(ElevatorSimulator VERSION 0.1.0 LANGUAGES CXX)

# Потоки понадобятся для отдельного рабочего потока каждого лифта.
find_package(Threads REQUIRED)

add_library(elevator_core
    src/model/elevator.cpp
    src/simulation.cpp
)
add_library(elevator::core ALIAS elevator_core)
target_include_directories(elevator_core PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_compile_features(elevator_core PUBLIC cxx_std_17)
set_target_properties(elevator_core PROPERTIES CXX_EXTENSIONS OFF)
target_link_libraries(elevator_core PUBLIC Threads::Threads)

add_executable(elevator_simulator app/main.cpp)
target_link_libraries(elevator_simulator PRIVATE elevator::core)
set_target_properties(elevator_simulator PROPERTIES CXX_EXTENSIONS OFF)

foreach(target IN ITEMS elevator_core elevator_simulator)
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4 /utf-8)
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endforeach()

install(TARGETS elevator_simulator RUNTIME DESTINATION bin)
