#include "files.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>

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

char *compress(char *raw_line) {
  
  int rlen;
  int length = strlen(raw_line);
  char *compressed_line = malloc(sizeof(char) * (length * 2 +1));
  char count[50];

  int i, j = 0, k;

  for (i = 0; i<length; i++){
    compressed_line[j++] = raw_line[i];

    rlen = 1;
    while (i+1 < length && raw_line[i] == raw_line[i+1]){
      rlen++;
      i++;
    }

    sprintf(count, "%d", rlen);

    for (k=0; *(count + k); k++, j++){
      compressed_line[j] = count[k];
    }
  }

  compressed_line[j] = '\0';


  return compressed_line;

}
