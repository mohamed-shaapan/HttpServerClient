cmake_minimum_required(VERSION 3.10)
project(HttpServerClient)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

set(Boost_INCLUDE_DIR /mnt/16BE8F73BE8F4A67/program/IDES/boost_1_65_0)

set(APP_SERVER ./Server)
set(APP_FILES ./Files)

find_package(Boost COMPONENTS system filesystem REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
include_directories(${APP_SERVER})

configure_file(${APP_FILES}/smile.jpeg
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${APP_FILES}/read.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${APP_FILES}/write.txt
        ${CMAKE_CURRENT_BINARY_DIR})

configure_file(${APP_FILES}/to_modify.txt
        ${CMAKE_CURRENT_BINARY_DIR} )

add_executable(HttpServerClient
        util/IOHandler.cpp
        Server/HttpServer.cpp
        Server/HttpHandler.cpp
        util/PortHandler.cpp
        Messages/Request.cpp
        Messages/Request.h
        Messages/Response.cpp
        Messages/Response.h
        Messages/Parser.cpp
        Messages/Parser.h
        Messages/HttpMessage.cpp
        Messages/HttpMessage.h Tests/main.cpp Tests/MessagesTests.cpp Tests/IOHandlerTests.cpp Tests/ServerTests.cpp)