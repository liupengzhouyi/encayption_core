//
// Created by 刘鹏 on 2021/6/8.
//
#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include "../core/encryption/Encryption.h"
#include "../core/unEncryption/UnEncryption.h"

#ifndef ENCAYPTION_CORE_READFILE_H
#define ENCAYPTION_CORE_READFILE_H


class ReadFile {
private:
    std::string path;

    std::vector<std::string> infomation;

public:
    ReadFile();

    const std::string &getPath() const;

    void setPath(const std::string &path);

    const std::vector<std::string> &getInfomation() const;

    void setInfomation(const std::vector<std::string> &infomation);

    void readFile();

    void unEncryptionFile();

    void writeFlie();
};


#endif //ENCAYPTION_CORE_READFILE_H

// ![Anurag's github stats](https://github-readme-stats.vercel.app/api?username=liupengzhouyi&show_icons=true)