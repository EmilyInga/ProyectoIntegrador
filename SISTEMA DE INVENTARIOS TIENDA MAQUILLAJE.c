#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100

typedef struct {
    char nombre[50];
    int categoria;
    float precio;
    int cantidad;
} Producto;

int totalProductos = 0;
Producto inventario[MAX_PRODUCTS];

void ingresarProducto();
void editarProducto();
void eliminarProducto();
void listarProductos();

int main() {
    int opcion;

    do {
        printf("\nMenu de opciones:\n");
        printf("1. Ingresar un nuevo producto\n");
        printf("2. Editar un producto existente\n");
        printf("3. Eliminar un producto\n");
        printf("4. Listar productos ingresados\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarProducto();
                break;
            case 2:
                editarProducto();
                break;
            case 3:
                eliminarProducto();
                break;
            case 4:
                listarProductos();
                break;
            case 5:
                printf("Fin del programa...\n");
                break;
            default:
                printf("Opción no válida, por favor intente de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}

void ingresarProducto() {
    // Aquí controla el máximo de los produtos.
    if (totalProductos < MAX_PRODUCTS) {
        printf("\nIngresar nombre del producto: ");
        scanf("%s", inventario[totalProductos].nombre);
        printf("Ingresar categoria del producto\n");
        printf(" 1: Maquillaje para el rostro \n 2: Maquillaje para los ojos\n 3: Maquillaje para los labios\n ");
        scanf("%d", &inventario[totalProductos].categoria);
        printf("Ingresar precio del producto: ");
        scanf("%f", &inventario[totalProductos].precio);
        printf("Ingresar cantidad en stock: ");
        scanf("%d", &inventario[totalProductos].cantidad);
        totalProductos++;
        printf("\nProducto ingresado correctamente.\n");
    } else {
        printf("\nNo se puede ingresar más productos, inventario lleno.\n");
    }
}

void editarProducto() {
    int orden;
    printf("Ingrese el índice del producto a editar (0 a %d): ", totalProductos - 1);
    scanf("%d", &orden);

    if (orden >= 0 && orden < totalProductos) {
        printf("Ingresar nuevo nombre del producto: ");
        scanf("%s", inventario[orden].nombre);
        printf("Ingresar nueva categoria del producto: ");
        scanf("%d", &inventario[orden].categoria);
        printf("Ingresar nuevo precio del producto: ");
        scanf("%f", &inventario[orden].precio);
        printf("Ingresar nueva cantidad en stock: ");
        scanf("%d", &inventario[orden].cantidad);
        printf("Producto editado correctamente.\n");
    } else {
        printf("Índice de producto no válido, no hay productos existentes.\n");
    }
}

void eliminarProducto() {
    int orden;
    printf("Ingrese el índice del producto a eliminar (0 a %d): ", totalProductos - 1);
    scanf("%d", &orden);

    if (orden >= 0 && orden < totalProductos) {
        for (int i = orden; i < totalProductos - 1; i++) {
            inventario[i] = inventario[i + 1];
        }
        totalProductos--;
        printf("Producto eliminado correctamente.\n");
    } else {
        printf("Índice de producto no válido.\n");
    }
}

void listarProductos() {
    printf("\nListado de productos:\n");
    printf("Indice  Nombre            Categoria              Precio      Cantidad\n");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < totalProductos; i++) {
        printf("  %d     %s   ", i, inventario[i].nombre);
        if (inventario[i].categoria == 1) {
            printf("  Maquillaje para el rostro\t");
        } else if (inventario[i].categoria == 2) {
            printf("  Maquillaje para los ojos\t");
        } else if (inventario[i].categoria == 3) {
            printf("  Maquillaje para los labios\t");
        }
        printf("  %.2f          %d\n", inventario[i].precio, inventario[i].cantidad);
    }
}