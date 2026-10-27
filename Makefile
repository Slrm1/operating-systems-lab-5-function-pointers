CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g

.PHONY: all test clean

all: task1/qsort task2/func_ptr

task1/qsort: task1/func-ptr.c
	$(CC) $(CFLAGS) $< -o $@

task2/func_ptr: task2/task2.c
	$(CC) $(CFLAGS) $< -o $@

test: task1/qsort
	./task1/qsort task1/test-data/test1.csv > task1/test-data/test1.log
	diff task1/test-data/test1.log task1/test-data/test1-exp.log

clean:
	rm -f task1/qsort task2/func_ptr task1/test-data/test1.log
