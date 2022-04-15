#include "compressor.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>

Compressor *Compressor__init(char *file_name){
  Compressor *c = malloc(sizeof(Compressor));

  c->raw_line = NULL;
  c->compressed_line = NULL;
  c->file_name = file_name;

  return c;
}

void Compressor__read(Compressor *self) {

  int f;
  struct stat s;
  int status;
  size_t file_size;
  char *mapped = self->raw_line;

  f = open(self->file_name, O_RDONLY);
  if (f < 0) {
    fprintf(stderr, "Could not read the file\n");
  }

  status = fstat(f, &s);
  if (status < 0) {
    fprintf(stderr, "Could not get the file size\n");
  }
  file_size = s.st_size;

  mapped = mmap(0, file_size, PROT_READ, MAP_PRIVATE, f, 0);

  self->raw_line = mapped;
}

void Compressor__compress(Compressor *self) {

  int rlen;
  int length = strlen(self->raw_line);
  char *compressed_line = malloc(sizeof(char) * (length * 2 +1));
  char count[50];

  int i, j = 0, k;

  for (i = 0; i<length; i++){
    compressed_line[j++] = self->raw_line[i];

    rlen = 1;
    while (i+1 < length && self->raw_line[i] == self->raw_line[i+1]){
      rlen++;
      i++;
    }

    sprintf(count, "%d", rlen);

    for (k=0; *(count + k); k++, j++){
      compressed_line[j] = count[k];
    }
  }

  compressed_line[j] = '\0';

  self->compressed_line = compressed_line;
}

void Compressor__printer(Compressor *self) {
  printf("Raw line is %s \n", self->raw_line);
  printf("Compressed line is %s \n", self->compressed_line);
}
