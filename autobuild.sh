
#!/bin/bash

set -e

#如果没有build目录，创建该目录
if [ ! -d `pwd`/build ]; then
    mkdir `pwd`/build
fi

rm -rf `pwd`/build/*  #删除目录下内容

cd `pwd`/build &&
    cmake .. &&
    make #编译

