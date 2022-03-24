
#include <assert.h>
#include "../files.h"
#include <stdio.h>
#include <string.h>

int main(void){
  char *line = NULL;


  line = read_file("test_input.txt", line);

  if (line == NULL){
    return 1;
  }


  return 0;

}
