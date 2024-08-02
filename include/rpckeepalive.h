#pragma once 
#include <string> 
#include <vector>
#include <thread>
#include <sys/types.h>
#include <unistd.h>

#include "rpcredisutil.h"
class KeepAlive{
public :
    KeepAlive(std::string key , std::vector<std::string> service_container , int time = 10 ) ; 
    /// 周期性的修改keepalivekey这个键所对应的值
    void start() ; 
    // 每10秒修改一次 key 所对应的值。
    void setkeepalive()  ; 
    // 子进程调用，周期性的检查rpc服务是否正常运行。
    void getkeepalive() ; 

private:
    const std::string key_ ; 
    int sleeptime ;  // 以秒为单位
    std::vector<std::string> service_container_ ; 
} ;