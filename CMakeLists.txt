cmake_minimum_required(VERSION 3.26)
project(IT30340_Week3)

set(CMAKE_CXX_STANDARD 17)

add_executable(IT30340_Week3 main.cpp
        Week3/Bai3.1.cpp
        Week3/Bai3.2.cpp
        Week3/Bai3.3.cpp
        Week3/Bai3.4.cpp
        Week3/Bai3.5.cpp
        Week3/Bai3.6.cpp
        Week3/Bai3.7.cpp
        Week3/Bai8.cpp
        Week3/Bai9.cpp
        Week3/Bai10.cpp
        Week3/Bai11.cpp
        Week3/Bai12.cpp
)
add_executable(new_target Week3/Bai3.1.cpp)
add_executable(new_target1 Week3/Bai3.2.cpp)
add_executable(new_target2 Week3/Bai3.3.cpp)
add_executable(new_target3 Week3/Bai3.4.cpp)
add_executable(new_target4 Week3/Bai3.5.cpp)
add_executable(new_target5 Week3/Bai3.6.cpp)

add_executable(new_target6 Week3/Bai3.7.cpp)
add_executable(new_target7 Week3/Bai8.cpp)
add_executable(new_target8 Week3/Bai9.cpp)
add_executable(new_target9 Week3/Bai10.cpp)
add_executable(new_target10 Week3/Bai11.cpp)
add_executable(new_target11 Week3/Bai12.cpp)
