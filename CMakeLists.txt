cmake_minimum_required(VERSION 2.8)
project(sanchaar)

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")

file(GLOB SOURCES "src/server/*")

ADD_LIBRARY(sanchaar SHARED ${SOURCES})

file(GLOB SOURCES_TEST_SERVER "test/sstest.c")
ADD_EXECUTABLE(test_sanchaar_ss ${SOURCES_TEST_SERVER})
TARGET_LINK_LIBRARIES(test_sanchaar_ss sanchaar)

file(GLOB SOURCES_TEST_CLIENT "test/sclient.c")
ADD_EXECUTABLE(test_sanchaar_sc ${SOURCES_TEST_CLIENT})
TARGET_LINK_LIBRARIES(test_sanchaar_sc sanchaar)