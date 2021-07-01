#include <iostream>
#include "model/path/FliePath.h"
#include "model/readFile/ReadFile.h"

void show() {
    std::cout << "______加密与解密工具______" << std::endl;
    std::cout << "｜   模式1：加密单文件    ｜" << std::endl;
    std::cout << "｜   模式2：加密文件夹    ｜" << std::endl;
    std::cout << "｜   模式3：解密单文件    ｜" << std::endl;
    std::cout << "｜   模式4：解密文件夹    ｜" << std::endl;
    std::cout << "｜   模式5：下车不玩了    ｜" << std::endl;
    std::cout << "------------------------" << std::endl;
}
void paly() {
    int n = 2;
    while (n > 1) {
        show();
        int model = 0;
        std::cout << "请选择模式>>>";
        std::cin >> model;
        if (model == 5) {
            break;
        } else if (model == 2 || model == 4) {
            std::string dirPath = "";
            std::cout << "请输入文件夹路径>>>";
            std::cin >> dirPath;
            FliePath fliePath = FliePath();
            fliePath.setLogKey(true);
            fliePath.setDirPath(dirPath);
            fliePath.selectAllFiles(fliePath.getDirPath());
            for (std::string path : fliePath.getFilepath()) {
                std::cout << path << std::endl;
                ReadFile readFile = ReadFile();
                readFile.setPath(path);
                if (model == 2) readFile.readFile();
                else readFile.unEncryptionFile();
                readFile.writeFlie();
                break;
            }
        } else if (model == 1 || model == 3) {
            std::string filePath = "";
            std::cout << "请输入文件路径>>>";
            std::cin >> filePath;
            ReadFile readFile = ReadFile();
            readFile.setPath(filePath);
            if (model == 1) readFile.readFile();
            else readFile.unEncryptionFile();
            readFile.writeFlie();
        } else {
            std::cout << "只有5种模式，不要想屁吃！" << std::endl;
        }
    }
}

int main() {

    paly();

    return 0;
}
