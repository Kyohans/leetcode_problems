CC=clang
CFLAGS=-g -Wall -I../../include 

BINDIR=$(abspath bin)
SRCDIR=src
PROBLEMDIR=$(SRCDIR)/problems
STRUCTS=$(wildcard $(SRCDIR)/structs/*.c)
TARGET=$(BINDIR)/solution

