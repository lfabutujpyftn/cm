set(PROJECT_NAME lab2.2)
set(LIB_NAME1 lib2.2)
set(LIB_NAME2 lib1.1)

project(${PROJECT_NAME})

set(SOURCE_LIB1
./Source/sysEquation.cpp)
set(SOURCE_LIB2
../1.1_LU/Source/LU.cpp)

set(SOURCE_EXEC
./Source/main.cpp)

set(HEADER1
./Header/sysEquation.h
../1.1_LU/Header/LU.h)

set(HEADER2
../1.1_LU/Header/LU.h)


include_directories(
./Header
../1.1_LU/Header)

add_library(${LIB_NAME1} STATIC ${SOURCE_LIB1} ${HEADER1})

add_library(${LIB_NAME2} STATIC ${SOURCE_LIB2} ${HEADER2})

add_executable(${PROJECT_NAME} ${SOURCE_EXEC} ${HEADER1})

target_link_libraries(${PROJECT_NAME} ${LIB_NAME1})
target_link_libraries(${PROJECT_NAME} ${LIB_NAME2})