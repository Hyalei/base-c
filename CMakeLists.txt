# 指定 CMake 的最低版本要求
# 这里使用 4.1（以你当前 CLion 自带的 cmake 为准）
cmake_minimum_required(VERSION 4.1)

# 定义项目名称 base_c，并指定使用 C 语言
project(base_c C)

# 设置 C 语言标准为 C99
set(CMAKE_C_STANDARD 99)

# ================================
# 设置可执行文件的输出目录
# ================================
# CMAKE_BINARY_DIR 表示 CMake 的构建目录
# 在 CLion 中通常是：
#   cmake-build-debug/
#
# 这里设置为：
#   cmake-build-debug/build/
#
# 所有 add_executable 生成的程序都会放到该目录下
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

# ================================
# 递归查找项目中的所有 .c 文件
# ================================
# GLOB_RECURSE 会从当前 CMakeLists.txt 所在目录开始，
# 递归扫描所有子目录，收集后缀为 .c 的源文件

file(GLOB_RECURSE ALL_C_FILES
        *.c
)

# ================================
# 为每一个 .c 文件生成一个可执行程序
# ================================
foreach (src ${ALL_C_FILES})

    # 获取源文件名（不包含路径和 .c 后缀）
    # 例如：
    #   linear-list/main.c → main
    get_filename_component(fname ${src} NAME_WE)

    # 获取源文件所在目录的完整路径
    # 例如：
    #   /Users/xxx/base-c/linear-list
    get_filename_component(dir ${src} DIRECTORY)

    # 获取目录名（只取最后一级目录名）
    # 例如：
    #   /Users/xxx/base-c/linear-list → linear-list
    get_filename_component(dir_name ${dir} NAME)

    # ================================
    # 生成唯一的 target 名称
    # ================================
    # 使用 “目录名_文件名” 的方式，
    # 可以避免不同目录下存在同名 .c 文件（如多个 main.c）
    # 造成 target 名称冲突
    #
    # 示例：
    #   linear-list/main.c → linear-list_main
    #   tree/main.c        → tree_main
    set(target_name ${dir_name}_${fname})

    # 定义一个可执行文件 target
    # 每一个 .c 文件都会被编译成一个独立的可执行程序
    add_executable(${target_name} ${src})

    # ================================
    # 设置最终生成的可执行文件名称
    # ================================
    # OUTPUT_NAME 决定的是 build 目录下生成的
    # 实际可执行文件名
    #
    # 这里保持与 target 名一致，方便识别
    set_target_properties(${target_name} PROPERTIES
            OUTPUT_NAME ${dir_name}_${fname}
    )

endforeach ()
