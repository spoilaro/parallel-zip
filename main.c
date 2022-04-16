#include <stdio.h>
#include "files.h"
#include <assert.h>
#include "compressor.h"
#include <pthread.h>
#include <stdlib.h>

void * thread_runner(void * file_name) {
  char *input_name = (char *) file_name;
  Compressor *c;

  c = Compressor__init(input_name);
  Compressor__read(c);
  Compressor__compress(c);
  Compressor__printer(c);

  free(c);

  return 0;
}

int main(int argc, char *argv[]){
  pthread_t *threads;
  int number_of_threads = argc - 1;

  threads = malloc(sizeof(pthread_t) * number_of_threads);

  if (argc == 1){
    fprintf(stderr, "No file specified\n");
    return 1;
  }

  for (int i=0; i<number_of_threads; i++){
      pthread_create(&threads[i], NULL, thread_runner, (void *)argv[i+1]);
  }
  
  // TODO Write tests for compress
  // TODO Free memory
  
  pthread_exit(NULL);

  free(threads);

  return 0;
}
