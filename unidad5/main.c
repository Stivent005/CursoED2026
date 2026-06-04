/*
 * Sistema de Organizacion de Contenedores  
 *   - [Darin stiven angulo valencia]
 *   - [Edward stiven rodallega aeagon]
 *   - [Julio cesar balareso espinoza]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONTENEDORES 30

int pesos[MAX_CONTENEDORES];
int n = 0;
int ordenado = 0;

/* Prototipos */
void mostrarMenu();
void registrarManual();
void generarAleatorios();
void mostrarContenedores();
void shellSort();
void mergeSort(int arr[], int izq, int der);
void merge(int arr[], int izq, int mid, int der);
void quickSort(int arr[], int izq, int der);
int  particion(int arr[], int izq, int der);
void buscarBinario();
void swap(int *a, int *b);
void pausar();

/* MAIN */
int main() {
    srand(time(NULL));
    int opcion;

    do {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarManual();
                break;
            case 2:
                generarAleatorios();
                break;
            case 3:
                mostrarContenedores();
                break;
            case 4:
                if (n == 0) {
                    printf("\n  No hay contenedores registrados.\n");
                    pausar();
                } else {
                    shellSort();
                    ordenado = 1;
                    printf("\n  Contenedores ordenados con Shell Sort.\n");
                    mostrarContenedores();
                }
                break;
            case 5:
                if (n == 0) {
                    printf("\n  No hay contenedores registrados.\n");
                    pausar();
                } else {
                    mergeSort(pesos, 0, n - 1);
                    ordenado = 1;
                    printf("\n  Contenedores ordenados con Merge Sort.\n");
                    mostrarContenedores();
                }
                break;
            case 6:
                if (n == 0) {
                    printf("\n  No hay contenedores registrados.\n");
                    pausar();
                } else {
                    quickSort(pesos, 0, n - 1);
                    ordenado = 1;
                    printf("\n  Contenedores ordenados con Quick Sort.\n");
                    mostrarContenedores();
                }
                break;
            case 7:
                buscarBinario();
                break;
            case 8:
                printf("\n  Cerrando el sistema. Hasta pronto!\n\n");
                break;
            default:
                printf("\n  Opcion invalida. Intente de nuevo.\n");
                pausar();
        }

    } while (opcion != 8);

    return 0;
}

/* MENU */
void mostrarMenu() {
    system("cls");
    printf("\n");
    printf("  SISTEMA DE ORGANIZACION DE CONTENEDORES\n");
    printf("         MUELLE DE CARGA\n");
    printf("\n");
    printf("  Contenedores registrados : %d / %d\n", n, MAX_CONTENEDORES);
    printf("  Estado del arreglo       : %s\n", ordenado ? "ORDENADO" : "SIN ORDENAR");
    printf("\n");
    printf("  1. Registrar peso de contenedores manualmente\n");
    printf("  2. Generar pesos aleatorios de contenedores\n");
    printf("  3. Mostrar contenedores registrados\n");
    printf("  4. Ordenar contenedores - Shell Sort\n");
    printf("  5. Ordenar contenedores - Merge Sort\n");
    printf("  6. Ordenar contenedores - Quick Sort\n");
    printf("  7. Buscar contenedor (Busqueda Binaria)\n");
    printf("  8. Salir\n");
    printf("\n");
    printf("  Seleccione una opcion: ");
}

/* REGISTRO MANUAL */
void registrarManual() {
    int peso;

    printf("\n--- REGISTRO MANUAL ---\n");

    if (n >= MAX_CONTENEDORES) {
        printf("  El patio esta lleno (%d contenedores).\n", MAX_CONTENEDORES);
        pausar();
        return;
    }

    printf("  Ingrese el peso del contenedor %d (en kg): ", n + 1);
    scanf("%d", &peso);

    if (peso <= 0) {
        printf("  El peso debe ser un numero positivo.\n");
    } else {
        pesos[n] = peso;
        n++;
        ordenado = 0;
        printf("  Contenedor registrado: %d kg\n", peso);
    }

    pausar();
}

