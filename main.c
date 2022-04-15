#include <stdio.h>
#include "files.h"
#include <assert.h>
#include "compressor.h"
#include <pthread.h>

void * thread_runner(void * file_name) {
  char *input_name = (char *) file_name;
  Compressor *c;

  c = Compressor__init(input_name);
  Compressor__read(c);
  Compressor__compress(c);
  Compressor__printer(c);

  return 0;
}

int main(int argc, char *argv[]){
  
  char *filename;
  char *filename2 = "../input2.txt";

  printf("Args are %s \n", argv[1]);
  printf("Args are %s \n", argv[2]);

  // Threads
  pthread_t tid0;
  pthread_t tid1;

  if (argc == 1){
    fprintf(stderr, "No file specified\n");
    return 1;
  }

  filename = argv[1];

  pthread_create(&tid0, NULL, thread_runner, (void *)filename);
  pthread_create(&tid1, NULL, thread_runner, (void *)filename2);
  
  // TODO Write tests for compress
  // TODO Free memory
  
  pthread_exit(NULL);

  return 0;
}
