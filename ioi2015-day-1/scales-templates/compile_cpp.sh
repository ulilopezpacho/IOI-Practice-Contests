#!/bin/bash

NAME=scales

/usr/bin/g++ -static -O2 -Wall -Wextra -Wshadow -D_GLIBCXX_DEBUG -std=c++11 -o $NAME grader.cpp $NAME.cpp
