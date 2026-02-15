#pragma once
#include<filesystem>
#include<iostream>

namespace fs = std::filesystem;
class FileExplorer {
public:
	bool directoryExists(fs::path dir);
	bool IsGameDirectory(fs::path dir);
    static FileExplorer& getInstance() {
        static FileExplorer instance;
        return instance;
    }

private:
    FileExplorer() {}
    FileExplorer(const FileExplorer&) = delete;
    FileExplorer& operator=(const FileExplorer&) = delete;
};

extern FileExplorer& fileExplorer;