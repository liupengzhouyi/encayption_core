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
    std::string s1 = this->info;
    std::string s2 = this->encryptionFactor;
    std::vector<int> myMap = {};
    for (auto item : s2) {
        myMap.push_back(int(item));
    }
    std::string newStr = "";
    int index = 0;
    for (auto item : s1) {
        char temp = (char)(int(item) + myMap[index]);
        newStr = newStr + temp;
        if (index <= myMap.size()) {
            index = index + 1;
        } else {
            index = 0;
        }
    }
    this->returnInfo = std::string(newStr);
}
