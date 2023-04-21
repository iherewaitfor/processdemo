#Cmake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目信息
project (Demo)

# 查找目录下的所有源文件
# 并将名称保存到DIR_SRCS变量
aux_source_directory(. DIR_SRCS)

# 添加math子目录
add_subdirectory(subprocess)

# 指定生成目标
add_executable(Demo ${DIR_SRCS})

add_custom_command(TARGET Demo
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_BINARY_DIR}/subprocess/$<CONFIGURATION>/TestConsoleAppD.exe ${PROJECT_BINARY_DIR}/$<CONFIGURATION>
  )
  add_custom_command(TARGET Demo
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_BINARY_DIR}/subprocess/$<CONFIGURATION>/TestConsoleAppD.exe ${PROJECT_BINARY_DIR}
  )