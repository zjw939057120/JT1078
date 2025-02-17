#include "tcp_client.h"
#include "MessageCallback.h"
#include "ConnectionCallback.h"

ConnectionCallback *connectionCallback = new ConnectionCallback();

void SendMessage(const evpp::TCPConnPtr &conn) {
    if (conn->IsConnected()) {
        connectionCallback->Send(conn);
    }
}

int main(int argc, char *argv[]) {
    MessageCallback *messageCallback = new MessageCallback();

    std::string addr = "47.100.112.218:8808";

    if (argc == 2) {
        addr = argv[1];
    }

    evpp::EventLoop loop;
    evpp::TCPClient client(&loop, addr, "TCPPingPongClient");
    client.SetMessageCallback([&loop, &client, &messageCallback](const evpp::TCPConnPtr &conn,
                                                                 evpp::Buffer *msg) {
        //LOG_INFO << "Receive a message [" << msg->ToString() << "]";
        //client.Disconnect();

        messageCallback->Receive(msg);
        msg->Reset();
    });

    client.SetConnectionCallback([&loop](const evpp::TCPConnPtr &conn) {
        if (conn->IsConnected()) {
            LOG_INFO << "Connected to " << conn->remote_addr();
            //conn->Send("hello");

            evpp::Duration duration(3.0);
            loop.RunEvery(duration, [conn]() { SendMessage(conn); });
        } else {
            conn->loop()->Stop();
        }
    });
    client.Connect();
    loop.Run();
    return 0;
}
