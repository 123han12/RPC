#pragma once 
#include <hiredis/hiredis.h>
#include <thread>
#include <functional>
#include <string> 
#include <iostream>
class Redis {

public:
    Redis() ; 
    ~Redis() ; 

    /// @brief 连接 redis 
    void Connect() ; 
    
    /// @brief 向redis中的 service hash集合注册field为method并且value 为 address 的服务
    /// @param service 
    /// @param method 
    /// @param addrss 
    void RegisterRpcAddress(std::string service , std::string method , std::string address ) ; 
    std::string GetAddress(std::string service , std::string method) ; 
    std::string RedisCommand(std::string command , std::string key , std::string value ) ;  

private:
    redisContext* conn ; 
} ; 

