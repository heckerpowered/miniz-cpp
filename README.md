# miniz-cpp

## 使用方式

直接将 `zip_file.hpp` 头文件拷贝到项目中即可。经过测试，在 `Ubuntu 22.04 x86_64` 上使用 gcc 12 编译器没有问题。

## 使用示例

```cpp
#include <iostream>
#include "zip_file.hpp"

int main(){
    miniz_cpp::zip_file zip;

    // 将 test.txt 写入压缩包的根目录
    zip.write("./test.txt", "test.txt");

    // 将 1MB_file.dat 写入压缩包的根目录
    zip.write("./1MB_file.dat", "1MB_file.dat");

    zip.save("miniz_cpp.zip");
    
    std::clog << "Saved to test.zip" << std::endl;
}
```
