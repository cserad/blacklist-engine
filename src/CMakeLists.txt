SET(SOURCES
        main.cpp
        database.cpp
        hashgenerator.cpp
        scanner.cpp
)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

ADD_EXECUTABLE(blacklist-engine ${SOURCES})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::Core)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::Sql)