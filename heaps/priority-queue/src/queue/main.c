#include <stdio.h>
#include <stdlib.h>
#include "heap.h"



int main(int argc, char* argv[])
{
    FILE* input = fopen(argv[1], "r");

    // Simulacion cola de prioridad
    // Tendremos N nodos y V instrucciones donde N <= V
    // 1 <= V <= 100000
    // Una instruccion puede ser una tupla ID PRIORITY ó una tupla -1 -1
    // ID es un numero entero positivo y PRIORITY es un numero entero positivo
    // -1 -1 indica que se debe imprimir el ID del nodo con mayor prioridad y extraerlo de la cola
    // Al finalizar la simulacion se imprimen los primeros 10 nodos de la cola en orden de prioridad

    // La primera linea es V, la cantidad de instrucciones
    int V;
    fscanf(input, "%d", &V);

    // La segunda linea es N, la cantidad de nodos
    int N;
    fscanf(input, "%d", &N);

    // Luego continua V lineas con las instrucciones

    // Crear la cola de prioridad
    // En la tarea pueden usar un numero grande para el tamaño de la cola
    // O inferirlo desde la cantidad de caminos posibles
    Heap* heap = heap_create(N+1);

    // Leer las instrucciones
    for (int i = 0; i < V; i++)
    {
        int id, priority;
        fscanf(input, "%d %d", &id, &priority);
        if (id == -1 && priority == -1)
        {
            // Extraer el nodo con mayor prioridad
            Node* node = heap_extract_min(heap);
            printf("Node %d with priority %d extracted\n", node->key, node->priority);
            free(node);
        }
        else
        {
            // Insertar un nodo
            heap_insert(heap, id, priority);
        }
    }

    // Imprimir los primeros 10 nodos de la cola
    printf("First 10 nodes in the heap:\n");
    for (int i = 0; i < 10; i++)
    {
        Node* node = heap_extract_min(heap);
        printf("Node %d with priority %d\n", node->key, node->priority);
        free(node);
    }

    // Liberar la memoria
    heap_free(heap);

    return 0;
}