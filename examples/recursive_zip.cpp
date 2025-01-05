#include "../zip_file.hpp"
#include <filesystem>
#include <algorithm>

// 将路径中的 '\' 替换为 '/' 并且去除路径开始的 str 字符
std::string normalize_path(const std::string& path, const std::string& str) {
    std::string normalized = path;
    std::replace(normalized.begin(), normalized.end(), '\\', '/');
    
    // 去除路径开始的 str 字符
    if (normalized.find(str) == 0) {
        normalized = normalized.substr(str.length());
    }
    
    return normalized;
}

int main() {
    miniz_cpp::zip_file file;
    const std::string base_path = "./test/";

    for (const auto& entry : std::filesystem::recursive_directory_iterator{ base_path }) {
        auto path = entry.path().string();
        auto zip_path = normalize_path(path, base_path);

        if (entry.is_directory()) {
            // 如果是目录，添加空目录条目
            file.writestr(zip_path + "/", "");
        } else if (entry.is_regular_file()) {
            // 如果是文件，添加文件内容 第一个参数是文件路径，第二个参数是在 zip 中的路径
            file.write(path, zip_path);
        }

        std::cout << "path: " << path << " zip_path: " << zip_path << "\n";
    }
    file.save("recursive_zip.zip");
}