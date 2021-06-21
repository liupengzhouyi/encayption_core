cmake_minimum_required(VERSION 3.19)
project(encayption_core)

set(CMAKE_CXX_STANDARD 20)

link_directories(/Users/liupeng/CLionProjects/encayption_core/lib)


add_executable(encayption_core
        main.cpp
        model/path/FliePath.cpp
        model/path/FliePath.h
        model/readFile/ReadFile.cpp model/readFile/ReadFile.h
        test.cpp model/core/unEncryption/UnEncryption.cpp model/core/unEncryption/UnEncryption.h
        model/core/encryption/Encryption.cpp model/core/encryption/Encryption.h
        model/allEnv/allEnv.h
        )


add_subdirectory(lib)


