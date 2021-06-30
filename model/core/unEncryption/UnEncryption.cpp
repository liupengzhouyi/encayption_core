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
    std::string newStr = this->info;
    std::string s2 = this->encryptionFactor;
    std::vector<int> myMap = {};
    for (auto item : s2) {
        myMap.push_back(int(item));
    }
    int index = 0;
    std::string oldStr = "";
    for (auto item : newStr) {
        char temp = (char)(int(item) - myMap[index]);
        oldStr = oldStr + temp;
        if (index <= myMap.size()) {
            index = index + 1;
        } else {
            index = 0;
        }
    }
    this->returnInfo = std::string(oldStr);
}
