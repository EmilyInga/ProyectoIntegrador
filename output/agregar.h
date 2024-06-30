
#include <stdio.h>

// el extern sirve para usar un valor de una variable de otra función
extern int veces;
//este acu nos va ayudar a registrar el número de productos
int acu = 0;
// este indice1 nos va a ayudar a inicializar el indice
int indice1 = 1; 

// definir una estructura con los datos del producto
struct inventario {
    int indice;
    int categoria;
    char nombreProducto[30];
    float precio;
    int cantidad;
} producto;

void agregar() {
    int i, numeroProductos;
    //aqui definimos el archivo
    FILE *Archivo;
    // busca el archivo y si no hay se crea
    Archivo = fopen("Inventario.txt", "a");
    if (Archivo == NULL) {
        printf("Error al abrir el archivo Inventario.txt no hay registro\n");
        // regresa al main 
        return;
    }
    
    // si veces es 1 va imprimir el encabezado

    if (veces == 1) {
        fprintf(Archivo, "\n\n");
        fprintf(Archivo, " Indice   Categoria                     Nombre    Precio     Cantidad\n");
    }
    
    // Pide los datos

    printf("\n");
    printf(" Agregando productos\n");
    printf(" Cuantos productos vas a ingresar: ");
    scanf("%d", &numeroProductos);
    
    //acumula el numero de productos
    acu += numeroProductos;
    
    //el for nos ayuda a imprimir la informacion de la cantidad de productos ingresados
    for (int i = 0; i < numeroProductos; i++) {
        // por cada iteracion de i se almacena el indice y aumenta en 1
        producto.indice = indice1++;
        printf("\n");
        printf(" Categoria del producto %d:\n ", i + 1);
        printf("\n1: Maquillaje para el rostro\n2: Maquillaje para los ojos\n3: Maquillaje para los labios\n");
        printf("Ingresa la categoria: ");
        scanf("%d", &producto.categoria);
        //depende de la categoria elegida imprime en el archivo 
        // fprintf imprime en el archivo
        // printf imprime en la consola
        if (producto.categoria == 1) {
            fprintf(Archivo, "   %d      Maquillaje para el rostro", producto.indice);
        } else if (producto.categoria == 2) {
            fprintf(Archivo, "   %d      Maquillaje para los ojos  \t", producto.indice);
        } else if (producto.categoria == 3) {
            fprintf(Archivo, "   %d      Maquillaje para los labios\t", producto.indice);
        }
        printf(" Nombre del producto %d: ", i + 1);
        scanf("%s", producto.nombreProducto);
        printf(" Precio del producto %d: ", i + 1);
        scanf("%f", &producto.precio);
        printf(" Cantidad del producto %d: ", i + 1);
        scanf("%d", &producto.cantidad);
        fprintf(Archivo, " %s     %.2f         %d\n", producto.nombreProducto, producto.precio, producto.cantidad);
    }

    fclose(Archivo);
}
