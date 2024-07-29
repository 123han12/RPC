#include "rpczookeeperutil.h"
#include "rpcapplication.h"
#include "rpcserverlog.h" 

#include <semaphore>

// 当服务端向客户端发送成功的消息的时候，这个函数会被回调
void watcher(zhandle_t *zh, int type, int state, const char *path,void *watcherCtx) {
    if(type == ZOO_SESSION_EVENT ) {
        if(state == ZOO_CONNECTED_STATE ) {
            sem_t* sem = (sem_t*)zoo_get_context(zh) ; 
            sem_post(sem) ; 
        }
    }
}

ZkClient::ZkClient(): m_zhandle(nullptr) {

} 
ZkClient::~ZkClient(){
    if(m_zhandle != nullptr ) {
        zookeeper_close(m_zhandle) ; 
    }
} 

// 客户端异步连接 zkServer服务器  
void ZkClient::Start() {
    std::pair<std::string , int> info = RpcApplication::GetInstance().GetZookeeperInfo() ; 
    std::string host = info.first , port = std::to_string(info.second) ; 
    std::string connstr = host + ":" + port ; 

    /*
    如果链接的是zookeeper_mt 多线程版本的库
    在调用zookeeper_init的时候是异步的,有多个线程:
    API调用线程，就是当前线程
    在函数内部通过调用pthread_create API 接口创建另外两个线程: 网络I/O线程(使用poll) , watcher 回调线程 
    
    */

    m_zhandle = zookeeper_init(connstr.c_str() , watcher , 30000 , nullptr , nullptr , 0) ; 
    if(m_zhandle == nullptr ) {
        LOG_INFO("connect to zookeeper server:%s failed..." , ERROR , connstr.c_str() ) ; 
        exit(EXIT_FAILURE) ; 
    }
    sem_t sem ;   // 用于判断是否连接成功
    sem_init(&sem , 0 , 0 ) ; 
    zoo_set_context(m_zhandle , &sem) ;  

    sem_wait(&sem) ; // 一直阻塞，直到watcher 成功被调用，表示连接成功

    LOG_INFO("zookeeper_init sucess!" , INFO) ;  

} 


// 创建节点并给节点赋值
void ZkClient::Create(const char* path , const char * data , int datalen , int state  ) {
    char path_buffer[1024] ; 
    int bufferlen = sizeof(path_buffer) ; 
    int flag ; 

    flag = zoo_exists(m_zhandle , path , 0 , nullptr ) ;  // 判断当前节点是否存在

    if(ZNONODE == flag ) {
        flag = zoo_create(m_zhandle , path , data , datalen , &ZOO_OPEN_ACL_UNSAFE , state , path_buffer , bufferlen ) ; 
        if(flag == ZOK) {
            LOG_INFO("znode create sucess.... path:%s" , INFO , path) ; 
        }else {
            LOG_INFO("flag: %d znode create error.... path: %s" , ERROR , flag , path ) ; 
            exit(EXIT_FAILURE) ; 
        }
    }

}

// 获取节点上的数据
std::string ZkClient::GetData(const char* path ) {
    char buffer[1024] ; 
    int bufferlen = sizeof(buffer) ; 
    int flag = zoo_get(m_zhandle , path , 0 , buffer , &bufferlen , nullptr ) ; 
    if(flag != ZOK) {
        LOG_INFO("get znode error.... path: %s" , ERROR , path ) ; 
        exit(EXIT_FAILURE) ; 
    }

    return buffer ; 
}
