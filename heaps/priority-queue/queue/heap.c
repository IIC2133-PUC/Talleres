#include "heap.h"


Heap* heap_create(int size)
{
    Heap* heap = (Heap*)calloc(1, sizeof(Heap));
    heap->size = size;
    heap->capacity = 0;
    heap->nodes = (Node**)calloc(size, sizeof(Node*));
    return heap;
}


void heap_destroy(Heap* heap)
{
    free(heap->nodes);
    free(heap);
}


void percolate_up(Heap* heap, int index)
{
    int parent = (index - 1) / 2;
    if (index > 0 && heap->nodes[index]->priority < heap->nodes[parent]->priority)
    {
        Node* temp = heap->nodes[index];
        heap->nodes[index] = heap->nodes[parent];
        heap->nodes[parent] = temp;
        percolate_up(heap, parent);
    }
}


void percolate_down(Heap* heap, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int min = index;
    if (left < heap->capacity && heap->nodes[left]->priority < heap->nodes[min]->priority)
    {
        min = left;
    }
    if (right < heap->capacity && heap->nodes[right]->priority < heap->nodes[min]->priority)
    {
        min = right;
    }
    if (min != index)
    {
        Node* temp = heap->nodes[index];
        heap->nodes[index] = heap->nodes[min];
        heap->nodes[min] = temp;
        percolate_down(heap, min);
    }
}


void heap_insert(Heap* heap, int key, int priority)
{
    if (heap->capacity == heap->size)
    {
        heap->size *= 2;
        heap->nodes = (Node**)realloc(heap->nodes, heap->size * sizeof(Node*));
    }
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->key = key;
    node->priority = priority;
    heap->nodes[heap->capacity] = node;
    percolate_up(heap, heap->capacity);
    heap->capacity++;
}

Node* heap_extract_min(Heap* heap)
{
    Node* min = heap->nodes[0];
    heap->nodes[0] = heap->nodes[heap->capacity - 1];
    heap->capacity--;
    percolate_down(heap, 0);
    return min;
}


void heapify(Heap* heap)
{
    for (int i = heap->capacity / 2; i >= 0; i--)
    {
        percolate_down(heap, i);
    }
}

void heap_free(Heap* heap)
{
    for (int i = 0; i < heap->capacity; i++)
    {
        free(heap->nodes[i]);
    }
    free(heap->nodes);
    free(heap);
}