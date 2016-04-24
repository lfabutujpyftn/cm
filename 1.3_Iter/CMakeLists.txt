set(PROJECT_NAME lab1.3)
set(LIB_NAME lib1.3)

project(${PROJECT_NAME})

set(SOURCE_LIB
./Source/Iter.cpp
./Source/Zeid.cpp)

set(SOURCE_EXEC
./Source/main.cpp)

set(HEADER
./Header/Iter.h
./Header/Zeid.h)

include_directories(./Header)

add_library(${LIB_NAME} STATIC ${SOURCE_LIB} ${HEADER})

add_executable(${PROJECT_NAME} ${SOURCE_EXEC} ${HEADER})

target_link_libraries(${PROJECT_NAME} ${LIB_NAME})