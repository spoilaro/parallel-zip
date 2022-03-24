#include <stdio.h>
#include "files.h"
#include <assert.h>

int main(int argc, char *argv[]){
  
  char *raw_line;
  char *filename;
  char *compressed_line;
  
  if (argc == 1){
    fprintf(stderr, "No file specified\n");
    return 1;
  }

  filename = argv[1];

  raw_line = read_file(filename, raw_line);
  compressed_line = compress(raw_line);
  
  // TODO Write tests for compress
  // TODO Free memory


  return 0;
}
