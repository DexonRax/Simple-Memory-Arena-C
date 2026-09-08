#include <stdio.h>
#include "mem_arena.h"

#define ARENA_CAPACITY 8192

int main(){
    printf("Hello World!\n");

    Arena arena = {};
    InitArena(&arena, ARENA_CAPACITY);

    size_t arr_size = 10;
    int* a = ArenaAlloc(&arena, sizeof(int) * arr_size);
    for(size_t i = 0; i < arr_size; ++i){
        a[i] = i * 10 + 10;
    }

    float* b = ArenaAlloc(&arena, sizeof(int) * arr_size);
    for(size_t i = 0; i < arr_size; ++i){
        b[i] = i * 13.13f + 13.f;
    }

    for(size_t i = 0; i < arr_size; ++i){
        printf("a[%zu] = %d\n", i, a[i]);
    }

    for(size_t i = 0; i < arr_size; ++i){
        printf("b[%zu] = %.2f\n", i, b[i]);
    }

    ArenaFree(&arena);
    return 0;
}