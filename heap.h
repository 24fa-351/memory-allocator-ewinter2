#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>

void* xmalloc(size_t size);

void xfree(void* ptr);

void* xrealloc(void* ptr, size_t size);


#endif
