#ifndef HEAP_H
#define HEAP_H

void* test_system_malloc(size_t size);

void test_system_free(void* ptr);

void* test_system_realloc(void* ptr, size_t size);

#endif
