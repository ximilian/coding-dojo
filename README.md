# ximilian's coding dojo

This repository represents my personal dojo. I put here all my attempts to solve coding katas, small exercise and more.
I try to keep it clean and self explanatory, however...

## kata
This folder holds the description to each kata, in plain text

## cpp
In here you can find the solutions to the katas done using c++. I use CMake to compile and tests everything (the building system has been taken from [here](https://github.com/snikulov/google-test-examples)
To run all tests, just do
```bash
cd cpp
cmake -P build.cmake
```
A version of google test is download, compiled and linked so the unittest can be tested