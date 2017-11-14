cmake_minimum_required(VERSION 2.6)


message(STATUS "Current dir : --- ${CMAKE_CURRENT_SOURCE_DIR}")
set(PROJECT_NAME xsrobot)
set(CROSS_PLATFORM arm)
set(CMAKE_C_COMPILER "arm-linux-gnueabi-gcc")
set(CMAKE_CXX_COMPILER "arm-linux-gnueabi-g++")        
set(CMAKE_ASM_COMPILER "arm-linux-gnueabi-gcc")
set(LIBS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_C_FLAGS "-Wall -O2 -Os -D_REENTRANT -lm -lpthread")
set(CMAKE_CXX_FLAGS "-Wall -O2 -Os -D_REENTRANT  -lm -lpthread")
message(STATUS "===> Cross Platform : arm")
if (NOT CONF_LIBRARY)
        set(CONF_LIBRARY "static")
endif (NOT CONF_LIBRARY)
set(ALL_SRC_COMPILE no)
set(PROJECT_SOURCE_DIR)

include_directories(src/app src/modules/drvt src/modules/log4c 
src/modules/video include)


message(STATUS "CMAKE_EXE_LINKER_FLAGS : ${CMAKE_EXE_LINKER_FLAGS}")


add_subdirectory(src) 

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/app/)

set(mainsrc ${SRC_DIR}main.c )

add_executable(${PROJECT_NAME} ${mainsrc})



target_link_libraries(${PROJECT_NAME} ${LIBS_DIR}/libsqlite3.so)

target_link_libraries(${PROJECT_NAME} ${LIBS_DIR}/libexpat.so)

target_link_libraries(${PROJECT_NAME} ${LIBS_DIR}/liblog4c.so)

target_link_libraries(${PROJECT_NAME} log)

target_link_libraries(${PROJECT_NAME} drvt)

target_link_libraries(${PROJECT_NAME} capture)


SET(EXECUTABLE_OUTPUT_PATH bin)
