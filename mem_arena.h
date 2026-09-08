#pragma once
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct {
    uint8_t* buffer;
    size_t capacity;
    size_t offset;
} Arena; 

void InitArena(Arena* arena, size_t capacity);
void* ArenaAlloc(Arena* arena, size_t size);
void ArenaReset(Arena* arena);
void ArenaFree(Arena* arena);