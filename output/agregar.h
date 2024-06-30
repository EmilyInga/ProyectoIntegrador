#include <stdio.h>

extern int veces;
int acu = 0;
int currentIndex = 1; // Starting index for products

struct inventario {
    int indice;
    int categoria;
    char nombreProducto[30];
    float precio;
    int cantidad;
} producto;

void agregar() {
    int i, numeroProductos;
    FILE *Archivo;
    Archivo = fopen("Inventario.txt", "a");
    if (Archivo == NULL) {
        printf("Error al abrir el archivo Inventario.txt no hay registro\n");
        return;
    }

    if (veces == 1) {
        fprintf(Archivo, "\n\n");
        fprintf(Archivo, " Indice Categoria                    Nombre   Precio  Cantidad\n");
    }

    printf("\n");
    printf(" Agregando productos\n");
    printf(" Cuantos productos vas a ingresar: ");
    scanf("%d", &numeroProductos);
    acu += numeroProductos;

    for (int i = 0; i < numeroProductos; i++) {
        producto.indice = currentIndex++;

        printf("\n");
        printf(" Categoria del producto %d:\n ", i + 1);
        printf("\n1: Maquillaje para el rostro\n2: Maquillaje para los ojos\n3: Maquillaje para los labios\n");
        printf("Ingresa la categoria: ");
        scanf("%d", &producto.categoria);
        if (producto.categoria == 1) {
            fprintf(Archivo, " %d Maquillaje para el rostro \t", producto.indice);
        } else if (producto.categoria == 2) {
            fprintf(Archivo, " %d Maquillaje para los ojos  \t", producto.indice);
        } else if (producto.categoria == 3) {
            fprintf(Archivo, " %d Maquillaje para los labios\t", producto.indice);
        }

        printf(" Nombre del producto %d: ", i + 1);
        scanf("%s", producto.nombreProducto);
        printf(" Nombre es: %s\n", producto.nombreProducto);
        printf(" Precio del producto %d: ", i + 1);
        scanf("%f", &producto.precio);
        printf(" Precio es: %.2f\n", producto.precio);
        printf(" Cantidad del producto %d: ", i + 1);
        scanf("%d", &producto.cantidad);
        printf(" Cantidad del producto: %d\n", producto.cantidad);

        fprintf(Archivo, " %s %.2f %d\n", producto.nombreProducto, producto.precio, producto.cantidad);
    }

    fclose(Archivo);
}
