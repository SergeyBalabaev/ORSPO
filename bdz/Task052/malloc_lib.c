#include <stdio.h> 
#include <unistd.h> 
#include <assert.h>
#include <string.h>
#include <stdarg.h>
#include "safe_printf_lib.h"

//используем safe_printf т.к. обычный printf для выделения памяти под буфер использует malloc

#ifdef DEBUG
	#define info(... ) safe_printf(__VA_ARGS__)
#else
	#define info(... )
#endif


int has_initialized = 0;	//флаг инициализации malloc_init
void* managed_memory_start; //указатель на начало выделенной памяти
void* last_valid_address;	//указатель на последний доступный адрес

struct mem_control_block {
	int is_available;
	int size;
};

void malloc_init()
{
	///
}


void* malloc(long numbytes) {
	///
}

void free(void* firstbyte) {
	///
}

