cmake_minimum_required(VERSION 2.4.6)

project(lex4 C)

ADD_DEFINITIONS(-Wall -g -O0)

include_directories(include)

add_subdirectory(src bin)
