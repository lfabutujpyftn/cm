set(PROJECT_NAME lab4.2)
set(LIB_NAME lib4.2)
set(LIB_NAME2 lib1.2)

project(${PROJECT_NAME})

set(SOURCE_LIB
./Source/DU.cpp)

set(SOURCE_LIB2
../1.2_Prog/Source/Prog.cpp)

set(SOURCE_EXEC
./Source/main.cpp)

#set(HEADER
#./Header/DU2.h
#../4.1_DU/Header/DU.h)
set(HEADER2
../1.2_Prog/Header/Prog.h)
set(HEADER1
./Header/DU2.h)

include_directories(
./Header
../1.2_Prog/Header)
#../4.1_DU/Header)

add_library(${LIB_NAME} STATIC ${SOURCE_LIB} ${HEADER1})
add_library(${LIB_NAME2} STATIC ${SOURCE_LIB2} ${HEADER2})

add_executable(${PROJECT_NAME} ${SOURCE_EXEC} ${HEADER1})

target_link_libraries(${PROJECT_NAME} ${LIB_NAME})
target_link_libraries(${PROJECT_NAME} ${LIB_NAME2})