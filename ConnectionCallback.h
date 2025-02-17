//
// Created by zjw93 on 2025/2/17.
//

#ifndef TCP_CLIENT_CONNECTIONCALLBACK_H
#define TCP_CLIENT_CONNECTIONCALLBACK_H


#include <memory>
#include <evpp/tcp_conn.h>

class ConnectionCallback {

public:
    void Send(const std::shared_ptr<evpp::TCPConn> &conn);
};


#endif //TCP_CLIENT_CONNECTIONCALLBACK_H
