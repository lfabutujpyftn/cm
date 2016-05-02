set(PROJECT_NAME lab3.5)
set(LIB_NAME lib3.5)

project(${PROJECT_NAME})

set(SOURCE_LIB
./Source/Int.cpp)

set(SOURCE_EXEC
./Source/main.cpp)

set(HEADER
./Header/Int.h)

include_directories(
./Header)

add_library(${LIB_NAME} STATIC ${SOURCE_LIB} ${HEADER})

add_executable(${PROJECT_NAME} ${SOURCE_EXEC} ${HEADER})

target_link_libraries(${PROJECT_NAME} ${LIB_NAME})