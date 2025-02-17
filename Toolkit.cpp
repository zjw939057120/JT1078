//
// Created by zjw93 on 2025/2/17.
//

#include <stdexcept>
#include "Toolkit.h"

void Toolkit::hexStringToByteArray(const std::string &hex, uint8_t *byteArray) {
    size_t len = hex.length();
    if (len % 2 != 0) {
        throw std::invalid_argument("Hex string length must be even");
    }

    for (size_t i = 0; i < len; i += 2) {
        std::string byteStr = hex.substr(i, 2);
        byteArray[i / 2] = static_cast<uint8_t>(std::stoi(byteStr, nullptr, 16));
    }
}
