//
// Created by 刘鹏 on 2021/6/8.
//

#include <iostream>
#include "fstream"
#include <dirent.h>
#include <stdio.h>
#include <string>
#include <vector>

#ifndef ENCAYPTION_CORE_FLIEPATH_H
#define ENCAYPTION_CORE_FLIEPATH_H


class FliePath {

public:

    FliePath();

    FliePath(const std::string &dirPath);

    const std::string &getDirPath() const;

    void setDirPath(const std::string &dirPath);

    const std::vector<std::string> &getFilepath() const;

    void setFilepath(const std::vector<std::string> &filepath);

    void selectAllFiles(const std::string &path);

    void sayLog(const std::string &log);

    void addPath(const std::string &path);

    bool isLogKey() const;

    void setLogKey(bool logKey);

private:

    bool logKey = true;

    std::string dirPath;

    std::vector<std::string> filepath;

};


#endif //ENCAYPTION_CORE_FLIEPATH_H
