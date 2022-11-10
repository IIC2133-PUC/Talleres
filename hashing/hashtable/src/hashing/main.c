#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashtable.h"


// Problem:
// Given N pairs (id, ammount)
// Given a set of M Queries by id
// Return the sum of all ammounts of that id
// Restriction: There are ids > N

int main(int argc, char **argv) {
    int N, M;

    FILE* transactions = fopen(argv[1], "r");
    FILE* queries = fopen(argv[2], "r");
    FILE* output_file = fopen(argv[3], "w");

    // Para ajustar del dominio D de ids a la tabla de tamaño N
    // Simplemente utilizaremos el operador modulo (%)
    // Importante notar que existen muchas mejores formas de realizarlo. Esta es la forma naive

    fscanf(transactions, "%d", &N);

    HashItem **table = calloc(N, sizeof(HashItem*));
    int id, ammount;
    for (int i = 0; i < N; i++) {
        fscanf(transactions, "%d %d", &id, &ammount);
        insert_or_update(table, id, ammount, N);
    }

    fscanf(queries, "%d", &M);
    int id_query, result;
    for (int i = 0; i < M; i++) {
        fscanf(queries, "%d", &id_query);
        result = fetch_value(table, id_query, N);
        fprintf(output_file, "%d\n", result);
    }
}