CC=clang
CFLAGS=-g -Wall -I../../include 

SRCDIR=src
PROBLEMDIR=$(SRCDIR)/problems
STRUCTS=$(wildcard $(SRCDIR)/structs/*.c)
TARGET=../../../bin/solution

