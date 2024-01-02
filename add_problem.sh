#!/bin/bash

if [ $# -lt 1 ]; then
  echo "usage: ./add_problem.sh [challenge_name]"
  exit 1
fi

PROBLEM=$1

mkdir -p src/problems/${PROBLEM} && touch src/problems/${PROBLEM}/{${PROBLEM}.c,Makefile}

cat << EOF > src/problems/${PROBLEM}/Makefile
include ../../../common.mk

SRCS = ${PROBLEM}.c

all:
    \$(CC) \$(CFLAGS) \$(SRCS) -o \$(TARGET)
EOF
