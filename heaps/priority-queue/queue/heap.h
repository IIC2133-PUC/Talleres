#pragma once
#include <stdlib.h>

typedef struct node_t {
    int key;
    int priority;
} Node;

typedef struct heap_t {
    Node **nodes;
    int size;
    int capacity;
} Heap;


Heap *heap_create(int capacity);

void heap_free(Heap *heap);

void heap_insert(Heap *heap, int key, int priority);

Node *heap_extract_min(Heap *heap);

void percolate_down(Heap *heap, int index);

void percolate_up(Heap *heap, int index);

void heapify(Heap *heap);


