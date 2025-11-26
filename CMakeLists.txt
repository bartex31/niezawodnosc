cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

#file(GLOB KOD_SRC "src/Kody/*.cpp")
file(GLOB KODERY_SRC "src/Kodery/*.cpp")
file(GLOB DEKODERY_SRC "src/Dekodery/*.cpp")

add_executable(untitled
        main.cpp
        #${KOD_SRC}
        src/Kody/BCH.cpp
        src/Kody/RC.cpp
        ${KODERY_SRC}
        ${DEKODERY_SRC}
        src/Transmision.cpp
        Wynik.cpp
)
