#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graph.h"


// Problem:
// Given N pairs of edges. Check if the graph is a spanning tree.
// INPUT:
// k lines with format a1 b1 a2 b2 that indicates an edge between nodes 1 and 2.
// OUTPUT:
// 1 if the graph is a spanning tree, 0 otherwise.


int main(int argc, char **argv) {
    int edges = 0;
    Node *root = NULL;

    FILE* input = fopen(argv[1], "r");

    int a1, b1, a2, b2;
    Node *node1, *node2;
    while (fscanf(input, "%d %d %d %d", &a1, &b1, &a2, &b2) == 4) {
        edges++;
        if (root == NULL) {
            root = initialize_root(a1, b1);
        }

        node1 = find_or_create_node(root, a1, b1);
        node2 = find_or_create_node(root, a2, b2);
        insert_neighbor(node1, node2);
    }
    printf("Edges count: %d\n", edges);
    recursive_dfs(root);

    Node *current = root;
    int nodes_count = 0;
    while (current->next != NULL) {
        nodes_count++;

        if (!current->visited) {
            printf("Node %d %d is not a spanning tree\n", current->x, current->y);
            return 0;
        }
        current = current->next;
    }

    if (!current->visited) {
        printf("Node %d %d is not a spanning tree\n", current->x, current->y);
        return 0;
    }

    printf("Nodes count: %d\n", nodes_count + 1);
    printf("The graph is a spanning tree!\n");
    return 0;
}