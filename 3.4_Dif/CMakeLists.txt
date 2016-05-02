set(PROJECT_NAME lab3.4)
set(LIB_NAME lib3.4)

project(${PROJECT_NAME})

set(SOURCE_LIB
./Source/Dif.cpp)

set(SOURCE_EXEC
./Source/main.cpp)

set(HEADER
./Header/Dif.h)

include_directories(
./Header)

add_library(${LIB_NAME} STATIC ${SOURCE_LIB} ${HEADER})

add_executable(${PROJECT_NAME} ${SOURCE_EXEC} ${HEADER})

target_link_libraries(${PROJECT_NAME} ${LIB_NAME})