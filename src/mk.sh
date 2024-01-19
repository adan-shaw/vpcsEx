#!/bin/sh

os=`uname`

if [ $# -eq 0 ]; then
    arch=`uname -p`
fi

CCOPT="-O2"

# 只有一个参数的情况: 
# mk.sh debug / mk.sh clean 
# mk.sh i386 / mk.sh amd64 
if [ $# -eq 1 ]; then
    case $1 in
    clean)
        MKOPT=clean
        arch=`uname -p`
        ;;
    debug)
        CCOPT="-g"
        MKOPT=all 
        arch=`uname -p`
        ;;
    *)
        arch=$1
    esac
fi

# 有2 个参数的情况(任意模式, 任意输入都行, 部分前后, 非常秀的写法, 但实用性不强):
# mk.sh debug amd64 / mk.sh clean amd64
# mk.sh i386 debug / mk.sh amd64 debug
if [ $# -eq 2 ]; then
    case $1 in
    clean)
        MKOPT=clean
        arch=$2
        ;;
    debug)
        CCOPT="-g"
        MKOPT=all
        arch=$2
        ;;
    esac
    case $2 in
    clean)
        MKOPT=clean
        arch=$1
        ;;
    debug)
        CCOPT="-g"
        MKOPT=all
        arch=$1
        ;;
    esac
fi



if [ "x$arch" = "x" ]; then
    echo $0" [i386 | amd64 | 32 | 64] [clean | debug]"
    exit 1
fi

if [ $arch = "i386" -o $arch = "32" ]; then
    CCOPT=$CCOPT" -m32"
fi

if [ $arch = "amd64" -o $arch = "x86_64" -o $arch = "64" ]; then
    CCOPT=$CCOPT" -m64"
fi

if [ $os = "Darwin" ]; then
    CCOPT=$CCOPT""
fi

export CCOPT
echo $CCOPT
echo $os
echo $MKOPT
case ${os} in
    FreeBSD)
        make -f Makefile.fbsd ${MKOPT}
        ;;
    Linux)
        make -f Makefile.linux ${MKOPT}
        ;;
    CYGWIN*)
        make -f Makefile.cygwin ${MKOPT}
        ;;
    Darwin)
        make -f Makefile.osx ${MKOPT}
        ;;
    *)
        echo "Not support"
        ;;
esac
