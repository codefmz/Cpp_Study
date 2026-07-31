#!/usr/bin/env bash

TOP_DIR=$(cd "$(dirname "$0")"; pwd)
echo "TOP_DIR=$TOP_DIR"

target=""
debug=""
rebuild=""

print_usage() {
    echo "Usage: sh $(basename "$0") [-t <target>] [-d <debug>] [-r <rebuild>]"
    echo "eg: sh $(basename "$0") -t "
}

# 解析命令行参数
ARGS=$(getopt -o t:d:r --name "$0" -- "$@")
if [ $? -ne 0 ]; then
    echo "Error in command line arguments."
    print_usage
    exit 1
fi

eval set -- "$ARGS"
while true; do
    case "$1" in
        -t)
            target="$2"
            shift 2
            ;;
        -d)
            debug="$2"
            shift 2
            ;;
        -r)
            rebuild="y"
            shift 1
            ;;
        --)
            shift
            break
            ;;
        *)
            echo "Invalid command."
            print_usage
            exit 1
            ;;
    esac
done

cmake_params=""
if [ "$debug" = "y" ]; then
    cmake_params="-DCMAKE_BUILD_TYPE=Debug"
else
    cmake_params="-DCMAKE_BUILD_TYPE=Release"
fi

if [ "$target" != "" ]; then
    cmake_params="$cmake_params -DTARGET=$target"
fi

if [ "$rebuild" = "y" ]; then
    rm -rf build
fi


if [ "$rebuild" = "y" ] ; then
    cmake --preset=default $cmake_params
fi

echo "compile target = ${target}, debug = ${debug}"
cmake --build build -- -j$(nproc)