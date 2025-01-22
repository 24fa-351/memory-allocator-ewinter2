#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>

typedef struct Block {
    size_t size;
    int free;
    struct Block* next;
} Block;

void init_memory();

Block *find_free_block(size_t size);

void* block_to_ptr(Block* block);

void* xmalloc(size_t size);

void coalesce_free_blocks();

void xfree(void* ptr);

void* xrealloc(void* ptr, size_t size);


#endif
