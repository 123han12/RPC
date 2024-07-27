cmake_minimum_required(VERSION 3.0) 
project(RPC) 


set(CMAKE_CXX_STANDARD 17)
add_definitions(-DDEBUG)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
#指定rpc框架动态库的生成的路径在
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)  



include_directories(${PROJECT_SOURCE_DIR}/include )  
include_directories(${PROJECT_SOURCE_DIR}/example)  
link_directories(${PROJECT_SOURCE_DIR}/lib) 

add_subdirectory(${CMAKE_SOURCE_DIR}/src)   
add_subdirectory(${CMAKE_SOURCE_DIR}/example )  




