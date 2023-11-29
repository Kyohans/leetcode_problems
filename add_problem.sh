#!/bin/bash

PROBLEM=$1

mkdir -p src/${PROBLEM} && touch src/${PROBLEM}/{solution.c,Makefile}
