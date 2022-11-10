#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct hashitem_t {
    int key;
    int value;
    struct hashitem_t *next;
} HashItem;


int hash_function(int key, int range);

void insert_or_update(HashItem **table, int key, int value, int table_size);

int fetch_value(HashItem **table, int key, int table_size);