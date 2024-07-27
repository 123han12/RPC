#include "rpcconfig.h"
#include <iostream>
const int BUFSIZE = 1024 ; 

RpcConfig& RpcConfig::GetInstance() {
    static RpcConfig app ; 
    return app ; 
}

// 功能函数
// 去除后置空格
static std::string removeLastSpace(const std::string& data ) {
    int idx = 0 ; 
    idx = data.find_last_not_of(' ') ; 
    return data.substr(0 , idx + 1) ; 
}

// 去除前置空格
static std::string removeFirstSpace(const std::string& data ) {
    int idx = 0 ; 
    idx = data.find_first_not_of(' ') ; 
    return data.substr(idx , data.size() - idx ) ; 
}


// 读取配置文件中的内容到实例中
void RpcConfig::Init(std::string configFile) {
    char buffer[BUFSIZ] ; 
    FILE* pfile = fopen(configFile.c_str() , "r" ) ; // 以只读的方式
    if(pfile == NULL ) {
        std::cout << "open config file failed!...." << std::endl ; 
    }
    std::cout << "open config file sucess!........." << std::endl ; 
    while(fgets(buffer , sizeof(buffer) , pfile ) != NULL ) {
        std::string line(buffer) ; 
        int idx = 0 ; 
        idx = line.find_last_of('\n') ; 
        line = line.substr(0 , idx ) ;   // 处理 \n 字符 
        if(line.empty() ) {
            continue ; 
        }

        line = removeFirstSpace(line) ; // 处理前置空格
        line = removeLastSpace(line) ;  // 处理后置空格

        // 为空表示这行就是无用的
        if(line.empty() ) {
            continue ; 
        }

        // 该行为注释行
        if(line[0] == '#' ) continue ; 

        std::string key , value ; 
        idx = line.find('=') ; 
        if(idx == std::string::npos ) {
            std::cout << "error occur when we read config file " << std::endl ; 
            exit(EXIT_FAILURE) ; 
        }
        key = line.substr(0 , idx ) ; 
        value = line.substr(idx + 1 , line.size() - idx - 1 ) ; 
        key = removeLastSpace(key) ; // 移除key的后置空格
        value = removeFirstSpace(value) ; // 移除value 的前置空格
        if(key.empty() || value.empty() ) {
            std::cout << "error occur when we read config file " << std::endl ; 
            exit(EXIT_FAILURE) ; 
        }
        configMap[key] = value ; 
    }
    // 关闭这个文件
    fclose(pfile) ; 
    for(auto [key , value] : configMap ) {
        std::cout << key << std::endl ; 
        std::cout << value << std::endl ; 
    }

}

std::pair<std::string , int> RpcConfig::GetRpcServerInfo() {
    std::string rpcip = "rpcserverip" ; 
    std::string rpcport = "rpcserverport" ; 
    if(configMap.find(rpcip) == configMap.end() ) {
        std::cout << "load rpcserver ip error" << std::endl ;
    }
    if(configMap.find(rpcport) == configMap.end() ) {
        std::cout << "load rpcserver port error" << std::endl ; 
    }
    std::string ip = configMap[rpcip] ; 
    int port = atoi(configMap[rpcport].c_str() ) ; 
    return make_pair(ip , port) ; 

}


std::pair<std::string , int> RpcConfig::GetZookeeperInfo() {
    std::string zookeeperip = "zookeeperip" ; 
    std::string zookeeperport = "zookeeperport" ; 
    if(configMap.find(zookeeperip) == configMap.end() ) {
        std::cout << "load zookeeperip ip error" << std::endl ;
    }
    if(configMap.find(zookeeperport) == configMap.end() ) {
        std::cout << "load zookeeperport port error" << std::endl ; 
    }
    std::string ip = configMap[zookeeperip] ; 
    int port = atoi(configMap[zookeeperport].c_str() ) ; 
    return make_pair(ip , port) ; 
}




