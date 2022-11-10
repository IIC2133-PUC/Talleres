#pragma once

#include <stdlib.h>
#include <stdio.h>

#define MAX_NEIGHBORS 1024

typedef struct node_t {
    int x;
    int y;
    struct node_t **neighbors;
    struct node_t *next;
    int visited;
    int neighbors_count;
} Node;

void insert_neighbor(Node *graph, Node *neighbor);

Node* find_or_create_node(Node *root, int x, int y);

Node* initialize_root(int x, int y);

int recursive_dfs(Node *root);