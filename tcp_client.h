//
// Created by zjw93 on 2025/2/17.
//

#ifndef TCP_CLIENT_TOOLKIT_H
#define TCP_CLIENT_TOOLKIT_H


#include <evpp/tcp_client.h>
#include <evpp/buffer.h>
#include <evpp/tcp_conn.h>
#include "MessageCallback.h"
#include "ConnectionCallback.h"

class TCP_Client {
public:
    TCP_Client(std::string addr);

    void SendMessage(const evpp::TCPConnPtr &conn);

    void Run();

public:
    std::string addr;
    evpp::TCPConnPtr m_TCPConnPtr;
    MessageCallback *m_MessageCallback;
    ConnectionCallback *M_ConnectionCallback;
};


#endif //TCP_CLIENT_TOOLKIT_H
