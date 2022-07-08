#!/bin/bash

problem=sorting

g++ -DEVAL -static -O2 -std=c++11 -o $problem -Wall -Wshadow -Wextra -Wconversion -D_GLIBCXX_DEBUG grader.cpp $problem.cpp
