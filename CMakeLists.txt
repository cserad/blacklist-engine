CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(blacklist-engine)
SET(CMAKE_CXX_STANDARD 11)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)

FIND_PACKAGE(Qt5Core)
FIND_PACKAGE(Qt5Sql)

INCLUDE_DIRECTORIES(src)

ADD_SUBDIRECTORY(src)
