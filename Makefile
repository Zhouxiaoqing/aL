cc = gcc
cflag = -g -Wall
lflag = 

incl_dir = ./incl
src_dir = ./src
test_dir = ./test

all : internal_sort.o

internal_sort.o : ${incl_dir}/internal_sort.h ${src_dir}/internal_sort.c
	${cc} ${cflag} -c 
