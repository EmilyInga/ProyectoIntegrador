#include <stdio.h>
#include <string.h>
//Incluimos los headers
#include "agregar.h"
#include "editar.h"
#include "enlistar.h"
#include "eliminar.h"
//declarar e inicializar en 0 veces
int veces =1;

int main(){
    int opcion, irMenu;
    printf("\n\n");
    printf("\t\t INVENTARIO Cosmética saludable \t\n");
    do{
        do{
            //imprime el menu
            printf("\n");
            printf(" Actividades\t\n");
            printf(" 1. Agregar  productos \n");
            printf(" 2. Editar   productos \n");
            printf(" 3. Eliminar productos \n");
            printf(" 4. Enlistar productos \n");
            printf(" Que actividad vas a realizar: ");
            scanf("%d",&opcion);
            //controla que entre 1-4
        }while(opcion<0 || opcion>4);
        
        //dirige al header
        switch(opcion){
        case 1:
        agregar();
        // este veces va a marcar las veces que ingresa a agregar productos
        // para que el encabezado se imprima solo la primera vez
        veces ++;
        break;
        case 2:
        editar();
        break;
        case 3:
        eliminar();
        break;
        case 4:
        enlistar();
        break;
        }
        // permite que realice mas actividades
        printf("Desea realizar otra actividad si(1) o no (2):");
        scanf ("%d",&irMenu);
        
        //controla que si es 2 sale del programa
    } while(irMenu==1);

    return 0;
    
}
