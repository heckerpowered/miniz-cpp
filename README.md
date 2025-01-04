miniz-cpp
=========

使用示例：

```cpp
#include <iostream>
#include "zip_file.hpp"

int main(){
    miniz_cpp::zip_file zip;

    // 将 test.txt 写入压缩包的根目录
    zip.write("./test.txt", "test.txt");

    // 将 1MB_file.dat 写入压缩包的根目录
    zip.write("./1MB_file.dat", "1MB_file.dat");

    // 保存到 test.zip
    zip.save("miniz_cpp.zip");
    
    std::clog << "Saved to test.zip" << std::endl;
}
```
