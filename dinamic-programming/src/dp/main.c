#include <stdio.h>
#include <stdlib.h>
#include "cutting_rod.h"

int main(int argc, char** argv)
{
  if(argc != 2)
  {
    printf("Modo de uso: %s input\nDonde:\n", argv[0]);
    printf("\t\"input\" es la ruta al archivo de input\n");
    return 1;
  }

  // Abrimos el archivo de input
  FILE* input_stream = fopen(argv[1], "r");

  // Si alguno de los dos archivos no se pudo abrir
  if(!input_stream)
  {
    printf("El archivo %s no existe o no se puede leer\n", argv[1]);
    return 2;
  }

  // Read value table
  int value_count;
  fscanf(input_stream, "%d", &value_count);

  int* values = calloc(value_count, sizeof(int));

  for(int i = 0; i < value_count; i++)
  {
    fscanf(input_stream, "%d", &values[i]);
  }

  // Read rod size
  int rod_size;
  fscanf(input_stream, "%d", &rod_size);

  // instanciates the dynamic table
  int** dp_table = create_dynamic_table(value_count + 1, rod_size + 1);
  int max_value = cutting_rod(values, value_count, rod_size, dp_table);

  printf("Dado un Rod de tamaño %d y los siguientes valores:\n", rod_size);
  for(int i = 0; i < value_count; i++)
  {
    printf("\t%d: %d\n", i + 1, values[i]);
  }

  printf("\n");
  printf("El valor maximo que se puede obtener es: %d\n", max_value);

  // Cerrar archivo de input
  fclose(input_stream);

  return 0;
}
