set(PROJECT_NAME lab4.2)
set(LIB_NAME lib4.2)
set(LIB_NAME2 lib1.2)
set(LIB_NAME3 lib1.1)

project(${PROJECT_NAME})

set(SOURCE_LIB
./Source/DU.cpp)

set(SOURCE_LIB2
../1.2_Prog/Source/Prog.cpp)

set(SOURCE_LIB3
../1.1_LU/Source/LU.cpp)

set(SOURCE_EXEC
./Source/main.cpp)

#set(HEADER
#./Header/DU2.h
#../4.1_DU/Header/DU.h)
set(HEADER2
../1.2_Prog/Header/Prog.h)
set(HEADER1
./Header/DU2.h)
set(HEADER3
../1.1_LU/Header/LU.h)

include_directories(
./Header
../1.2_Prog/Header
../1.1_LU/Header)
#../4.1_DU/Header)

add_library(${LIB_NAME} STATIC ${SOURCE_LIB} ${HEADER1})
add_library(${LIB_NAME2} STATIC ${SOURCE_LIB2} ${HEADER2})
add_library(${LIB_NAME3} STATIC ${SOURCE_LIB3} ${HEADER3})

add_executable(${PROJECT_NAME} ${SOURCE_EXEC} ${HEADER1})

target_link_libraries(${PROJECT_NAME} ${LIB_NAME})
target_link_libraries(${PROJECT_NAME} ${LIB_NAME2})
target_link_libraries(${PROJECT_NAME} ${LIB_NAME3})