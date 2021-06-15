//
// Created by 刘鹏 on 2021/6/9.
//

#include "UnEncryption.h"

UnEncryption::UnEncryption(const std::string &encryptionFactor, const std::string &info) : encryptionFactor(
        encryptionFactor), info(info) {
    this->unEncryption_for_info();
}

const std::string &UnEncryption::getEncryptionFactor() const {
    return encryptionFactor;
}

void UnEncryption::setEncryptionFactor(const std::string &encryptionFactor) {
    UnEncryption::encryptionFactor = encryptionFactor;
}

const std::string &UnEncryption::getInfo() const {
    return info;
}

void UnEncryption::setInfo(const std::string &info) {
    UnEncryption::info = info;
}

const std::string &UnEncryption::getReturnInfo() const {
    return returnInfo;
}

void UnEncryption::setReturnInfo(const std::string &returnInfo) {
    UnEncryption::returnInfo = returnInfo;
}

void UnEncryption::unEncryption_for_info() {
    this->returnInfo = std::string(this->info);
}
