//
// Created by zjw93 on 2025/2/17.
//

#include "tcp_client_main.h"
#include "tcp_client.h"

int main(int argc, char *argv[]) {
    TCP_Client *m_TCP_Client = new TCP_Client("47.100.112.218:8808");
    m_TCP_Client->Run();
    return 0;
}