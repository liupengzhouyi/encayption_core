//
// Created by 刘鹏 on 2021/6/8.
//

#include <fstream>
#include "ReadFile.h"
#include "../core/encryption/Encryption.h"

ReadFile::ReadFile() {
    this->infomation = std::vector<std::string>();
}

const std::string &ReadFile::getPath() const {
    return path;
}

void ReadFile::setPath(const std::string &path) {
    ReadFile::path = path;
}

const std::vector<std::string> &ReadFile::getInfomation() const {
    return infomation;
}

void ReadFile::setInfomation(const std::vector<std::string> &infomation) {
    ReadFile::infomation = infomation;
}

void ReadFile::readFile() {
    std::ifstream in(this->getPath());
    if (! in.is_open()) {
        std::cout << "Error opening file"; exit (1);
    }
    std::string line;
    while(getline(in, line))
    {
        Encryption encryption = Encryption(this->getPath(), line);
        this->infomation.push_back(encryption.getReturnInfo());
    }
}

void ReadFile::writeFlie() {
    std::ofstream out(this->getPath()+"temp");
    if (! out.is_open()) {
        std::cout << "Error opening file"; exit (1);
    }
    for (std::string line : this->getInfomation()) {
        out << line << std::endl;
    }
}