/* GENERAR ALEATORIOS */
void generarAleatorios() {
    int cantidad;

    printf("\n--- GENERACION ALEATORIA ---\n");

    int espacioDisponible = MAX_CONTENEDORES - n;
    if (espacioDisponible == 0) {
        printf("  El patio esta lleno.\n");
        pausar();
        return;
    }

    printf("  Espacio disponible: %d contenedor(es).\n", espacioDisponible);
    printf("  Cuantos pesos desea generar? ");
    scanf("%d", &cantidad);

    if (cantidad <= 0 || cantidad > espacioDisponible) {
        printf("  Cantidad invalida.\n");
        pausar();
        return;
    }

    printf("\n  Pesos generados:\n");
    for (int i = 0; i < cantidad; i++) {
        pesos[n] = (rand() % 29501) + 500;
        printf("    Contenedor %2d: %d kg\n", n + 1, pesos[n]);
        n++;
    }

    ordenado = 0;
    printf("\n  Se generaron %d contenedores.\n", cantidad);
    pausar();
}

/* MOSTRAR CONTENEDORES */
void mostrarContenedores() {
    printf("\n--- CONTENEDORES REGISTRADOS ---\n");

    if (n == 0) {
        printf("  (No hay contenedores aun)\n");
        pausar();
        return;
    }

    printf("  %-10s %-15s\n", "Posicion", "Peso (kg)");
    printf("  %-10s %-15s\n", "--------", "---------");

    for (int i = 0; i < n; i++) {
        printf("  %-10d %-15d\n", i + 1, pesos[i]);
    }

    printf("\n  Total: %d contenedor(es) | Estado: %s\n",
           n, ordenado ? "ORDENADO" : "SIN ORDENAR");
    pausar();
}

/* SHELL SORT */
void shellSort() {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = pesos[i];
            int j = i;
            while (j >= gap && pesos[j - gap] > temp) {
                pesos[j] = pesos[j - gap];
                j -= gap;
            }
            pesos[j] = temp;
        }
    }
}

/* 
   MERGE SORT
    */
void mergeSort(int arr[], int izq, int der) {
    if (izq < der) {
        int mid = izq + (der - izq) / 2;
        mergeSort(arr, izq, mid);
        mergeSort(arr, mid + 1, der);
        merge(arr, izq, mid, der);
    }
}

void merge(int arr[], int izq, int mid, int der) {
    int n1 = mid - izq + 1;
    int n2 = der - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[izq + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = izq;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

/* 
   QUICK SORT
    */
void quickSort(int arr[], int izq, int der) {
    if (izq < der) {
        int pi = particion(arr, izq, der);
        quickSort(arr, izq, pi - 1);
        quickSort(arr, pi + 1, der);
    }
}

int particion(int arr[], int izq, int der) {
    int pivote = arr[der];
    int i = izq - 1;

    for (int j = izq; j < der; j++) {
        if (arr[j] <= pivote) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[der]);
    return i + 1;
}

/* 
   BUSQUEDA BINARIA
    */
void buscarBinario() {
    printf("\n--- BUSQUEDA BINARIA ---\n");

    if (n == 0) {
        printf("  No hay contenedores registrados.\n");
        pausar();
        return;
    }

    if (!ordenado) {
        printf("  El arreglo NO esta ordenado.\n");
        printf("  Debe ordenarlo primero (opciones 4, 5 o 6).\n");
        pausar();
        return;
    }

    int objetivo;
    printf("  Ingrese el peso a buscar (en kg): ");
    scanf("%d", &objetivo);

    int izq = 0;
    int der = n - 1;
    int encontrado = -1;

    while (izq <= der) {
        int mid = izq + (der - izq) / 2;

        if (pesos[mid] == objetivo) {
            encontrado = mid;
            break;
        } else if (pesos[mid] < objetivo) {
            izq = mid + 1;
        } else {
            der = mid - 1;
        }
    }

    if (encontrado != -1) {
        printf("\n  Contenedor encontrado!\n");
        printf("  Peso     : %d kg\n", pesos[encontrado]);
        printf("  Posicion : %d\n", encontrado + 1);
    } else {
        printf("\n  No se encontro ningun contenedor con %d kg.\n", objetivo);
    }

    pausar();
}

/* 
   UTILIDADES
    */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pausar() {
    printf("\n  Presione Enter para continuar...");
    while (getchar() != '\n');
    getchar();
}
