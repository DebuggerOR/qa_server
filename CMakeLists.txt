cmake_minimum_required(VERSION 3.13)
project(proj2222)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(proj2222 main.cpp ClientHandler.cpp MyTestClientHandler.cpp Server.cpp StringReverser.cpp MatrixCreator.cpp Matrix.cpp Utils.cpp Point.cpp MyClientHandler.cpp)