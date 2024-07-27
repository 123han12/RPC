include_directories(${PROJECT_SOURCE_DIR}/example) 
set(SRC userclient.cpp ../user.pb.cc ) 

add_executable(consumer ${SRC} ) 
target_link_libraries(consumer rpc protobuf ) 