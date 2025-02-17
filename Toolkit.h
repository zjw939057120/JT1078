//
// Created by zjw93 on 2025/2/17.
//

#ifndef TCP_CLIENT_TOOLKIT_H
#define TCP_CLIENT_TOOLKIT_H


#include <string>

class Toolkit {

public:
    static void hexStringToByteArray(const std::string &hex, uint8_t *byteArray);
};


#endif //TCP_CLIENT_TOOLKIT_H
