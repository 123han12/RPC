#! /bin/bash

set -e 

rm -rf  `pwd`/build/*

cd `pwd`/build && 
    cmake .. && 
    make 
cd `pwd`/../

sudo cp -r `pwd`/lib/*  /usr/local/lib 

# 安装rpc的头文件和rpc静态库
# sudo cp -r `pwd`/include/*  /usr/local/include