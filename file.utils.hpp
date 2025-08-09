#ifndef FILE_UTILS_HPP
#define FILE_UTILS_HPP

#include <filesystem>
#include <vector>
#include <string>

namespace fs = std::filesystem;

std::vector<std::string> glob(const std::string& pattern) {
    std::vector<std::string> result;
    std::string path = fs::path(pattern).parent_path().string();
    std::string ext = fs::path(pattern).extension().string();

    for (auto &p : fs::directory_iterator(path)) {
        if (p.path().extension() == ext) {
            result.push_back(p.path().string());
        }
    }
    return result;
}

#endif
