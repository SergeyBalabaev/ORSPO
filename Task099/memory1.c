#include <stdio.h> 
#include <stdlib.h>

static char bss[1000]; 
static char data[1000] = {'a'}; 
static const char rodata[1000] = {"rodata"}; 

int main(void) 
{ 
  char stack; 
  char *heap = (char*)malloc(1024*sizeof(char)); 
  free(heap); 
  return 0; 
} 
