#include <stdio.h>
#include "files.h"
#include <assert.h>

int main(int argc, char *argv[]){
  
  char *line;
  char *filename;
  
  assert(argc == 2);
  filename = argv[1];

  line = read_file(filename, line);

  printf("File contains %s \n", line);

  return 0;
}
