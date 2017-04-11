cmake_minimum_required(VERSION 2.8.9)
project(Arbol)

include_directories(include)

set(SOURCES src/NodoP.cpp src/Arbol.cpp src/main.cpp)

add_executable(Arbol ${SOURCES})
