#include "mem_arena.h"

void InitArena(Arena* arena, size_t capacity){
    arena->capacity = capacity;
    arena->offset = 0;
    arena->buffer = malloc(arena->capacity);
}

void* ArenaAlloc(Arena* arena, size_t size){
    size_t aligned_offset = arena->offset;
    aligned_offset = (aligned_offset + 15) & ~15;

    if(aligned_offset + size > arena->capacity){
        return NULL;
    }

    void* ptr = arena->buffer + aligned_offset;
    arena->offset = aligned_offset + size;

    return ptr;
}

void ArenaReset(Arena* arena){
    arena->offset = 0;
}

void ArenaFree(Arena* arena){
    free(arena->buffer);
}
