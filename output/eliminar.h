#include <stdio.h>
#include <stdlib.h>

void eliminar() {
    FILE *archivo, *tempArchivo;
    int indice2;
    int indiceProducto;
    char buffer[500];
    int encontrado = 0;

    // Abrir el archivo original para lectura
    archivo = fopen("Inventario.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo Inventario.txt no hay registro\n");
        return;
    }

    // Crear un archivo temporal para escritura
    tempArchivo = fopen("TempInventario.txt", "w");
    if (tempArchivo == NULL) {
        printf("Error al crear el archivo temporal\n");
        fclose(archivo);
        return;
    }

    printf("Ingrese el índice del producto que desea eliminar: ");
    scanf("%d", &indice2);

    // Leer y escribir el contenido del archivo, excluyendo el producto a eliminar
    while (fgets(buffer, sizeof(buffer), archivo)) {
        sscanf(buffer, "%d", &indiceProducto);
        if (indiceProducto != indice2) {
            fputs(buffer, tempArchivo);
        } else {
            encontrado = 1;
        }
    }

    fclose(archivo);
    fclose(tempArchivo);

    // Eliminar el archivo original y renombrar el temporal
    remove("Inventario.txt");
    rename("TempInventario.txt", "Inventario.txt");

    if (encontrado) {
        printf("Producto eliminado exitosamente.\n");
    } else {
        printf("Producto con índice %d no encontrado.\n", indice2);
    }
}
