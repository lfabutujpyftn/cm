set(PROJECT_NAME lab1.5)
set(LIB_NAME lib1.5)

project(${PROJECT_NAME})

set(SOURCE_LIB
./Source/QR.cpp)

set(SOURCE_EXEC
./Source/main.cpp)

set(HEADER
./Header/QR.h)

include_directories(./Header)

add_library(${LIB_NAME} STATIC ${SOURCE_LIB} ${HEADER})

add_executable(${PROJECT_NAME} ${SOURCE_EXEC} ${HEADER})

target_link_libraries(${PROJECT_NAME} ${LIB_NAME})