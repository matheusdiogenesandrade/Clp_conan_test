cmake_minimum_required(VERSION 3.16)
project(CoinConanTest)

##### SETs
set (CMAKE_BUILD_TYPE Release) 
set (CMAKE_CXX_STANDARD 20)
set (BUILD_SHARED_LIBS On)

##### Includes
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
conan_basic_setup()

##### Additional packages 

##### Include Dirs 

include_directories(
    SYSTEM
    includes
    "${PROJECT_BINARY_DIR}"
    )

##### Compile options 

add_compile_options(-Wall
    -DIL_STD
    -Wfatal-errors
    -pedantic
    -fopenmp
    -DDEBUG
    -fdiagnostics-color=always
    #    -Wall
    -lz
    -std=c++20
    #
    -lm 
    -lpthread 
    -ldl
    -Wno-sign-compare
    )

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(
    main 
    ${SOURCES} 
    )
    

target_link_libraries(
    main 
    ${CONAN_LIBS} 
    pthread 
    m 
    dl
    )
