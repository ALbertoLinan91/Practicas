#include <stdio.h>


void mostrarNumeros(int num1, int num2) {
    int inicio = num1 < num2 ? num1 : num2;
    int fin = num1 > num2 ? num1 : num2;

    printf("Los n�meros entre %d y %d son:\n", inicio, fin);
    for (int i = inicio; i <= fin; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int numero1, numero2;

    printf("Ingresa el primer n�mero: ");
    scanf("%d", &numero1);

    printf("Ingresa el segundo n�mero: ");
    scanf("%d", &numero2);

    mostrarNumeros(numero1, numero2);

    return 0;
}
