#include <stdio.h>
#include <stdint.h>
#include <math.h>

void displayMenu() {
    printf("Seleccione una opción:\n");
    printf("1. Sumar dos números\n");
    printf("2. Restar dos números\n");
    printf("3. Multiplicar dos números\n");
    printf("4. Dividir dos números\n");
}

int main() {
    uint32_t select;
    int32_t num1, num2;

    displayMenu();

    if (scanf("%u", &select) != 1) {
        printf("Entrada inválida. Por favor, ingrese un número válido.\n");
        return 1;
    }

    switch(select) {
        case 1:
            printf("Introduce dos números: ");
            if (scanf("%d %d", &num1, &num2) != 2) {
                printf("Entrada inválida.\n");
                break;
            }
            printf("Resultado: %d\n", num1 + num2);
            break;
        case 2:
            printf("Introduce dos números: ");
            if (scanf("%d %d", &num1, &num2) != 2) {
                printf("Entrada inválida.\n");
                break;
            }
            printf("Resultado: %d\n", num1 - num2);
            break;
        case 3:
            printf("Introduce dos números: ");
            if (scanf("%d %d", &num1, &num2) != 2) {
                printf("Entrada inválida.\n");
                break;
            }
            printf("Resultado: %d\n", num1 * num2);
            break;
        case 4:
            printf("Introduce dos números: ");
            if (scanf("%d %d", &num1, &num2) != 2) {
                printf("Entrada inválida.\n");
                break;
            }
            if (num2 == 0) {
                printf("Error: División por cero no permitida.\n");
            } else {
                printf("Resultado: %d\n", num1 / num2);
            }
            break;
        default:
            printf("Opción no válida.\n");
    }

    return 0;
}

