#ifndef MEMORY_LAYOUT_H
#define MEMORY_LAYOUT_H

#define repeat_count 100
#define heap_size 2048

void say_hello();

char* allocate_heap();
void deallocate_heap(char *heap);

void print_memory_layout();

#endif // MEMORY_LAYOUT_H
