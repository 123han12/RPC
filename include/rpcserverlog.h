#pragma once 
#include <mutex>
#include <condition_variable> 
#include <queue> 
#include <string> 
#include <chrono>
#include <ctime>
#include <iomanip> 
#include <iostream>
#include <stdio.h>
#include "rpcconfig.h"


// 服务器日志系统的产生的日志的几个级别
enum LogLevel{
    INFO = 1 ,     // 记录程序的正常运行
    NOTICE = 2 ,   // 记录一般性信息
    WARNING = 3 ,  // 表示有潜在性问题，程序仍然能够正常运行
    ERROR = 4 ,    // 程序遇到问题，仍然能够继续运行
    CRITICAL = 5 , // 遇到严重问题，可能会影响程序
    ALERT = 6 ,    // 通常是更加严重的问题，需要立即关注，如果不关注，可能会造成死机
    EMERGENCY = 7  // 最高级别的错误，需要立即停机或者采取紧急措施
} ; 



class RpcServerLog {
public:
    static RpcServerLog& getInstance() ;   // 在构造 RpcServerLog() 的时候，启动写日志的线程。
    void WriteLogToQqueue(std::string log , LogLevel loglevel ) ; 

    // 线程函数，从队列中获取消息写入到磁盘上去，当消息队列为空的时候会被阻塞。
    void WriteToDisk() ; 

private:
    RpcServerLog() ; 
    RpcServerLog(const RpcServerLog& ) = delete ; 
    RpcServerLog(RpcServerLog&&) = delete ;
    ~RpcServerLog() ; 
    std::string GetDate() ; 
    std::string GetTime() ; 
    std::string GetLogLevel(LogLevel level ) ; 


private:
    std::mutex mtx ; 
    std::condition_variable cond ; 
    std::queue<std::string> LogQueue ; 

} ; 


#define LOG_INFO(logformat , loglevel , ...)                      \
do                                                                \
{                                                                 \
    RpcServerLog& Logger = RpcServerLog::getInstance() ;          \
    char buffer[4096] = {0} ;                                     \
    snprintf(buffer , 4096 , logformat , ##__VA_ARGS__) ;         \
    Logger.WriteLogToQqueue(std::string(buffer) , loglevel ) ;    \
} while(0) ; 