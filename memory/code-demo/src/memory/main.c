#include <stdlib.h>
#include <stdio.h>

typedef struct my_struct_t {
    int a;
    int b;
} MyStruct;

MyStruct create_stack_struct() {
    MyStruct my_struct;
    my_struct.a = 10;
    my_struct.b = 20;
    return my_struct;
}

MyStruct *create_heap_struct() {
    MyStruct *my_struct = calloc(1, sizeof(MyStruct));
    my_struct->a = 10;
    my_struct->b = 20;
    return my_struct;
}

void modify_stack_struct(MyStruct my_struct) {
    my_struct.a = 100;
    my_struct.b = 200;
}

void modify_struct_with_pointer(MyStruct *my_struct) {
    my_struct->a = 100;
    my_struct->b = 200;
}

int main() {

    // 1. Memoria
    int number = 10;
    int *number_pointer = &number;

    printf("The value of number is: %d \n", number); // %d prints the value of the variable
    printf("The value of number_pointer is: %p \n", number_pointer); // %p prints the address of the pointer
    printf("The value of casted number_pointer is: %d \n", *number_pointer); // *Pointer seeks the value referenced by the pointer

    // 2. Porque trabajar con punteros?

    // 2.1 Stack
    MyStruct another_struct;
    another_struct.a = 10;
    another_struct.b = 20;

    modify_stack_struct(another_struct);

    printf("The value of my_struct.a is: %d \n", another_struct.a);
    printf("The value of my_struct.b is: %d \n", another_struct.b);


    // 2.2 Heap

    MyStruct* another_struct_for_pointer = create_heap_struct();
    another_struct_for_pointer->a = 10;
    another_struct_for_pointer->b = 20;

    modify_struct_with_pointer(another_struct_for_pointer);

    printf("The value of my_struct->a is: %d \n", another_struct_for_pointer->a);
    printf("The value of my_struct->b is: %d \n", another_struct_for_pointer->b);

    // Cuando una funcion recibe una valor de input, este valor es copiado en el stack de la funcion.
    // Por lo que cualquier modificacion que se haga a este valor dentro de la funcion, no afectara al valor original.
    // Para evitar esto, se puede pasar el puntero, de esa forma se copiara solo el puntero, lo que permitira acceder al valor original.
}