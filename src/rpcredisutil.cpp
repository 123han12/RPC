#include "rpcredisutil.h"
#include <iostream>
#include "rpcapplication.h"

Redis::Redis(): conn(nullptr) {} 

Redis::~Redis() {
    if(conn != nullptr ) {
        redisFree(conn) ; 
    }
}

/// @brief 连接 redis
/// @param redisip 
/// @param redisport 
void Redis::Connect() {
    std::pair<std::string , int> redisInfo = RpcApplication::GetInstance().GetRedisInfo() ; 
    std::string ip = redisInfo.first ; 
    int port = redisInfo.second ; 
    conn = redisConnect( ip.c_str() , port ) ; 
    if (conn->err)
    {
        std::cout << __FILE__  << __LINE__ << "init redis failed..." << std::endl ; 
        redisFree(conn);                
        exit(EXIT_FAILURE) ; 
    }
}

/// @brief 向redis中的 service hash集合注册field为method并且value 为 address 的服务
/// @param service 
/// @param method 
/// @param addrss 
void Redis::RegisterRpcAddress(std::string service , std::string method , std::string address ) {
    redisReply * reply = (redisReply* ) redisCommand(conn, "hset %s %s %s"
        , service.c_str() , method.c_str() , address.c_str()
    ); 
    if(reply->type == REDIS_REPLY_ERROR) {
        std::cout << __FILE__  << __LINE__ << reply->str << std::endl ; 
        freeReplyObject(reply) ; 
        exit(EXIT_FAILURE) ; 
    }
    freeReplyObject(reply) ; 
} 

std::string Redis::GetAddress(std::string service , std::string method) {
    redisReply * reply = (redisReply* ) redisCommand(conn, "hget %s %s"
        , service.c_str() , method.c_str() 
    ); 
    if(reply->type == REDIS_REPLY_ERROR) {
        std::cout << __FILE__  << __LINE__ << reply->str << std::endl ; 
        freeReplyObject(reply) ; 
        exit(EXIT_FAILURE) ; 
    }
    std::string addr = reply->str ; 
    freeReplyObject(reply) ; 
    return addr ;  // 获取到指定的ip:port
}


std::string Redis::RedisCommand(std::string command , std::string key , std::string value ) {
    redisReply * reply ; 
    
    if(value == "") {
        reply =(redisReply* ) redisCommand(conn , "%s %s" , 
        command.c_str() , key.c_str() ) ;   
    }else {
        reply =(redisReply* ) redisCommand(conn , "%s %s %s" , 
        command.c_str() , key.c_str() , value.c_str() 
        );  
    }
    
    if(reply->type == REDIS_REPLY_ERROR) {
        std::cout << __FILE__  << __LINE__ << reply->str << std::endl ; 
        freeReplyObject(reply) ; 
        exit(EXIT_FAILURE) ; 
    }
    std::string answer = reply->str ; 
    freeReplyObject(reply) ; 
    return answer ; 
}
