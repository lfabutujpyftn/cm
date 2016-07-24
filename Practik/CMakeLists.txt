set(PROJECT_NAME practik)
set(LIB_NAME practikLib)
set(LIB_NAME1 LU)

project(${PROJECT_NAME})

set(SOURCE_LIB
./Source/Pr.cpp)

set(SOURCE_LIB1
../1.1_LU/Source/LU.cpp)

set(SOURCE_EXEC
./Source/main.cpp)

set(HEADER
./Header/Pr.h)
set(HEADER1
../1.1_LU/Header/LU.h)

include_directories(
./Header
../1.1_LU/Header)

add_library(${LIB_NAME} STATIC ${SOURCE_LIB} ${HEADER})
add_library(${LIB_NAME1} STATIC ${SOURCE_LIB1} ${HEADER1})

add_executable(${PROJECT_NAME} ${SOURCE_EXEC})

target_link_libraries(${PROJECT_NAME} ${LIB_NAME})
target_link_libraries(${PROJECT_NAME} ${LIB_NAME1})