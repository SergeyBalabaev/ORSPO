#include <stdio.h> 
#include <stdlib.h>

static char bss[1]; 
static char data[1] = {'a'}; 
static const char rodata[] = {"rodata"}; 

int main(void) 
{ 
  char stack; 
  char *heap = (char*)malloc(1024*sizeof(char)); 
  free(heap); 
  return 0; 
} 
