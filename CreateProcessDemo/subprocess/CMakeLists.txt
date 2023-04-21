# 查找目录下的所有源文件
# 并将名称保存到DIR_LIB_SRCS变量
aux_source_directory(. DIR_LIB_SRCS)
set ( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE" ) 

# 指定生成MathFunctions链接库
add_executable(TestConsoleAppD ${DIR_LIB_SRCS})