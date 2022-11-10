#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node_t {
    int value;
    struct node_t *left_child;
    struct node_t *right_child;
} Node;

Node* node_create(int value);

void insert_node(Node* root, Node* node);

void print_tree(Node* root);

void find_parent(Node* root, int value);