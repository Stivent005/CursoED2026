#include <stdio.h>
#include "areas.h"
#include "volumenes.h"

int main(){
    int opcion;
    double x, y;

    do{
        printf("\n1. Calcular area de un circulo\n");
        printf("2. Calcular area de un cuadrado\n");
        printf("3. Calcular volumen de una esfera\n");
        printf("4. Calcular volumen de un cubo\n");
        printf("5. Salir\n");

        scanf("%d", &opcion);

        switch(opcion){

            case 1:
                printf("Escribe el radio: ");
                scanf("%lf", &x);
                printf("Area: %.2lf\n", AreaC(x));
                break;

            case 2:
                printf("Escribe lado 1: ");
                scanf("%lf", &x);
                printf("Escribe lado 2: ");
                scanf("%lf", &y);
                printf("Area: %.2lf\n", AreaCu(x, y));
                break;

            case 3:
                printf("Radio: ");
                scanf("%lf", &x);
                printf("Volumen: %.2lf\n", VolEsfera(x));
                break;

            case 4:
                printf("Lado: ");
                scanf("%lf", &x);
                printf("Volumen: %.2lf\n", VolCubo(x));
                break;

        }

    }while(opcion != 5);

    return 0;
}