#include "rpccontroller.h"

void RpcController::Reset() {
    errorText = "" ; 
    isFailed = false ; 
}
bool RpcController::Failed() const  {
    return isFailed ; 
}
std::string RpcController::ErrorText() const  {
    return errorText ; 
}
void RpcController::StartCancel() {} 
    
void RpcController::SetFailed(const std::string& reason ) {
    isFailed = true ; 
    errorText = reason ; 
}

bool RpcController::IsCanceled() const {
    return true ; 
} 
void RpcController::NotifyOnCancel(google::protobuf::Closure* callback) {
    return ; 
} 

RpcController::RpcController() {
    isFailed = false ; 
    errorText = "" ; 
}