cmake_minimum_required(VERSION 3.19.0-rc1)

project(factorial)

add_subdirectory(./factorial)

add_executable(proiect1 main.cpp)

target_link_libraries(proiect1 factorial)

install(TARGETS proiect1 DESTINATION bin)
