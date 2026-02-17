#include "FileExplorer.h"

bool FileExplorer::directoryExists(fs::path dir) {
    if (fs::exists(dir) && fs::is_directory(dir)) {
        return true;
    }
    else {
        return false;
    }
}

bool FileExplorer::IsGameDirectory(fs::path dir) {
    if (!(directoryExists(dir) && directoryExists(dir/ "characters") && fs::exists(dir/"metadata"))) {
        return false;
    }
    //std::cout << directoryExists(dir);
    return true;
}
FileExplorer& fileExplorer = FileExplorer::getInstance();
