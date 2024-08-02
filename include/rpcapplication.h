#pragma once 
#include <string>
#include <iostream>
#include <unordered_map> 
class RpcApplication {
public:
    static RpcApplication& GetInstance() ; 
    void Init(std::string configFile) ; // 从配置文件中读取所需要的信息
    std::pair<std::string , int> GetRpcServerInfo() ; 
    std::pair<std::string , int> GetZookeeperInfo() ;
    std::pair<std::string , int> GetRedisInfo() ;  
    std::string GetKeepAliveKey() ; 
    std::string GetConfigPath() ; 
private:
    RpcApplication(){} ; 
    RpcApplication(const RpcApplication& ) = delete ; 
    RpcApplication(RpcApplication&&) = delete ; 

    std::unordered_map<std::string , std::string > configMap ;  

} ; 