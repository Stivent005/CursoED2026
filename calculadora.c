#include <stdio.h>
#include "areas.h"
#include "volumenes.h"

int main() {

    int opcionMenu = 0;
    double dato1, dato2;

    while(opcionMenu != 5){

        printf("\n===== MENU DE CALCULOS =====\n");
        printf("1) Area del circulo\n");
        printf("2) Area del cuadrado\n");
        printf("3) Volumen de la esfera\n");
        printf("4) Volumen del cubo\n");
        printf("5) Salir\n");
        printf("Seleccione una opcion: ");

        scanf("%d", &opcionMenu);

        if(opcionMenu == 1){
            printf("Ingrese el radio del circulo: ");
            scanf("%lf", &dato1);

            double resultado = AreaC(dato1);
            printf("El area del circulo es: %.2lf\n", resultado);
        }

        else if(opcionMenu == 2){
            printf("Ingrese el primer lado: ");
            scanf("%lf", &dato1);

            printf("Ingrese el segundo lado: ");
            scanf("%lf", &dato2);

            double resultado = AreaCu(dato1, dato2);
            printf("El area del cuadrado es: %.2lf\n", resultado);
        }

        else if(opcionMenu == 3){
            printf("Ingrese el radio de la esfera: ");
            scanf("%lf", &dato1);

            double resultado = VolEsfera(dato1);
            printf("El volumen de la esfera es: %.2lf\n", resultado);
        }

        else if(opcionMenu == 4){
            printf("Ingrese el lado del cubo: ");
            scanf("%lf", &dato1);

            double resultado = VolCubo(dato1);
            printf("El volumen del cubo es: %.2lf\n", resultado);
        }

        else if(opcionMenu == 5){
            printf("Programa finalizado.\n");
        }

        else{
            printf("Opcion invalida. Intente nuevamente.\n");
        }
    }

    return 0;
}