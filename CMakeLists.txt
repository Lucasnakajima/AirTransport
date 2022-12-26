cmake_minimum_required(VERSION 3.23)
project(AirTransport)

set(CMAKE_CXX_STANDARD 14)

add_executable(AirTransport main.cpp Classes/Graph.cpp Classes/Graph.h Classes/Database.cpp Classes/Database.h Classes/Airport.cpp Classes/Airport.h Classes/Airline.cpp Classes/Airline.h)
