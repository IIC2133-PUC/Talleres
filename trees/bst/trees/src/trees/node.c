#include "node.h"

Node* node_create(int value){
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->value = value;

    return node;
}

void insert_node(Node* root, Node* node){
    Node* actual_node = root;
    bool is_node_inserted = false;
    while(!is_node_inserted){
        if (actual_node->value > node->value){
            if (actual_node->left_child){
                actual_node = actual_node->left_child;
            } else {
                actual_node->left_child = node;
                is_node_inserted = true;
            }
        } else {
            if (actual_node->right_child){
                actual_node = actual_node->right_child;
            } else {
                actual_node->right_child = node;
                is_node_inserted = true;
            }
        }
    }
}

void print_tree(Node* node){
    printf("%d ", node->value);
    if (node->left_child) { print_tree(node->left_child); }
    if (node->right_child) { print_tree(node->right_child); }
}

void find_parent(Node* root, int value){
    Node* actual_node = root;
    while(actual_node){
        if (actual_node->value > value){
            if (actual_node->left_child->value == value){
                printf("%d", actual_node->value);
                break;
            }
            actual_node = actual_node->left_child;
        } else {
            if (actual_node->right_child->value == value){
                printf("%d", actual_node->value);
                break;
            }
            actual_node = actual_node->right_child;
        }
    }
}