#!/bin/bash

NAME=boxes

/usr/bin/g++ -DEVAL -static -O2 -Wall -Wextra -Wshadow -D_GLIBCXX_DEBUG -std=c++11 -o $NAME grader.cpp $NAME.cpp
