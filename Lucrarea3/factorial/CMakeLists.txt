cmake_minimum_required(VERSION 3.19.0-rc1)

project(factorial)

add_library(factorial STATIC factorial.cpp)

install(TARGETS factorial DESTINATION lib)
install(FILES factorial.h DESTINATION include)
