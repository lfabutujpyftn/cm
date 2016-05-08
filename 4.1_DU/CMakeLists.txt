set(PROJECT_NAME lab4.1)
set(LIB_NAME lib4.1)

project(${PROJECT_NAME})

set(SOURCE_LIB
./Source/DU.cpp)

set(SOURCE_EXEC
./Source/main.cpp)

set(HEADER
./Header/DU.h)

include_directories(
./Header)

add_library(${LIB_NAME} STATIC ${SOURCE_LIB} ${HEADER})

add_executable(${PROJECT_NAME} ${SOURCE_EXEC} ${HEADER})

target_link_libraries(${PROJECT_NAME} ${LIB_NAME})