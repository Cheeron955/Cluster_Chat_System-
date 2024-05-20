This project uses C++ cluster chat server developed based on muduo in Linux environment. 
Used redis, json, mysql, nginx, etc. 
Realize new user registration, user login, add friends, add groups, friend communication, group chat, keep offline messages and other functions.

Compile step:

One-click compilation ./autobuild.sh

or

cd build
rm -rf *
cmake ..
make

This project needs to configure nginx load balancing, install redis, json, nginx, mysql, etc. 
The related installation steps and configuration are continuously updated in the personal blog https://blog.csdn.net/m0_73537205?type=blog.

Catalog introduction:
bin/: directory of executable files;
build/: a temporary file generated at compile time;
include/: header file;
src/: source directory;
thirdparty/: Third-party dependent library.
