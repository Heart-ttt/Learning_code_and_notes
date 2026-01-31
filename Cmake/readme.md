## CMake学习笔记 [视频链接](https://www.bilibili.com/video/BV14s4y1g7Zj?spm_id_from=333.788.player.switch&vd_source=71d8419b0e68a3c6bdaead698608818d&p=5) [博主网站](https://subingwen.cn/cmake/CMake-primer)

## CMake编译流程

在[文件夹目录](./CMakelists_Structure/)下使用[tree命令](./tree.md)查看文件夹结构

[例程](./CMakelists_Structure/CMakeLists.txt)

### CMakeLists.txt 内容格式
```cmake
cmake_minimum_required(VERSION 3.31)
project(demo1)
file(GLOB src ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
include_directories(${PROJECT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ../bin)
add_executable(main ${src})
```

### 注释

```cmake
行注释: # 这是一个 CMakeLists.txt 文件

块注释: #[[ 这是一个 CMakeLists.txt 文件
这是一个 CMakeLists.txt 文件
这是一个 CMakeLists.txt 文件]]
```

### 常见函数

```cmake
# SET:
# [] 中的参数为可选项, 如不需要可以不写
SET(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE]])
VAR为变量名 VALUE为变量值

# 方式1: 各个源文件之间使用空格间隔
set(SRC_LIST add.c  div.c   main.c  mult.c  sub.c)

# 方式2: 各个源文件之间使用分号 ; 间隔
set(SRC_LIST add.c;div.c;main.c;mult.c;sub.c)
```

```cmake
# 添加可执行文件
# 变量使用: ${}
add_executable(app  ${SRC_LIST})
```

```cmake
# 设置可执行文件生成路径
set(EXECUTABLE_OUTPUT_PATH ../bin)
```

```cmake
# 查找文件
file(GLOB/GLOB_RECURSE SRC *.c *.cpp)
# 使用GLOB_RECURSE参数递归子目录
# SRC为变量名
# 可以收集多个类型的文件

# 扫描当前目录下的所有文件,(已弃用)
# 仅支持C/C++文件,不递归子目录
aux_source_directory(<dir> <variable>)
# <dir>: 要扫描的目录 
# <variable>: 输出变量名
```

```cmake
# 包含头文件夹
include_directories(<dir>)
# <dir>: 头文件夹目录 
```

### 常见宏定义
| CMake 内置变量 | 说明 | 示例值 |
|----------------|------|--------|
| `CMAKE_BUILD_TYPE` | 当前构建类型（需用户指定或默认） | `"Debug"`, `"Release"`, `"RelWithDebInfo"`, `"MinSizeRel"` |
| `CMAKE_CURRENT_BINARY_DIR` | 当前 `CMakeLists.txt` 对应的构建输出目录 | `/home/user/build/src/utils` |
| `PROJECT_BINARY_DIR` | 当前项目的构建根目录 | 通常等于 `CMAKE_BINARY_DIR`（在顶层时） |
| `CMAKE_BINARY_DIR` | 项目根构建目录（即 `cmake -B <dir>` 指定的目录） | `/home/user/build` |
| `LIBRARY_OUTPUT_PATH`<br>`EXECUTABLE_OUTPUT_PATH(对动态库可用)` | 库文件和可执行文件输出目录 | `/home/user/lib`<br>`/home/user/bin`|
| `CMAKE_SYSTEM_NAME` | 目标操作系统名称 | `"Darwin"` (macOS), `"Linux"`, `"Windows"`, `"Android"` |
| `CMAKE_HOST_SYSTEM_NAME` | 构建主机的操作系统名称 | 同上，表示运行 CMake 的机器系统 |
| `CMAKE_SIZEOF_VOID_P` | `void*` 指针的字节大小（反映架构位数） | `8`（64 位）, `4`（32 位） |
| `PROJECT_NAME` | 当前 `project()` 命令指定的项目名称 | `"MyApp"` |
| `CMAKE_CURRENT_LIST_DIR` | 当前正在解析的 `CMakeLists.txt` 或脚本所在目录 | `/home/user/project/cmake/modules` |
| `CMAKE_PROJECT_NAME` | 最外层项目的名称（顶层 `project()`） | `"TopLevelProject"` |


## 动态库与静态库

[例程](./Create_Library/CMakeLists.txt)

### 区别与特性
| 特性 | 静态库（Static Library） | 动态库（Shared Library） |
|------|--------------------------|---------------------------|
| **CMake 命令** | `add_library(name STATIC src.c)` | `add_library(name SHARED src.c)` |
| **输出文件（macOS）** | `libname.a` | `libname.dylib` |
| **链接时机** | 编译时嵌入可执行文件 | 运行时加载 |
| **可执行文件大小** | 较大（包含库代码） | 较小（仅含引用） |
| **运行时依赖** | ❌ 无外部依赖，独立运行 | ✅ 需要 `.dylib` 文件在运行路径中 |
| **更新库的影响** | 必须重新编译整个程序 | 只需替换 `.dylib` 文件 |
| **内存占用（多程序）** | 每个程序独占一份副本 | 多个程序共享同一份内存 |
| **分发复杂度** | 简单（单个可执行文件） | 较高（需打包库文件） |
| **调试便利性** | 库修改后需全量重编 | 库修改后只需替换 `.dylib` |
| **典型使用场景** | <ul><li>发布独立软件</li><li>嵌入式系统</li><li>安全敏感环境</li></ul> | <ul><li>多个程序共享功能</li><li>插件系统</li><li>开发阶段快速迭代</li></ul> |
| **CMake 运行时路径设置** | 不需要 | 推荐：`set(CMAKE_BUILD_RPATH "$ORIGIN")` |
| **查看依赖命令（macOS）** | `ar -t libname.a` | `otool -L ./app` 或 `otool -L libname.dylib` |

### 库制作的cmake指令

```cmake
# 库生成
add_library(name SHARED src.c)
add_library(name STATIC src.c)
# 指定库的输出路径
set(LIBRARY_OUTPUT_PATH ../lib)
```

### 链接库
目录如下
```shell
$ tree 
.
├── build
├── CMakeLists.txt
├── include
│   └── head.h
├── lib
│   └── libstatic.a     # 制作出的静态库的名字
│   └── libshared.dylib
└── src
    └── main.cpp

4 directories, 4 files
```

链接静态库的命令
```cmake
# 包含静态库的路径
link_directories(${PROJECT_SOURCE_DIR}/lib)

# 链接静态库
link_libraries(<static lib> [<static lib>...])
<static lib>: 要链接静态库的名字(可以是全名，也可以是掐头去尾后的名字)
[<static lib>]: 要链接其他静态库的名字
```