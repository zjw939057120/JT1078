//
// Created by zjw93 on 2025/2/17.
//

#include "MessageCallback.h"

void MessageCallback::Receive(evpp::Buffer *msg) {
//    LOG_TRACE << "Receive a message data " << msg->data();
    LOG_TRACE << "Receive a message length " << msg->length();

    const char *buf = msg->data();
    for (int i = 0; i < msg->length(); ++i) {
        printf("%x,", buf[i]);
    }
    printf("\r\n");
}
