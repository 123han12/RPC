#include "rpcapplication.h"
#include "rpcserverlog.h" 
#include <thread>
#include <functional>

RpcServerLog& RpcServerLog::getInstance() {
    static RpcServerLog Logger ; 
    return Logger ; 
}

void RpcServerLog::WriteLogToQqueue(std::string log , LogLevel loglevel ) {
    std::unique_lock<std::mutex> lock(mtx) ; 
    std::string time = GetDate() + "-" + GetTime() ;  
    /*
        日志格式
        year-month-day-hour-min-sec:[loglevel]:log
    */
    std::string logLevel = GetLogLevel(loglevel) ; 
    // 按照日志格式进行组装
    std::string Log = time + ":[" + logLevel + "]:" + log + '\n' ;   
    LogQueue.push(Log) ; 
    cond.notify_one() ; 

}

// 线程函数，从队列中获取消息写入到磁盘上去，当消息队列为空的时候会被阻塞。
void RpcServerLog::WriteToDisk() {

    std::string filepath ; 
    filepath = RpcApplication::GetInstance().GetConfigPath() ; 

    for(; ; ) {
        std::string message ; 
    {
        // 尝试获取锁
        std::unique_lock<std::mutex> lock(mtx) ; 
        while(LogQueue.empty() ) {  // 队列为空的话，我们就一直等待
            cond.wait(lock) ; 
        } 
        message = LogQueue.front() ; 
        LogQueue.pop() ; 
        cond.notify_all() ;
    }

        std::string date = GetDate() ; 
        std::string File = "log" ;  
        File = File + date + ".txt" ; 
        File = filepath + "/" + File ; 

        FILE* file = fopen(File.c_str() , "a+" ) ; 
        if(file == nullptr ) {
            std::cout << "Log system error" << std::endl ; 
            exit(EXIT_FAILURE) ; 
        }
        
        fputs(message.c_str() , file ) ;   // 磁盘I/O较为耗时
        
        fclose(file) ;   // 关闭文件
    } 

}

std::string RpcServerLog::GetDate() { // 获取当前日期
    auto now = std::chrono::system_clock::now() ; 
    std::time_t now_c = std::chrono::system_clock::to_time_t(now) ; 
    std::tm* time_tm = std::localtime(&now_c) ; 
    
    std::string year , month , day ; 
    year = std::to_string(1900 + time_tm->tm_year) ; 
    month = std::to_string(1 + time_tm->tm_mon) ; 
    day = std::to_string(1 + time_tm->tm_mday ) ;  
    std::string date ; 
    date = year + "-" + month + "-" + day ;    

    return date ; 
}
std::string RpcServerLog::GetTime() {
    auto now = std::chrono::system_clock::now() ; 
    std::time_t now_c = std::chrono::system_clock::to_time_t(now) ; 
    std::tm* time_tm = std::localtime(&now_c) ; 
    
    std::string hour , min , second ; 
    hour = std::to_string(time_tm->tm_hour) ; 
    min = std::to_string(time_tm->tm_min) ; 
    second = std::to_string(time_tm->tm_sec) ; 
    return hour + ":" + min + ":" + second ; 
}

std::string RpcServerLog::GetLogLevel(LogLevel level ) {
    std::string logLevel ; 
    switch(level) {
        case INFO : 
            logLevel = "INFO" ; 
            break ; 
        case NOTICE: 
            logLevel = "NOTICE" ; 
            break ; 
        case WARNING:
            logLevel = "WARNING" ; 
            break ; 
        case ERROR: 
            logLevel = "ERROR" ; 
            break ; 
        case CRITICAL: 
            logLevel = "CRITICAL" ; 
            break ; 
        case ALERT:
            logLevel = "ALERT" ; 
            break ; 
        case EMERGENCY : 
            logLevel = "EMERGENCY" ; 
            break ; 
    }
    return logLevel ; 
}

// 在构造函数内启动日志进程。
RpcServerLog::RpcServerLog() {

    // std::thread WriteThread(std::bind(&RpcServerLog::WriteToDisk , this)) ; 
    // WriteThread.detach() ; // 实现将线程和thread对象进行分离，不分离的话，在析构thread对象的时候会尝试合并线程 
}   

RpcServerLog::~RpcServerLog() {
    cond.notify_all() ; 
}