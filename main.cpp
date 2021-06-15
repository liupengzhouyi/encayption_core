#include <iostream>
#include "model/path/FliePath.h"
#include "model/readFile/ReadFile.h"

int main() {

    std::string dirPath = "/Users/liupeng/CLionProjects/encryption-core";
    FliePath fliePath = FliePath();
    fliePath.setLogKey(false);
    fliePath.setDirPath(dirPath);
    fliePath.selectAllFiles(fliePath.getDirPath());

    for (std::string path : fliePath.getFilepath()) {
        std::cout << path << std::endl;
        ReadFile readFile = ReadFile();
        readFile.setPath(path);
        readFile.readFile();

        readFile.writeFlie();
        break;
    }

    return 0;
}
