# Operating Systems Lab 5 — Function Pointers

This repository contains both completed tasks for CSCI Operating Systems Lab 5.

## Task 1: qsort comparator

`task1/func-ptr.c` reads processes from a CSV file and sorts them with the C standard library's `qsort` function. The custom comparator orders processes by:

1. Higher priority first.
2. Earlier arrival time when priorities are equal.

## Task 2: function-pointer dispatch

`task2/task2.c` implements a five-entry dispatch table for addition, subtraction, multiplication, division, and program exit. It selects the operation directly through a function pointer and uses no `if`, `else`, `switch`, or `goto` statements.

## Build and test

```bash
make
make test
```

Run Task 1:

```bash
./task1/qsort task1/test-data/test1.csv
```

Run Task 2:

```bash
./task2/func_ptr
```

Both Codio autograders earned **100/100**.
