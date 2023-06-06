#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b);
int** create_dynamic_table(int n, int m);
void destroy_dynamic_table(int** table, int n);
int cutting_rod(int* values, int value_count, int N, int** dp_table);
