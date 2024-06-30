#include <stdio.h>
#include <string.h>
#include "agregar.h"
#include "editar.h"
#include "enlistar.h"
#include "eliminar.h"
int veces =1;

int main(){
    int opcion, irMenu;
    printf("\n\n");
    printf("\t\t INVENTARIO TIENDA MAKE UP \t\n");
    do{
        do{
            printf("\n");
            printf(" Actividades\t\n");
            printf(" 1. Agregar  productos \n");
            printf(" 2. Editar   productos \n");
            printf(" 3. Eliminar productos \n");
            printf(" 4. Enlistar productos \n");
            printf(" Que actividad vas a realizar: ");
            scanf("%d",&opcion);
            
        }while(opcion<0 || opcion>4);
        
        switch(opcion){
        case 1:
        agregar();
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
        printf("Desea realizar otra actividad si(1) o no (2):");
        scanf ("%d",&irMenu);
    } while(irMenu==1);

    return 0;
    
}
