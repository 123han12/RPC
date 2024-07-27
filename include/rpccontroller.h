#pragma once 
#include <google/protobuf/service.h>
#include <string> 

class RpcController : public google::protobuf::RpcController 
{
public:
    RpcController() ; 
    void Reset() ; 
    bool Failed() const  ; 
    std::string ErrorText() const  ; 
    void StartCancel() ;     
    void SetFailed(const std::string& reason ) ; 
    bool IsCanceled() const ; 
    void NotifyOnCancel(google::protobuf::Closure* callback) ; 

private:
    std::string errorText ; 
    bool isFailed ; 

}  ;