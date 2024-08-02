#include "rpckeepalive.h"



KeepAlive::KeepAlive(std::string key , std::vector<std::string> service_container , int time ) 
: key_(key) , sleeptime(time) , service_container_(service_container)
{}
/// 周期性的修改keepalivekey这个键所对应的值
void KeepAlive::start() {

    // 开启线程
    std::thread client(std::bind(&KeepAlive::setkeepalive , this) ) ; 
    client.detach() ; // 分离线程为守护线程。

    // fork() 一个子进程
    pid_t pid = fork() ; 
    if(pid == 0 ) {  // 表明这个是子进程，开始检测
        getkeepalive() ; 
    }
}

// 每10秒修改一次 key 所对应的值。
void KeepAlive::setkeepalive() {
    Redis redis ; 
    redis.Connect() ;  // 连接redis

    // 先清空key
    redis.RedisCommand("set" , key_ , "0" ) ; 
    int count = 1 ; 
    while(1) {  // 这个线程死循环对redis中的key_ 所对应的值进行修改
        sleep(sleeptime) ; 
        redis.RedisCommand("set" , key_ , std::to_string(count) ) ; 
        count ++ ; 
        if(count >= 100 ) count = 0 ; 
    }
}

// 子进程调用，周期性的检查rpc服务是否正常运行。
void KeepAlive::getkeepalive() {
    Redis redis ; 
    redis.Connect() ;  // 子进程连接redis 
    int count = 0 ;  // 计数器，当计数器中的值 >= 4 的时候，说明rpc节点服务已经掉线了。 
    
    std::string prevalue ; 
    prevalue = redis.RedisCommand( "get" , key_ , "" ) ; 
    std::string value ; 
    while(1) {
        sleep(sleeptime) ; 
        value = redis.RedisCommand("get" , key_ , "") ; 
        if(value == prevalue ) {
            count ++ ; 
            if(count >= 4 ) {
                // 销毁该rpc节点在redis上注册的服务。
                for(auto& servicename : service_container_ ) {
                    redis.RedisCommand("del" , servicename , "" ) ; 
                }
                exit(0) ; // 这个子进程直接退出了。
            }
        }else {
            count = 0 ; 
            prevalue = value ; 
        }
    }
}

