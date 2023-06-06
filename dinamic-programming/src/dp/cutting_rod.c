#include "cutting_rod.h"

int max(int a, int b) {
  return a > b ? a : b;
}

int** create_dynamic_table(int rows, int columns) {
  int** table = calloc(rows, sizeof(int*));

    for(int i = 0; i < rows; i++)
    {
        table[i] = calloc(columns, sizeof(int));
        memset(table[i], 0, columns * sizeof(int));
    }

    return table;
}

void destroy_dynamic_table(int** table, int rows) {
  for(int i = 0; i < rows; i++)
  {
    free(table[i]);
  }

  free(table);
}

int cutting_rod(int* values, int value_count, int N, int** dp_table) {
    // values: is a array where the gain of selling a
    // rod of size i is stored in values[i]
    // value_count: is the size of the values array
    // N: is the size of the rod we want to sell
    // dp_table: is a dinamic programming table where the
    // results of the subproblems are stored.

    // returns the highest gain possible for a rod of size N

    if(N == 0) {
      return 0;
    }

    if(dp_table[value_count][N] != 0) {
      return dp_table[value_count][N];
    }

    int max_value = 0;

    for(int i = 0; i < value_count; i++) {

      // We check if the cut is valid
      if(N - (i + 1) >= 0) {

        // We set the new maximum
        max_value = max(
            max_value,
            values[i] + cutting_rod(values, value_count, N - (i + 1), dp_table)
        );
      }
    }

    dp_table[value_count][N] = max_value;
    return max_value;
}