#!/usr/bin/bash

set -e  # stop on first error

usage () {
    echo "                                                  "
    echo "Build Script for Cracking CPP Questions           "
    echo "                                                  "
    echo "Usage: $0 [OPTIONS] <command>                     "
    echo "                                                  "
    echo "OPTIONS:                                          "
    echo "  -h          Print this help message             "
    echo "  -q          Specify question:                   "
    echo "                 - all (default)                  "
    echo "                 - name of the question           "
    echo "                                                  "
    echo "Commands:                                         "
    echo "  build       Build all questions                 "
    echo "  test        Run tests for all questions         "
    echo "  clean       Clean build files                   "
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
        cd buildz
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
    fi
    rm -rf build
}

##############################################
# Main

# Present usage.
if [ $# -eq 0 ]; then
    usage
    exit $NO_COMMAND_FOUND
fi

QUESTIONS="all"

# Get options
SHIFTCOUNT=0
while getopts ":h?:q:" opt; do

    case "$opt" in
        h|\?)
            usage
            exit 0
            ;;
        q)
            QUESTIONS=$OPTARG
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
            build "$QUESTIONS"
            shift
            break
            ;;
        test)
            test "$QUESTIONS"
            shift
            break
            ;;
        clean)
            clean "$QUESTIONS"
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
