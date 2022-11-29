cmake_minimum_required(VERSION 3.23)
project(icp_individual_c__)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(icp_individual_c__
        src/airline.cpp
        src/airport.cpp
        src/flight_path.cpp
        src/main.cpp
        src/reader.cpp
        src/route.cpp include/airline.h include/airport.h include/flight_path.h include/node.h include/reader.h include/route.h src/node.cpp)
