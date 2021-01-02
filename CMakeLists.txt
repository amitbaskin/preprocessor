cmake_minimum_required(VERSION 3.17)
project(preprocessor C)

set(CMAKE_C_STANDARD 90)

add_executable(preprocessor preprocessor.c processArg.c processArg.h openFile.c openFile.h preUtils.c preUtils.h filename.c filename.h)