#pragma once 
#include <unordered_map> 
#include <string> 


class RpcConfig {

public:
    static RpcConfig& GetInstance() ; 
    void Init(std::string configFile) ; // 从配置文件中读取所需要的信息
    std::pair<std::string , int> GetRpcServerInfo() ; 
    std::pair<std::string , int> GetZookeeperInfo() ; 
private:
    RpcConfig(){} ; 
    RpcConfig(const RpcConfig& ) = delete ; 
    RpcConfig(RpcConfig&&) = delete ; 

    std::unordered_map<std::string , std::string > configMap ;  

} ; 