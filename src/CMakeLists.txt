file(GLOB SRC_LIST ${CMAKE_SOURCE_DIR}/src/*.cc ${CMAKE_SOURCE_DIR}/src/*.cpp )
add_library(rpc  ${SRC_LIST}  ) 
# 为什么这里muduo_net 必须需要再muduo_base之前?
# target_link_libraries(rpc muduo_net muduo_base  pthread ) 
include_directories(/usr/local/lib) 
target_link_libraries(rpc 
-Wl,--start-group
muduo_base 
pthread 
muduo_net 
zookeeper_mt
-Wl,--end-group
)  
# 这里将rpc框架生成一个动态库文件
