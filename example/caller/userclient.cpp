#include <iostream>

#include "rpcchannel.h"
#include "user.pb.h"
#include "rpccontroller.h"
#include "rpcconfig.h" 


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


// 客户在这里对服务器端的代码进行调用
int main(int argc , char** argv ) {

    if(argc < 2 ) {
        std::cout << "paramter error" << std::endl ; 
    }
    std::string configFile = ParseParameter(argc , argv) ; 
    RpcConfig::GetInstance().Init(configFile) ; 


    RpcChannel channel ;  // 表示一条通道，
    protocol::UserServiceRpc_Stub stub(&channel) ; // 根据这条通道创建一个新的服务

    // 构建请求消息
    protocol::LoginRequest request ; 
    request.set_id(9527) ; 
    request.set_password("123456") ; 

    // 定义接受消息的结构
    protocol::LoginResponse response ; 

    // 定义控制函数，方便后续的回调
    RpcController controller ; 

    stub.Login(&controller , &request , &response , nullptr ) ;   

    if(controller.Failed() ) {
        std::cout << "error occur : " ;   // 这里尝试能不能获取服务名和方法名
        std::cout << controller.ErrorText() << std::endl ;   
        exit(EXIT_FAILURE) ; 
    }
    // 没有退出，表明response中的值已经被设置好了。
    std::cout << "errcode: " << response.errinfo().errcode() <<std::endl ; 
    std::cout << "errmessage: " << response.errinfo().errmsg() << std::endl ; 
    std::cout << "result: " << response.result() << std::endl ;    


    return 0 ; 
}