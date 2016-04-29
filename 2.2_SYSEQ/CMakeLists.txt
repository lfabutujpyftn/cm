set(PROJECT_NAME lab2.2)
set(LIB_NAME lib2.2)

project(${PROJECT_NAME})

set(SOURCE_LIB
./Source/sysEquation.cpp)

set(SOURCE_EXEC
./Source/main.cpp)

set(HEADER
./Header/sysEquation.h)

include_directories(./Header)

add_library(${LIB_NAME} STATIC ${SOURCE_LIB} ${HEADER})

add_executable(${PROJECT_NAME} ${SOURCE_EXEC} ${HEADER})

target_link_libraries(${PROJECT_NAME} ${LIB_NAME})