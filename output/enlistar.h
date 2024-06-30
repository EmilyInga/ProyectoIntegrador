#include <stdio.h>

void enlistar()
{
    FILE *Archivo;
    Archivo = fopen("Inventario.txt", "r");  // Abrir en modo lectura
    if (Archivo == NULL) 
    {
        printf("El archivo Inventario.txt no hay aún registro.\n");
        return;
    }
    else
    {
        char linea[500];
        printf("\nContenido del archivo Inventario.txt:\n");
        // fgets Lee una cadena de un archivo
        while (fgets(linea, sizeof(linea), Archivo)) 
        {
            printf("%s", linea);
        }
        printf("\n");
        
        fclose(Archivo);
    }
}
