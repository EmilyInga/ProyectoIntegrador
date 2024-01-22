#include <stdio.h>
 
int main() {

    char respuesta, dia;

    int horasDomingo, horasExtras;

    int minutos, horas, totalMinutos,horasCompletas;

    float costo, descuento = 0, total, pago, cambio,cambio2,pago2;
 
    do {

        printf("¿El tiempo que te quedaste incluye domingo? (S para Sí, N para No): ");

        scanf(" %c", &respuesta);
 
        if (respuesta == 'S' || respuesta == 's') {

            do {

                printf("Ingrese la cantidad de horas del Domingo (no puede ser negativo): ");

                scanf("%d", &horasDomingo);

            } while (horasDomingo < 0);
 
            do {

                printf("Ingrese la cantidad de horas extras (no puede ser negativo): ");

                scanf("%d", &horasExtras);

            } while (horasExtras < 0);
 
            float costoDomingo = (horasDomingo * 5 + 5) * 0.90;

            float costoExtras = horasExtras * 5 + 5;

            float costototal = costoDomingo + costoExtras;
          int totalhoras = horasDomingo + horasExtras;
printf("El total de horas que usaste el estacionamiento fue: %d\n", totalhoras);
            printf("Costo del domingo con descuento: $%.2f\n", costoDomingo);

            printf("Costo de horas extras: $%.2f\n", costoExtras);

            printf("Costo total: $%.2f\n", costototal);
 
            do {

                printf("Ingrese el monto pagado (no puede ser menor que el costo total): $");

                scanf("%f", &pago2);
 
                if (pago2 < costototal) {

                    printf("El monto pagado no puede ser menor que el costo total del estacionamiento. Por favor, ingrese un monto válido.\n");

                }

            } while (pago2 < costototal);
 
            cambio2 = pago2 - costototal;

            printf("Cambio a entregar: $%.2f\n\n",cambio2);

        } else {

            printf("Ingrese el día de la semana (D para Domingo, O para otros días): ");

            scanf(" %c", &dia);

            while (dia != 'D' && dia != 'd' && dia != 'O' && dia != 'o') {

                printf("Entrada no válida. Por favor, ingrese 'D' para Domingo o 'O' para otros días: ");

                scanf(" %c", &dia);

            }
 
            do {

                printf("Ingrese la cantidad de horas estacionado (no puede ser negativo): ");

                scanf("%d", &horas);

            } while (horas < 0);
 
            do {

                printf("Ingrese la cantidad de minutos adicionales (no puede ser negativo): ");

                scanf("%d", &minutos);

            } while (minutos < 0);
 
            totalMinutos = horas * 60 + minutos;
 
            if (totalMinutos <= 10) {

                costo = 0;

            } else if (totalMinutos <= 15) {

                costo = 3;

            } else if (totalMinutos <= 60) {

                costo = 10;

            } else {

               horasCompletas = (totalMinutos - 60) / 60;

                costo = 10 + horasCompletas * 5;

            }
 
            if (dia == 'D' || dia == 'd') {

                descuento = costo * 0.1;

            }
 
            total = costo - descuento;
printf("El total de horas que usaste el estacionamiento fue: %d\n", (int) horasCompletas+1);
            printf("\nTotal a pagar: $%.2f\n", total);
 
            do {

                printf("Ingrese el monto pagado (no puede ser menor que el costo total): $");

                scanf("%f", &pago);
 
                if (pago < total) {

                    printf("El monto pagado no puede ser menor que el costo total del estacionamiento. Por favor, ingrese un monto válido.\n");

                }

            } while (pago < total);
 
            cambio = pago - total;

            printf("Cambio a entregar: $%.2f\n\n", cambio);

        }
 
        printf("¿Desea realizar otro cálculo? (S para sí, cualquier otra tecla para salir): ");

        scanf(" %c", &respuesta);
 
    } while (respuesta == 'S' || respuesta == 's');
 
    return 0;

}
