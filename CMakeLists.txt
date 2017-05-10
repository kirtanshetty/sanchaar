cmake_minimum_required(VERSION 2.8)
project(prasaran)

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")

file(GLOB SOURCES "lib/*.c")

ADD_LIBRARY(prasaran SHARED ${SOURCES})

file(GLOB SOURCES_TEST_SERVER "test/*.c")

ADD_EXECUTABLE(test_prasaran_ss ${SOURCES_TEST_SERVER})

TARGET_LINK_LIBRARIES(test_prasaran_ss prasaran)