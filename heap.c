#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

#include "heap.h"

#define MY_HEAP_MAX_SIZE (1024 * 2024)
static uint8_t memory[MY_HEAP_MAX_SIZE];

//Block structure 
/*typedef struct Block {
    size_t size;
    int free;  //equals 1 if block is free, 0 if block is not free
    struct Block* next; // pointer to next block
} Block;*/

static Block* free_list = NULL;

#define ALIGNMENT 8
#define ALIGN(size) (((size) + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1))

void init_memory() {
    free_list = (Block*)memory;
    free_list->size = MY_HEAP_MAX_SIZE - sizeof(Block);
    free_list->free = 1;
    free_list->next = NULL;
}

Block *find_free_block(size_t size) {
    Block *current = free_list;
    while (current) {
        if (current->size >= size && current->free) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void* block_to_ptr(Block* block) {
    return (void*)((char*)block + sizeof(Block));
}

// my malloc implementation 
void* xmalloc(size_t size) {
    if (!free_list) {
        init_memory();
    }

    size = ALIGN(size);
    Block *block = find_free_block(size);

    if (!block) {
        fprintf(stderr, "No free block found\n");
        return NULL;
    }

    block->free = 0;
    void *ptr = block_to_ptr(block);
    memset(ptr, 0, size);

    return ptr;
}

void coalesce_free_blocks() {
    Block *current = free_list;
    while (current && current->next) {
        if (current->free && current->next->free) {
            current->size += current->next->size + sizeof(Block);
            current->next = current->next->next;
        }
        else {
            current = current->next;
        }
    }
}

// my custom free
void xfree(void* ptr) {
    if (!ptr) {
        return; // Null pointer, nothing to free
    }

    if ((uint8_t *)ptr < memory || (uint8_t *)ptr >= memory + MY_HEAP_MAX_SIZE) {
        fprintf(stderr, "xfree: Ivalid pointer\n");
        return;
    }

    Block *block = (Block *)((uint8_t *)ptr - sizeof(Block));

    if (block->free) {
        fprintf(stderr, "xfree: Block is already free\n");
        return;
    }

    block->free = 1; 
    
    coalesce_free_blocks();
}

// my custom realloc
void* xrealloc(void* ptr, size_t size) {
    printf("Testing my custom realloc\n");
    return NULL;
}   