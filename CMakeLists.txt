cmake_minimum_required(VERSION 2.8)
project(sanchaar)

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")

file(GLOB SOURCES "src/*.c")

ADD_LIBRARY(sanchaar SHARED ${SOURCES})

file(GLOB SOURCES_TEST_SERVER "test/sstest.c")
file(GLOB SOURCES_TEST_SERVER "test/sclient.c")

ADD_EXECUTABLE(test_sanchaar_ss ${SOURCES_TEST_SERVER})

TARGET_LINK_LIBRARIES(test_sanchaar_ss sanchaar)