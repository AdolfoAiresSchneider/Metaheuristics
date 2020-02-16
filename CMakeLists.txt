cmake_minimum_required(VERSION 3.15)
project(Metaheuristics)

set(CMAKE_CXX_STANDARD 17)

add_executable(Metaheuristics main.cpp Routing/Point.h Routing/Tsp/Tsp.cpp Routing/Tsp/Tsp.h Routing/Tsp/Solution/Solution.cpp Routing/Tsp/Solution/Solution.h Routing/Tsp/Ts/Ts.cpp Routing/Tsp/Ts/Ts.h Routing/Tsp/Ga/Ga.cpp Routing/Tsp/Ga/Ga.h Routing/Tsp/GaTs/GaTs.cpp Routing/Tsp/GaTs/GaTs.h Routing/Tsp/Tests/GaTest.cpp Routing/Tsp/Tests/TsTest.cpp Routing/Tsp/Tests/GaTsTest.cpp)