CC=clang
CFLAGS=-g -Wall -I../../include 

BINDIR=bin
SRCDIR=src
STRUCTS=$(wildcard $(SRCDIR)/structs/*.c)
TARGET=../../$(BINDIR)/solution

