#include <evpp/tcp_server.h>
#include <evpp/buffer.h>
#include <evpp/tcp_conn.h>

int main(int argc, char* argv[]) {
    std::string addr = "0.0.0.0:8808";
    int thread_num = 4;
    evpp::EventLoop loop;
    evpp::TCPServer server(&loop, addr, "TCPEchoServer", thread_num);
    server.SetMessageCallback([](const evpp::TCPConnPtr& conn,
                                 evpp::Buffer* msg) {
        LOG_TRACE << "SetMessageCallback " << msg->ToString() << msg->length();
        conn->Send(msg);
    });
    server.SetConnectionCallback([](const evpp::TCPConnPtr& conn) {
        if (conn->IsConnected()) {
            LOG_TRACE << "A new connection from " << conn->remote_addr();
        } else {
            LOG_TRACE << "Lost the connection from " << conn->remote_addr();
        }
    });
    server.Init();
    server.Start();
    loop.Run();
    return 0;
}
