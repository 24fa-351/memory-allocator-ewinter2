#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

int LOGGING_ON = 1;
int SYSTEM_FUNCTIONS_ON = 1;

void* test_system_malloc(size_t size) {
    if (LOGGING_ON) printf("Testing malloc\n");
    
    void *ptr = malloc(size);
    return ptr;
}

void test_system_free(void* ptr) {
    if (LOGGING_ON) printf("Testing free\n");

    free(ptr);
}

void* test_system_realloc(void* ptr, size_t size) {
    if (LOGGING_ON) printf("Testing realloc\n");

    void *new_ptr = realloc(ptr, size);
    return new_ptr;
}
