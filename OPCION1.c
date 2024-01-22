#include <stdio.h>
#include <locale.h>

int main() {
    setlocale (LC_ALL, "") ;
    int hora_entrada, minutos_entrada, hora_salida, minutos_salida, hora_total, minuto_total;
    int sum_entrada_horas, sum_minen;
    float total, pago, min_domingo = 0;
    char repeat, respuesta, domingo, dia, undomingo;

    do {
        // Ingrese hora entrada
        do {
            printf("Ingrese hora de entrada (formato 24 horas): ");
            scanf("%d", &hora_entrada);

            if (hora_entrada < 0 || hora_entrada > 24) {
                printf("Por favor, ingrese una hora válida .\n");
            }

        } while (hora_entrada < 0 || hora_entrada > 23);

        // Ingrese minutos entrada
        do {
            printf("Ingrese minutos de entrada: ");
            scanf("%d", &minutos_entrada);

            if (minutos_entrada < 0 || minutos_entrada > 59) {
                printf("Por favor, ingrese minutos válidos (entre 0 y 59).\n");
            }

        } while (minutos_entrada < 0 || minutos_entrada > 59);

        // Ingrese hora salida
        do {
            printf("Ingrese hora de salida (formato 24 horas): ");
            scanf("%d", &hora_salida);

            if (hora_salida < 0 || hora_salida > 23) {
                printf("Por favor, ingrese una hora válida ).\n");
            }
        } while (hora_salida < 0 || hora_salida > 23);

        // Ingrese minutos salida
        do {
            printf("Ingrese minutos de salida: ");
            scanf("%d", &minutos_salida);

            if (minutos_salida < 0 || minutos_salida > 59) {
                printf("Por favor, ingrese minutos válidos (entre 0 y 59).\n");
            }

        } while (minutos_salida < 0 || minutos_salida > 59);

        // Te quedaste mas de un dia
        do {
            printf("¿Te quedaste más de 1 día? (s/n): ");
            scanf(" %c", &respuesta);

            if (respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N') {
                printf("Datos ingresados incorrectos. Elige (s) para sí o (n) no.\n");
            }

        } while (respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N');

        // hora de salida no puede ser menor a la de entrada

        if (hora_salida < hora_entrada && respuesta == 'n' || respuesta == 'N')
        {
            printf("Te quedaste 1 día, la hora de salida no puede ser menor a la de entrada\n");
            break;
        }

        //si si se quedo un dia

        if (respuesta == 's' || respuesta == 'S')
        {
            int tiempo_hasta_medianoche = (24 * 60) - (hora_entrada * 60 + minutos_entrada);


            sum_entrada_horas = tiempo_hasta_medianoche / 60;
            sum_minen = tiempo_hasta_medianoche % 60;

            printf("Total horas estacionado del primer día: %d horas con %d minutos\n", sum_entrada_horas, sum_minen);
            printf("Total horas estacionado del segundo día: %d horas con %d minutos\n", hora_salida, minutos_salida);
           // incluye domingo
            printf("¿De los días que te quedaste, incluye domingo? (S/N) \n");
            scanf(" %c", &domingo);

            // si si incluye domingo 1 02

            if (domingo == 's' || domingo == 'S') {
                do {
                    printf("Día 1 es domingo o día 2 es domingo (1/2)\n");
                    scanf(" %c", &dia);

                    if (dia != '1' && dia != '2') {
                        printf("Por favor, ingrese un dígito válido. Solo pueden ser 1 y 2.\n");
                    }

                } while (dia != '1' && dia != '2');

               //domingo dia 1
                if (dia == '1') {
                    printf("Total horas estacionado del domingo: %d horas con %d minutos\n", sum_entrada_horas, sum_minen);
                     int dia1;

                    dia1=sum_entrada_horas*60+sum_minen;
                    printf("Minutos totales: %d\n", dia1);
                    float costof;
                    int gratis = 0, min15 = 3, min60 = 10;

                    if (dia1 >= 0 && dia1 <= 10)
                    costof = gratis;
                    else if (dia1 >= 11 && dia1 <= 15)
                    costof = min15;
                    else if (dia1 >= 16 && dia1 <= 60)
                    costof = min60;
                    else if (dia1 >= 61)
                    costof = 10 + ((dia1 - 60) / 60) * 5;

                   int minutos_adicionales = (dia1 - 60) % 60;
                    if (minutos_adicionales > 0 && minutos_adicionales <= 15)
                   costof += min15;
                    else if (minutos_adicionales > 15)
                    costof += min60;
                    float descuento,descuento_monto ,costo_con_descuento;
                    // Muestra el costo total
                   printf("Costo total: $%.2f\n",(float)costof);
                   descuento=0.10;
                   descuento_monto= costof*descuento;
                   costo_con_descuento= costof-descuento_monto;

                  printf("Costo total con descuento: $%.2f\n",(float)costo_con_descuento);
                  float dinero, a_pagar;
                  do {
                    printf("Ingrese valor con el que vas a pagar: ");
                    scanf("%f", &dinero);
                  if (dinero < costo_con_descuento) {
                     printf("El dinero ingresado es insuficiente. Intente de nuevo.\n");
                    }

                    } while (dinero < costo_con_descuento);
                    a_pagar = dinero - costo_con_descuento;

                     printf("Cambio a devolver: $%.2f\n", a_pagar);


                  //domingo dia 2
                } else if (dia == '2') {
                    printf("Total horas estacionado del domingo: %d horas con %d minutos\n", hora_salida, minutos_salida);
                    int dia2;
                    dia2=hora_salida*60+minutos_salida;
                    printf("Minutos totales: %d\n", dia2);
                    float costof;
                    int gratis = 0, min15 = 3, min60 = 10;

                    if (dia2 >= 0 && dia2 <= 10)
                    costof = gratis;
                    else if (dia2 >= 11 && dia2 <= 15)
                    costof = min15;
                    else if (dia2 >= 16 && dia2 <= 60)
                    costof = min60;
                    else if (dia2 >= 61)
                    costof = 10 + ((dia2 - 60) / 60) * 5;

                   int minutos_adicionales = (dia2 - 60) % 60;
                    if (minutos_adicionales > 0 && minutos_adicionales <= 15)
                   costof += min15;
                    else if (minutos_adicionales > 15)
                    costof += min60;
                    float descuento,descuento_monto ,costo_con_descuento;
                    // Muestra el costo total
                   printf("Costo total: $%.2f\n",(float)costof);
                   descuento=0.10;
                   descuento_monto= costof*descuento;
                   costo_con_descuento= costof-descuento_monto;

                  printf("Costo total con descuento: $%.2f\n",(float)costo_con_descuento);
                    float dinero, a_pagar;
                  do {
                    printf("Ingrese valor con el que vas a pagar: ");
                    scanf("%f", &dinero);
                  if (dinero < costo_con_descuento) {
                     printf("El dinero ingresado es insuficiente. Intente de nuevo.\n");
                    }

                    } while (dinero < costo_con_descuento);
                    a_pagar = dinero - costo_con_descuento;

                     printf("Cambio a devolver: $%.2f\n", a_pagar);


                }
            } else {
                //se quedo mas de dos dias y no incluye domingo
                int sum_entrada_horas = tiempo_hasta_medianoche / 60;
                int sum_minen = tiempo_hasta_medianoche % 60;
                int minutosdia1 = sum_entrada_horas * 60 + sum_minen;
                int minutosdia2 = hora_salida * 60 + minutos_salida;

                printf("Total minutos del primer dia: %d\n", minutosdia1);
                printf("Total minutos del segundo día: %d\n", minutosdia2);


                int undia;
                undia=minutosdia1+minutosdia2;

                printf("Minutos totales: %d\n", undia);
                float horas,h;
                h=undia/60;
                horas=undia %60;

            printf("Total horas estacionado de los dias: %2.f horas con %2.f minutos\n", h,horas);

                float costof;
                int gratis = 0, min15 = 3, min60 = 10;

                if (undia >= 0 && undia <= 10)
                costof = gratis;
                else if (undia >= 11 && undia <= 15)
                costof = min15;
                else if (undia >= 16 && undia <= 60)
                costof = min60;
                else if (undia >= 61)
               costof = 10 + ((undia - 60) / 60) * 5;

               int minutos_adicionales = undia % 60;
               if (minutos_adicionales > 0 && minutos_adicionales <= 15)
                   costof += min15;
               else if (minutos_adicionales > 15)
               costof += min60;

               // Muestra el costo total
            printf("Costo total: $%.2f\n", (float)costof);
                 float dinero, a_pagar;
            do {
            printf("Ingrese valor con el que vas a pagar: ");
            scanf("%f", &dinero);
            if (dinero < costof) {
            printf("El dinero ingresado es insuficiente. Intente de nuevo.\n");
             }

            } while (dinero < costof);
             a_pagar = dinero - costof;

            printf("Cambio a devolver: $%.2f\n", a_pagar);

            }


        } else {
            //si no se quedo mas de un dia
            int undia,horadia, minutodia;
            undia= (hora_salida*60+minutos_salida)-(hora_entrada*60+minutos_entrada);
            horadia= undia/60;
            minutodia= undia% 60;
            // horas si solo se quedo un dia
            printf("Total horas estacionado : %d horas con %d minutos\n", horadia, minutodia);

            // El día que te quedaste  fue domingo
            do {
                printf("¿El día que te quedaste fue domingo? (S/N): ");
                scanf(" %c", &undomingo);

            if (undomingo != 's' && undomingo != 'S'&& undomingo != 'n' && undomingo != 'N') {
                    printf("Por favor, ingrese una respuesta válida (S/N).\n");}

            } while (undomingo != 's' && undomingo != 'S' && undomingo != 'n' && undomingo != 'N');

            if (undomingo=='s' || undomingo =='S'){
                //calculo normal y descuento

             int undia = (hora_salida * 60 + minutos_salida) - (hora_entrada * 60 + minutos_entrada);
             printf("Minutos totales: %d\n", undia);
             float costof;
             int gratis = 0, min15 = 3, min60 = 10;

            if (undia >= 0 && undia <= 10)
              costof = gratis;
            else if (undia >= 11 && undia <= 15)
             costof = min15;
            else if (undia >= 16 && undia <= 60)
             costof = min60;
            else if (undia >= 61)
             costof = 10 + ((undia - 60) / 60) * 5;

            int minutos_adicionales = (undia - 60) % 60;
            if (minutos_adicionales > 0 && minutos_adicionales <= 15)
               costof += min15;
            else if (minutos_adicionales > 15)
            costof += min60;
             float descuento,descuento_monto ,costo_con_descuento;
            // Muestra el costo total
            printf("Costo total: $%.2f\n",(float)costof);
            descuento=0.10;
            descuento_monto= costof*descuento;
            costo_con_descuento= costof-descuento_monto;

            printf("Costo total con descuento: $%.2f\n",(float)costo_con_descuento);
            float dinero, a_pagar;
                  do {
                    printf("Ingrese valor con el que vas a pagar: ");
                    scanf("%f", &dinero);
                  if (dinero < costo_con_descuento) {
                     printf("El dinero ingresado es insuficiente. Intente de nuevo.\n");
                    }

                    } while (dinero < costo_con_descuento);
                    a_pagar = dinero - costo_con_descuento;

                     printf("Cambio a devolver: $%.2f\n", a_pagar);


            }else{
                //calculo normal
             int undia = (hora_salida * 60 + minutos_salida) - (hora_entrada * 60 + minutos_entrada);
             printf("Minutos totales: %d\n", undia);
             float costof;
             int gratis = 0, min15 = 3, min60 = 10;

            if (undia >= 0 && undia <= 10)
              costof = gratis;
            else if (undia >= 11 && undia <= 15)
             costof = min15;
            else if (undia >= 16 && undia <= 60)
             costof = min60;
            else if (undia >= 61)
             costof = 10 + ((undia - 60) / 60) * 5;
            int minutos_adicionales = (undia - 60) % 60;
            if (minutos_adicionales > 0 && minutos_adicionales <= 15)
               costof += min15;
            else if (minutos_adicionales > 15)
            costof += min60;
            // Muestra el costo total
            printf("Costo total: $%.2f\n", (float)costof);
            float dinero, a_pagar;
            do {
            printf("Ingrese valor con el que vas a pagar: ");
            scanf("%f", &dinero);
            if (dinero < costof) {
            printf("El dinero ingresado es insuficiente. Intente de nuevo.\n");
             }

            } while (dinero < costof);
             a_pagar = dinero - costof;

            printf("Cambio a devolver: $%.2f\n", a_pagar);

            }
        }
        printf("Quiere segir calculando? (s/n): ");
        scanf(" %c", &repeat);
    } while (repeat == 'S' || repeat == 's');
    return 0;
}
