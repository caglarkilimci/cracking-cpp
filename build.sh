#!/usr/bin/bash

set -e  # stop on first error

usage () {
    echo "                                                  "
    echo "Build Script for Cracking CPP Questions           "
    echo "                                                  "
    echo "Usage: $0 [OPTION] <command>                      "
    echo "                                                  "
    echo "OPTIONS:                                          "
    echo "  -h             Print this help message          "
    echo "  -q             Specify question:                "
    echo "                  - all (default)                 "
    echo "                  - name of the question          "
    echo "                                                  "
    echo "Commands:                                         "
    echo "  build              Build question(s)            "
    echo "  test               Run test(s) for question(s)  "
    echo "  clean              Clean build file(s)          "
    echo "  create <name>      Create a new question in C   "
    echo "  cpp-create <name>  Create a new question in CPP "
    echo "                                                  "
}

# Constants
INVALID_OPTION=1
INVALID_COMMAND=2
QUESTION_NOT_FOUND=3
NO_COMMAND_FOUND=4

check_question () {
    if [ ! -d "$1" ]; then
        echo -e "\e[31mError: Question not found.\e[0m"
        exit $QUESTION_NOT_FOUND
    fi
}

build () {
    echo "Building: $1"
    if [ "$1" != "all" ]; then
        check_question $1
        cd $1
    fi
    mkdir -p build
    cd build
    cmake ..
    make
    cd ..
}

check_build () {
    echo "Checking build: $1"
    if [ ! -d "build" ]; then
        echo -e "\e[33mWarning: Build directory not found. Building first.\e[0m"
        build $1
    fi
}

test () {
    echo -e "\e[32mTesting: $1\e[0m"
    if [ "$1" != "all" ]; then
        check_question $1
        cd $1
        check_build .
        cd build
        ctest
    else
        check_build all
        cd build
        for d in */ ; do
            echo -e "\e[1;32mTesting: $d\e[0m"
            ctest --test-dir $d
        done
    fi
}

clean () {
    echo "Cleaning: $1"
    if [ "$1" != "all" ]; then
        check_question $1
        cd $1
        rm -rf build
        cd ..
    else
        rm -rf build
    fi
}

create () {
    echo "Creating: $1"
    mkdir -p $1
    SAMPLE_NAME="sample_c"
    clean $SAMPLE_NAME
    cp -r $SAMPLE_NAME/* $1
    mv $1/$SAMPLE_NAME.c $1/$1.c
    mv $1/$SAMPLE_NAME.h $1/$1.h
    mv $1/test_$SAMPLE_NAME.c $1/test_$1.c
    sed -i "s/$SAMPLE_NAME/$1/g" $1/CMakeLists.txt
    sed -i "s/$SAMPLE_NAME/$1/g" $1/$1.c
    UPPER_SAMPLE_NAME=$(echo "$SAMPLE_NAME" | awk '{ print toupper($0) }')
    UPPER_NAME=$(echo "$1" | awk '{ print toupper($0) }')
    sed -i "s/$UPPER_SAMPLE_NAME/$UPPER_NAME/g" $1/$1.h
    sed -i "s/$SAMPLE_NAME/$1/g" $1/test_$1.c
    echo "add_subdirectory($1)" >> CMakeLists.txt

    echo "Question created: $1"
}

cpp_create () {
    echo "Creating cpp: $1"
    mkdir -p $1
    SAMPLE_NAME="sample_cpp"
    clean $SAMPLE_NAME
    cp -r $SAMPLE_NAME/* $1
    mv $1/$SAMPLE_NAME.cpp $1/$1.cpp
    mv $1/$SAMPLE_NAME.hpp $1/$1.hpp
    mv $1/test_$SAMPLE_NAME.cpp $1/test_$1.cpp
    sed -i "s/$SAMPLE_NAME/$1/g" $1/CMakeLists.txt
    sed -i "s/$SAMPLE_NAME/$1/g" $1/$1.cpp
    UPPER_SAMPLE_NAME=$(echo "$SAMPLE_NAME" | awk '{ print toupper($0) }')
    UPPER_NAME=$(echo "$1" | awk '{ print toupper($0) }')
    sed -i "s/$UPPER_SAMPLE_NAME/$UPPER_NAME/g" $1/$1.hpp
    sed -i "s/$SAMPLE_NAME/$1/g" $1/test_$1.cpp
    echo "add_subdirectory($1)" >> CMakeLists.txt

    echo "Question created in CPP: $1"
}

##############################################
# Main

# Present usage.
if [ $# -eq 0 ]; then
    usage
    exit $NO_COMMAND_FOUND
fi

QUESTION="all"

# Get options
SHIFTCOUNT=0
while getopts ":h?:q:" opt; do

    case "$opt" in
        h|\?)
            usage
            exit 0
            ;;
        q)
            QUESTION=$OPTARG
            SHIFTCOUNT=$(( $SHIFTCOUNT+2 ))
            ;;
        \?)
            echo "Invalid option: -$OPTARG" >&2
            usage
            exit $INVALID_OPTION
            ;;
    esac
done
# Move to the next argument after the options
shift $((OPTIND-1))

# Check if a command is provided
if [ $# -eq 0 ]; then
    echo "Error: No command provided."
    usage
    exit $NO_COMMAND_FOUND
fi

echo "Command: $1"

# Process all commands.
while true ; do
    case "$1" in
        build)
            build "$QUESTION"
            shift
            break
            ;;
        test)
            test "$QUESTION"
            shift
            break
            ;;
        clean)
            clean "$QUESTION"
            shift
            break
            ;;
        create)
            if [ ! -z "$2" ]; then
                QUESTION=$2
            fi
            if [ "$QUESTION" == "all" ]; then
                echo "Error: Question name not provided."
                exit $INVALID_COMMAND
            fi
            if [ -d "$QUESTION" ]; then
                echo "Error: Question already exists."
                exit $INVALID_COMMAND
            fi
            echo "Creating question: $QUESTION"
            create "$QUESTION"
            shift
            shift
            break
            ;;
        cpp-create)
            if [ ! -z "$2" ]; then
                QUESTION=$2
            fi
            if [ "$QUESTION" == "all" ]; then
                echo "Error: Question name not provided."
                exit $INVALID_COMMAND
            fi
            if [ -d "$QUESTION" ]; then
                echo "Error: Question already exists."
                exit $INVALID_COMMAND
            fi
            echo "Creating CPP question: $QUESTION"
            cpp_create "$QUESTION"
            shift
            shift
            break
            ;;
        *)
            if [[ -n "$1" ]]; then
                echo "Unknown command: $1 "
                exit $INVALID_COMMAND
            fi
            break
            ;;
    esac
done

exit 0
