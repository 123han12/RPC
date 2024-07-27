set(SRC  )   
add_executable(provider userservice.cpp ../user.pb.cc )  
target_link_libraries(provider rpc protobuf)  
