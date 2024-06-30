#include <stdio.h>
#include <stdlib.h> //para funciones de utilidad
#include <string.h> //para manejo de cadenas 


void editar() 
{
    FILE *Archivo;
    char buffer[500];
    int indice2; 
    struct inventario producto;
    
    int encontrado = 0; 
    
    // Abrir el archivo original para leer y escribir 
    Archivo = fopen("Inventario.txt", "r+");
    if (Archivo == NULL)
    {
        printf("Error al abrir el archivo Inventario.txt no hay registro\n");
        return;
    }
    
    // Leer el contenido del archivo en memoria 
    char lineas[100][500]; // límite máximo de productos[100]
    int totalProductos = 0;
    
    while (fgets(lineas[totalProductos], sizeof(buffer), Archivo)) {
        totalProductos++;
    }
    
    printf("Ingrese el índice del producto que desea editar: ");
    scanf("%d", &indice2);
    
    // Buscar y editar el producto en memoria 
    for (int i = 1; i < totalProductos; i++) { // i comienza en 1 para saltar el encabezado
        sscanf(lineas[i], "%d", &producto.indice);
        
        if (producto.indice == indice2) {
            printf("\nProducto encontrado: %s", lineas[i]);
            printf("\nIngrese nueva categoría (1: Maquillaje para el rostro\n2: Maquillaje para los ojos\n3: Maquillaje para los labios)\n");
            scanf("%d", &producto.categoria);
            printf("\nIngrese nuevo nombre: ");
            scanf("%s", producto.nombreProducto);
            printf("\nIngrese nuevo precio: ");
            scanf("%f", &producto.precio);
            printf("\nIngrese nueva cantidad: ");
            scanf("%d", &producto.cantidad);
            
            // Actualizar la línea correspondiente
            sprintf(lineas[i], "%d ", producto.indice); // Asegurar que el índice se incluya
            if (producto.categoria == 1) {
                strcat(lineas[i], "Maquillaje para el rostro \t");
            } else if (producto.categoria == 2) {
                strcat(lineas[i], "Maquillaje para los ojos \t");
            } else if (producto.categoria == 3) {
                strcat(lineas[i], "Maquillaje para los labios \t"); 
            }
            
            char temp[500];
            sprintf(temp, "%s %.2f %d\n", producto.nombreProducto, producto.precio, producto.cantidad);
            strcat(lineas[i], temp); // Concatenar el resto de la información
            
            encontrado = 1; 
            break;
        }
    }
    
    if (!encontrado) {
        printf("Producto con índice %d no encontrado.\n", indice2);
        fclose(Archivo);
        return;
    }
    
    freopen("Inventario.txt", "w", Archivo); // Abrir el archivo en modo escritura para sobreescribirlo
    for (int i = 0; i < totalProductos; i++) {
        fputs(lineas[i], Archivo);
    }
    
    fclose(Archivo);
    printf("Producto editado exitosamente.\n");
}
