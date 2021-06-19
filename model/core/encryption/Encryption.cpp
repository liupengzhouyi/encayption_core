//
// Created by 刘鹏 on 2021/6/9.
//

#include "Encryption.h"

Encryption::Encryption(const std::string &encryptionFactor, const std::string &info) : encryptionFactor(
        encryptionFactor), info(info) {
    this->encryption_for_info();
}

const std::string &Encryption::getEncryptionFactor() const {
    return encryptionFactor;
}

void Encryption::setEncryptionFactor(const std::string &encryptionFactor) {
    Encryption::encryptionFactor = encryptionFactor;
}

const std::string &Encryption::getInfo() const {
    return info;
}

void Encryption::setInfo(const std::string &info) {
    Encryption::info = info;
}

const std::string &Encryption::getReturnInfo() const {
    return returnInfo;
}

void Encryption::setReturnInfo(const std::string &returnInfo) {
    Encryption::returnInfo = returnInfo;
}

void Encryption::encryption_for_info() {

    this->returnInfo = std::string(this->info + "temp.");
}
