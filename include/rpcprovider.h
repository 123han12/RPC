#pragma once 
#include <iostream>
#include <google/protobuf/service.h>
#include <unordered_map>
#include <string> 

#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/TcpConnection.h>

 

// 如何设计RpcProvider类，使其和muduo网络库的代码相结合

/*

    请求头长度  服务名方法名参数长度参数

*/
class RpcProvider{
public :
    
    void RegisterService(google::protobuf::Service* service ) ; 
    void Run() ; 

    void SendRpcRepsonse(const muduo::net::TcpConnectionPtr& , google::protobuf::Message* ) ; 

private:
    
    struct ServiceInfo {
        google::protobuf::Service* servicePtr ; 
        std::unordered_map<std::string , const google::protobuf::MethodDescriptor* > MethodMap ;  
    } ; 
    std::unordered_map<std::string , ServiceInfo > ServiceMap ;  // 成功完成服务的注册。

    void onConnection(const muduo::net::TcpConnectionPtr& ) ; 
    void onMessage(const muduo::net::TcpConnectionPtr& , muduo::net::Buffer* , muduo::Timestamp ) ; 

    
} ; 