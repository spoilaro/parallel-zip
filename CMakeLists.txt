cmake_minimum_required(VERSION 3.10)

project(pzip)

set(Sources
  main.c
  files.c
)

set(Headers
  files.h
)

add_executable(pzip ${Sources} ${Headers})


enable_testing()

file(GLOB TEST_FILES tests/*.c)

add_executable(pzip_test ${TEST_FILES})
add_test(pzip_test pzip_test)


