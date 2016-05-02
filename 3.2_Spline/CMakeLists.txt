set(PROJECT_NAME lab3.2)
set(LIB_NAME lib3.2)
set(LIB_NAME2 lib1.2)

project(${PROJECT_NAME})

set(SOURCE_LIB
./Source/Spline.cpp)

set(SOURCE_LIB2
../1.2_Prog/Source/Prog.cpp)

set(SOURCE_EXEC
./Source/main.cpp)

set(HEADER
./Header/Spline.h)

set(HEADER2
../1.2_Prog/Header/Prog.h)

include_directories(
./Header
../1.2_Prog/Header)

add_library(${LIB_NAME} STATIC ${SOURCE_LIB} ${HEADER})

add_library(${LIB_NAME2} STATIC ${SOURCE_LIB2} ${HEADER2})

add_executable(${PROJECT_NAME} ${SOURCE_EXEC} ${HEADER} ${HEADER2})

target_link_libraries(${PROJECT_NAME} ${LIB_NAME})

target_link_libraries(${PROJECT_NAME} ${LIB_NAME2})