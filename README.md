# Parallel Zip

## Overall
Parallel Zip (pzip) is a program that compresses files using run length encoding.
In addition to that pzip uses multithreading to speed up the process of
compressing multiple files.

## Instructions
```
$ mkdir build   // Creates a build directory
$ cd build
$ cmake ..      // Generates a Makefile
$ make          // Does the actual building
$ pzip <file> <file> ... 
```

