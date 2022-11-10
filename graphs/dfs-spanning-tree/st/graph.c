#include "graph.h"

void insert_neighbor(Node *node, Node *neighbor) {
    node->neighbors[node->neighbors_count] = neighbor;
    node->neighbors_count++;

    neighbor->neighbors[neighbor->neighbors_count] = node;
    neighbor->neighbors_count++;
}

Node* find_or_create_node(Node *root, int x, int y){
    Node *current = root;
    Node *prev = NULL;
    while (current != NULL) {
        if (current->x == x && current->y == y) {
            return current;
        }
        prev = current;
        current = current->next;
    }

    Node *new_node = calloc(1, sizeof(Node));
    new_node->x = x;
    new_node->y = y;
    new_node->visited = 0;
    new_node->neighbors = calloc(MAX_NEIGHBORS, sizeof(Node*));
    new_node->neighbors_count = 0;
    new_node->next = NULL;
    prev->next = new_node;
    return new_node;
}

int recursive_dfs(Node *node) {
    if (node->visited) {
        return 1;
    }
    node->visited = 1;
    for (int i = 0; i < node->neighbors_count; i++) {
        recursive_dfs(node->neighbors[i]);
    }
    return 1;
}

Node* initialize_root(int x, int y) {
    Node *root = calloc(1, sizeof(Node));
    root->x = x;
    root->y = y;
    root->neighbors = calloc(MAX_NEIGHBORS, sizeof(Node*));
    root->neighbors_count = 0;
    root->next = NULL;
    root->visited = 0;
    return root;
}