#pragma once 
#include <google/protobuf/service.h>


// 提供一个和服务器交流的通道
class RpcChannel : public google::protobuf::RpcChannel {
public:
    void CallMethod(const google::protobuf::MethodDescriptor* method , google::protobuf::RpcController* controller
    , const google::protobuf::Message* request , google::protobuf::Message* response , google::protobuf::Closure* done 
    ) override ; 

} ; 