#include "rpcchannel.h"
#include "protocol.pb.h"
#include "rpcconfig.h"

#include <sys/types.h>
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <unistd.h>

#include <string>

void RpcChannel::CallMethod(const google::protobuf::MethodDescriptor* method , 
        google::protobuf::RpcController* controller ,
        const google::protobuf::Message* request , 
        google::protobuf::Message* response , 
        google::protobuf::Closure* done ) 
{   
    // 组装消息体并且序列化
    std::string message ; 
    if(!request->SerializeToString(&message) ) {
        std::cout << "serialize request failed!" << std::endl ; 
        exit(EXIT_FAILURE) ; 
    } 

    RpcProtocol::RequestHeader header ; 
    
    std::string servicename = method->service()->name() ; // 获得服务的名称
    std::string methodname = method->name() ; // 获得方法的名称

    header.set_servicename(servicename.c_str() ) ; 
    header.set_methodname(methodname.c_str() ) ; 
    header.set_argsize(message.size() ) ; 

    std::string headerstr ; 
    if(!header.SerializeToString(&headerstr) ) {
        std::cout << "serialize header failed" << std::endl ; 
        exit(EXIT_FAILURE) ; 
    }
    int headersize = headerstr.size() ;  

    // 插入header
    message.insert(0 , headerstr.c_str() ) ; 
    // 插入headersize
    message.insert(0 , (const char*)&headersize , 4 ) ; 



    // 建立连接 发送已经序列化好的message 
    // 使用linux下的原生态接口进行编程
    //1.创建socket
    int client_sock=socket(AF_INET,SOCK_STREAM,0);
    if (client_sock==-1)
    {
        controller->SetFailed("Faild to create socket") ; 
        return ; 
    }
 
    std::pair<std::string , int> rpcServerInfo = RpcConfig::GetInstance().GetRpcServerInfo() ; 
    std::string ip = rpcServerInfo.first ; 
    int port = rpcServerInfo.second ; 


    //2.连接服务器
    struct sockaddr_in server_addr;
    server_addr.sin_family=AF_INET;
    inet_pton(AF_INET, ip.c_str() , &server_addr.sin_addr.s_addr);
    server_addr.sin_port=htons(port); 

    if(connect(client_sock,(struct sockaddr*)&server_addr,sizeof(server_addr))==-1){
        controller->SetFailed("Faild to connect socket") ; 
        return ;
    }
 
    std::cout<<"Connected to server: " << ip << " : " << port << std::endl ; 
 
    //3.数据交互 
    if(send(client_sock,message.c_str(),message.length() , 0 )==-1){
        controller->SetFailed("Faild to write ") ; 
        return ; 
    }
 
    //接受消息
 
    char buffer[4096] ; 
    if(recv(client_sock,buffer,sizeof(buffer) , 0 )==-1) { 
        controller->SetFailed("Faild to read") ;
        return ;
    }

    // 反序列化
    response->ParseFromArray(buffer , strlen(buffer) ) ; 

    close(client_sock) ; 
}