set(PROJECT_NAME lab2.1)
set(LIB_NAME lib2.1)

project(${PROJECT_NAME})

set(SOURCE_LIB
./Source/equation.cpp)

set(SOURCE_EXEC
./Source/main.cpp)

set(HEADER
./Header/equation.h)

include_directories(./Header)

add_library(${LIB_NAME} STATIC ${SOURCE_LIB} ${HEADER})

add_executable(${PROJECT_NAME} ${SOURCE_EXEC} ${HEADER})

target_link_libraries(${PROJECT_NAME} ${LIB_NAME})