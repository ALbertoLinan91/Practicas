#include <stdio.h>
#include <stdint.h>
#include <math.h>

void displayMenu() {
    printf("Seleccione una opci�n:\n");
    printf("1. Sumar dos n�meros\n");
    printf("2. Restar dos n�meros\n");
    printf("3. Multiplicar dos n�meros\n");
    printf("4. Dividir dos n�meros\n");
}

int main() {
    uint32_t select;
    int32_t num1, num2;

    displayMenu();

    if (scanf("%u", &select) != 1) {
        printf("Entrada inv�lida. Por favor, ingrese un n�mero v�lido.\n");
        return 1;
    }

    switch(select) {
        case 1:
            printf("Introduce dos n�meros: ");
            if (scanf("%d %d", &num1, &num2) != 2) {
                printf("Entrada inv�lida.\n");
                break;
            }
            printf("Resultado: %d\n", num1 + num2);
            break;
        case 2:
            printf("Introduce dos n�meros: ");
            if (scanf("%d %d", &num1, &num2) != 2) {
                printf("Entrada inv�lida.\n");
                break;
            }
            printf("Resultado: %d\n", num1 - num2);
            break;
        case 3:
            printf("Introduce dos n�meros: ");
            if (scanf("%d %d", &num1, &num2) != 2) {
                printf("Entrada inv�lida.\n");
                break;
            }
            printf("Resultado: %d\n", num1 * num2);
            break;
        case 4:
            printf("Introduce dos n�meros: ");
            if (scanf("%d %d", &num1, &num2) != 2) {
                printf("Entrada inv�lida.\n");
                break;
            }
            if (num2 == 0) {
                printf("Error: Divisi�n por cero no permitida.\n");
            } else {
                printf("Resultado: %d\n", num1 / num2);
            }
            break;
        default:
            printf("Opci�n no v�lida.\n");
    }

    return 0;
}

