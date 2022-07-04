#!/bin/bash

NAME=boxes

/usr/bin/fpc -dEVAL -XS -O2 -o$NAME grader.pas
