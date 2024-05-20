#定义一个SRC_LIST变量 包含了该目录下所有的源文件 当前目录下的
aux_source_directory(. SRC_LIST)

#指定生成可执行文件
add_executable(ChatClient ${SRC_LIST})

#指定可执行文件链接时需要依赖的库文件 基于控制台应用程序
target_link_libraries(ChatClient pthread)