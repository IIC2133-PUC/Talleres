#include <stdlib.h>
#include <stdio.h>
#define WAGON_COUNT 20
#define TRAIN_COUNT 10

typedef struct wagon_t {
    int id;
    int capacity;
    struct wagon_t *next;
} Wagon;

typedef struct train_t {
    int id;
    Wagon *first_wagon;
    Wagon *last_wagon;
} Train;


Train* create_train(int id) {
    Train* train = calloc(1, sizeof(Train));
    train->id = id;
    return train;
}

Wagon* create_wagon(int id, int capacity) {
    Wagon* wagon = calloc(1, sizeof(Wagon));
    wagon->id = id;
    wagon->capacity = capacity;
    return wagon;
}

void insertWagon(Train* train, Wagon* wagon) {
    if (train->first_wagon == NULL) {
        train->first_wagon = wagon;
    } else {
        train->last_wagon->next = wagon;
    }

    train->last_wagon = wagon;
}

void freeTrain(Train* train) {
    Wagon* wagon = train->first_wagon;

    while (wagon != NULL) {
        Wagon* next_wagon = wagon->next;
        free(wagon);
        wagon = next_wagon;
    }

    free(train);
}

int main() {
    Train** trains = calloc(TRAIN_COUNT, sizeof(Train*));

    for (int i = 0; i < TRAIN_COUNT; i++) {
        trains[i] = create_train(i);
    }

    for (int i = 0; i < TRAIN_COUNT; i++) {
        Train* train = trains[i];

        for (int j = 0; j < WAGON_COUNT; j++) {
            Wagon* wagon = create_wagon((j+1) * i, train->id);

            insertWagon(train, wagon);
        }
    }

    // Imprimir vagones en cada tren

    for (int i = 0; i < TRAIN_COUNT; i++) {
        Train* train = trains[i];
        Wagon* wagon = train->first_wagon;

        printf("Train %d: ", train->id);

        while (wagon != NULL) {
            printf("%d ->", wagon->id);
            wagon = wagon->next;
        }

        printf(" \n");
    }


    // Liberar memoria

    for (int i = 0; i < TRAIN_COUNT; i++) {
        freeTrain(trains[i]);
    }

    free(trains);

}