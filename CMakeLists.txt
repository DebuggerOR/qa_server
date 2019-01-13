cmake_minimum_required(VERSION 3.13)
project(proj2222)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(proj2222 main.cpp AStar.cpp BestFirstSearch.cpp BFS.cpp CacheManager.cpp ClientHandler.cpp DFS.cpp FileCacheManager.cpp MyParallelServer.cpp MySerialServer.cpp MyTestClientHandler.cpp Server.cpp Solver.cpp State.cpp StringReverser.cpp Searchable.cpp Searcher.cpp TestSearcher.cpp SearchSolver.cpp SolverImp.cpp MatrixCreator.cpp Matrix.cpp Utils.cpp Point.cpp)