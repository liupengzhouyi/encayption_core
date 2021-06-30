//
// Created by 刘鹏 on 2021/6/9.
//

#ifndef ENCAYPTION_CORE_ENCRYPTION_H
#define ENCAYPTION_CORE_ENCRYPTION_H

#include <vector>
#include <string>

class Encryption {

private:

    std::string encryptionFactor;

    std::string info;

    std::string returnInfo;


public:

    Encryption(const std::string &encryptionFactor, const std::string &info);

    const std::string &getEncryptionFactor() const;

    void setEncryptionFactor(const std::string &encryptionFactor);

    const std::string &getInfo() const;

    void setInfo(const std::string &info);

    const std::string &getReturnInfo() const;

    void setReturnInfo(const std::string &returnInfo);

    void encryption_for_info();
};


#endif //ENCAYPTION_CORE_ENCRYPTION_H
