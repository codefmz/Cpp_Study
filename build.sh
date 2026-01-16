buildType=""
isNew=""

printUsage() {
    echo "Usage:  [options]"
    echo "options:"
    echo "  -n      is new build"
    echo "  -d      debug or release"
}

#--name "$0": 用于在错误时打印出脚本信息
# -- "$@ 结束标志， 代表传入脚本的 所有参数，保留每个参数的边界
ARGS=$(getopt -o nd --name "$0" -- "$@")
if [ $? != 0 ]; then
    echo "Error: Invalid arguments"
    printUsage
    exit 1
fi

eval set -- "$ARGS"
while true; do
    case "$1" in
        -n)
            isNew="y"
            shift
            ;;
        -d)
            debug="y"
            shift
            ;;
        --)
            shift
            break
            ;;
    esac
done

if [ "$isNew" = "y" ]; then
    rm -rf build
fi


if [ "$debug" = "y" ]; then
    cmake  -S . -B build -DCMAKE_BUILD_TYPE=Debug
else
    cmake  -S . -B build -DCMAKE_BUILD_TYPE=Debug
fi
cmake --build build