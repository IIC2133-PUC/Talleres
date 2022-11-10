#include "hashtable.h"

int hash_function(int key, int range) {
    return key % range;
}

void insert_or_update(HashItem **table, int key, int value, int table_size){
    int table_index = hash_function(key, table_size);
    HashItem *item = table[table_index];
    if (item == NULL) {
        item = calloc(1, sizeof(HashItem));
        item->key = key;
        item->value = value;
        item->next = NULL;
        table[table_index] = item;
    } else {
        while (item->next != NULL) {
            if (item->key == key) {
                item->value += value;
                return;
            }
            item = item->next;
        }
        if (item->key == key) {
            item->value += value;
            return;
        }
        item->next = calloc(1, sizeof(HashItem));
        item->next->key = key;
        item->next->value = value;
        item->next->next = NULL;
    }
}

int fetch_value(HashItem **table, int key, int table_size) {
    int table_index = hash_function(key, table_size);
    HashItem *item = table[table_index];
    while (item != NULL) {
        if (item->key == key) {
            return item->value;
        }
        item = item->next;
    }
    return 0;
}