cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 99)

project(pzip)

set(SOURCE_FILES
  compressor.c
  compressor.h
)
add_library(Utilites STATIC ${SOURCE_FILES})


add_executable(pzip main.c)
target_link_libraries(pzip Utilites)


#enable_testing()
#
#
#add_executable(file_reading tests/file_reading.c)
#
#target_link_libraries(file_reading Utilites)
#
#add_test(file_reading file_reading)







