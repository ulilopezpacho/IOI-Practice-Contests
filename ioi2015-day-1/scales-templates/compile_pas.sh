#!/bin/bash

NAME=scales

/usr/bin/fpc -dEVAL -XS -O2 -o$NAME grader.pas
