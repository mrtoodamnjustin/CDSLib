# CDSLib

This personal project aims to implement several data structures in C, including linked lists, stacks, queues, trees, and graphs. Each data structure is modularized for ease of use and reusability.

## Directory Structure

- `src/`: Contains the source code for data structures.
- `include/`: Header files defining structure types and function prototypes.
- `tests/`: Contains unit tests for each data structure.

## Included Datastructures

### Currently Implemented

- Linked List

### To Be Implemented

- Graph
- Hashmap
- Queue
- Stack
- Tree
- Binary Tree

## Building

To compile the project into a dll (placed in `./lib`), run:

```
make
```

To clean the build files run:
```
make clean
```

## Using the library

To use the dll compiled into `./lib`, simply copy the headers to your own project and then place the dll into your final executables directory.

The headers and source files can also be individually copied as needed to avoid using a dll.

## Running the tests

To run the data structures tests in `./test` first, build the dll

```
make
```

Then, compile the test using the library and headers

``` 
gcc -Iinclude -Llib -ldatastructures -o test.exe tests/test_example.c
```

**To use your executable, it must be in the same path as the dll. If they are placed in different directories, the executable will fail to function.**

### Without using the dll

If you want to test a data structure without using the dll, just pass the source of the test and the data structure to gcc whilst using the appropriate flags.

```
gcc -Iinclude -o test.exe test/test_datastructure.c src/datastructure.c
```