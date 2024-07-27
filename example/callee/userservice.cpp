#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "user.pb.h"
#include "rpcapplication.h"
#include "rpcprovider.h"

#include <google/protobuf/message.h> 


class UserService : public protocol::UserServiceRpc
{
public: 
    bool Login(int id , const std::string& pwd ) {
        std::cout << "Login callee sucess!" << std::endl ; 
        return true ; 
    }

    void Login(google::protobuf::RpcController* controller,   // 这个函数会被回调起来
                       const ::protocol::LoginRequest* request,
                       ::protocol::LoginResponse* response,
                       ::google::protobuf::Closure* done) override
    {
        
        // 从 request 中获得参数
        int id = request->id() ; 
        std::string password = request->password() ; 

        // 执行函数
        bool result = Login(id , password ) ; 

        // 组装返回值
        ::protocol::errInfo* errinfo = response->mutable_errinfo() ; 
        errinfo->set_errcode(0) ; 
        errinfo->set_errmsg("sucess call!") ; 
        response->set_result(result) ; 

        // 调用回调函数负责序列化结果并且发送给客户端
        done->Run() ; 
    }

} ; 

// 解析传入的参数
std::string ParseParameter(int argc , char** argv ) {
    int opt ; 
    std::string configFile ; 
    while((opt = getopt(argc , argv , "i:h")) != -1 ) {
        switch (opt) {
            case 'i' : 
                configFile = optarg ; 
                return configFile ; 
                break ; 
            case 'h' : 
                std::cout << "./a.out -i configFile" << std::endl ; 
                exit(EXIT_FAILURE) ; 
            case '?' : 
                std::cout << "error parameter" << std::endl ; 
                exit(EXIT_FAILURE) ; 
        }
    }
    return configFile ; 
}

int main(int argc , char** argv ) {
    if(argc < 2 ) {
        std::cout << "paramter error" << std::endl ; 
    }
    std::string configFile = ParseParameter(argc , argv) ; 

    // 初始化服务对象
    RpcApplication& application = RpcApplication::GetInstance() ;  
    application.Init(configFile) ; 

    RpcProvider provider ; 
    provider.RegisterService(new UserService() ) ; 
    
    provider.Run() ;  // rpc服务跑起来
    
    return 0 ; 
}