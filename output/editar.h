#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void editar() {
    FILE *archivo, *tempArchivo;
    char buffer[500];
    int indice2;
    struct inventario producto;
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

    printf(" Ingrese el índice del producto que desea editar: ");
    scanf("%d", &indice2);

    // Leer el contenido del archivo y escribir en el archivo temporal, editando el producto correspondiente
    while (fgets(buffer, sizeof(buffer), archivo)) {
        sscanf(buffer, "%d", &producto.indice);

        if (producto.indice == indice2) {
            printf("\nProducto encontrado:\n %s", buffer);
            printf("\nCategorías \n 1: Maquillaje para el rostro\n 2: Maquillaje para los ojos\n 3: Maquillaje para los labios \n ");
            printf(" Ingresa nueva categoria: ");
            scanf("%d", &producto.categoria);
            printf("  Ingrese nuevo nombre: ");
            scanf("%s", producto.nombreProducto);
            printf("  Ingrese nuevo precio: ");
            scanf("%f", &producto.precio);
            printf("  Ingrese nueva cantidad: ");
            scanf("%d", &producto.cantidad);

            // Formatear la nueva línea con la información actualizada
            char categoria[50];
            switch (producto.categoria)
            {
                case 1:
                    sprintf(categoria, "Maquillaje para el rostro");
                    break;
                case 2:
                    sprintf(categoria, "Maquillaje para los ojos");
                    break;
                case 3:
                    sprintf(categoria, "Maquillaje para los labios");
                    break;
                default:
                    sprintf(categoria, "Categoría desconocida");
                    break;
            }

            sprintf(buffer, "   %d      %s      %s     %.2f      %d\n", producto.indice, categoria, producto.nombreProducto, producto.precio, producto.cantidad);
            encontrado = 1;
        }

        fputs(buffer, tempArchivo);
    }

    fclose(archivo);
    fclose(tempArchivo);

    // Eliminar el archivo original y renombrar el temporal
    remove("Inventario.txt");
    rename("TempInventario.txt", "Inventario.txt");

    if (encontrado) {
        printf("Producto editado exitosamente.\n");
    } else {
        printf("Producto con índice %d no encontrado.\n", indice2);
    }
}
