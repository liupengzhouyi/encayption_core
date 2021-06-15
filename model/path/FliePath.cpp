//
// Created by 刘鹏 on 2021/6/8.
//

#include "FliePath.h"
unsigned char isFile =0x8;

FliePath::FliePath() {
    this->filepath = std::vector<std::string>();
}

FliePath::FliePath(const std::string &dirPath) : dirPath(dirPath) {}

const std::string &FliePath::getDirPath() const {
    return dirPath;
}

void FliePath::setDirPath(const std::string &dirPath) {
    FliePath::dirPath = dirPath;
}

const std::vector<std::string> &FliePath::getFilepath() const {
    return filepath;
}

void FliePath::setFilepath(const std::vector<std::string> &filepath) {
    FliePath::filepath = filepath;
}

void FliePath::selectAllFiles(const std::string &path) {
    DIR * dir;
    struct dirent * ptr;
    this->sayLog("open dir " + path + "...");
    dir = opendir((char *)path.c_str());
    while((ptr = readdir(dir)) != NULL) //循环读取目录数据
    {
        if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
            continue;
        else if(ptr->d_type == 8) {
            this->sayLog("find file " + std::string(ptr->d_name));
            std::string tempPath = path + "/" + std::string(ptr->d_name);
            this->sayLog("add file path[" + tempPath + "] in pathSet!");
            this->addPath(tempPath);
        }
        else if(ptr->d_type == 10) {
            printf("link_flie_name : %s\n", ptr->d_name); //输出文件名
        }
        else if(ptr->d_type == 4) {
            if (std::string(ptr->d_name) == "cmake-build-debug") {
                ;
            } else {
                std::string newPath = path + "/" + std::string(ptr->d_name);
                this->sayLog("find dir " + newPath + "...");
                this->sayLog("into dir " + newPath + "...");
                this->selectAllFiles(newPath);
            }
        }
    }
    closedir(dir);//关闭目录指针
    this->sayLog("clear dir over!");
}

void FliePath::sayLog(const std::string &log) {
    if (this->logKey) {
        std::cout << log << std::endl;
    }
}

void FliePath::addPath(const std::string &path) {
    this->filepath.push_back(path);
}

bool FliePath::isLogKey() const {
    return logKey;
}

void FliePath::setLogKey(bool logKey) {
    FliePath::logKey = logKey;
}






