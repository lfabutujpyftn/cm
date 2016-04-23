set(PROJECT_NAME lab1.2)
set(LIB_NAME lib1.2)

project(${PROJECT_NAME})

set(SOURCE_LIB
./Source/Prog.cpp)

set(SOURCE_EXEC
./Source/main.cpp)

set(HEADER
./Header/Prog.h)

include_directories(./Header)

add_library(${LIB_NAME} STATIC ${SOURCE_LIB} ${HEADER})

add_executable(${PROJECT_NAME} ${SOURCE_EXEC} ${HEADER})

target_link_libraries(${PROJECT_NAME} ${LIB_NAME})