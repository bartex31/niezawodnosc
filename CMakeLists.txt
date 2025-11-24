cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        src/Kody/RC.cpp
        src/Kodery/KoderRC.cpp
        src/Dekodery/DekoderRC.cpp
        src/Transmision.cpp
        Wynik.cpp
)
