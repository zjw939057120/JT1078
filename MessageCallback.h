//
// Created by zjw93 on 2025/2/17.
//

#ifndef TCP_CLIENT_MESSAGECALLBACK_H
#define TCP_CLIENT_MESSAGECALLBACK_H


#include <evpp/buffer.h>

class MessageCallback {

public:
    void Receive(evpp::Buffer *msg);
};


#endif //TCP_CLIENT_MESSAGECALLBACK_H
