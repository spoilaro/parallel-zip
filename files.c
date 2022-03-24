#include "files.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>

char *read_file(char *filename, char *line) {
  int f;
  struct stat s;
  int status;
  size_t file_size;
  char *mapped = line;

  f = open(filename, O_RDONLY);
  if (f < 0) {
    fprintf(stderr, "Could not read the file\n");
  }

  status = fstat(f, &s);
  if (status < 0) {
    fprintf(stderr, "Could not get the file size\n");
  }
  file_size = s.st_size;

  mapped = mmap(0, file_size, PROT_READ, MAP_PRIVATE, f, 0);

  return mapped;
}
