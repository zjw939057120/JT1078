#include "tcp_client.h"
#include "MessageCallback.h"
#include "ConnectionCallback.h"

evpp::TCPConnPtr m_TCPConnPtr;
MessageCallback *g_messageCallback;
ConnectionCallback *g_connectionCallback;


void TCP_Client::SendMessage(const evpp::TCPConnPtr &conn) {
    if (conn->IsConnected()) {
        g_connectionCallback->Send(conn);
    }
}

TCP_Client::TCP_Client(std::string addr) {
    this->addr = addr;
    M_ConnectionCallback = new ConnectionCallback();
    m_MessageCallback = new MessageCallback();

}

void TCP_Client::Run() {
    evpp::EventLoop loop;
    evpp::TCPClient client(&loop, addr, "TCPPingPongClient");
    client.SetMessageCallback([&loop, &client, this](const evpp::TCPConnPtr &conn,
                                                     evpp::Buffer *msg) {
        //LOG_INFO << "Receive a message [" << msg->ToString() << "]";
        //client.Disconnect();

        m_MessageCallback->Receive(msg);
        msg->Reset();
    });

    client.SetConnectionCallback([&loop, this](const evpp::TCPConnPtr &conn) {
        if (conn->IsConnected()) {
            LOG_INFO << "Connected to " << conn->remote_addr();
            //conn->Send("hello");
            memcpy(&m_TCPConnPtr, &conn, sizeof(evpp::TCPConnPtr));
            evpp::Duration duration(3.0);
            loop.RunEvery(duration, [conn, this]() { SendMessage(conn); });
        } else {
            conn->loop()->Stop();
        }
    });
    client.Connect();
    loop.Run();
}
