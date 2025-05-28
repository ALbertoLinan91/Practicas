#include <stdio.h>
#include <stdint.h>
#include <math.h>
float Calculatecircunference(uint32_t radio);

int main() {
    uint32_t number_radio;
    printf("Introduce el radio de la circunferencia: ");
    scanf("%u", &number_radio);
    float perimeter = Calculatecircunference(number_radio);
    printf("El resultado es: %f", perimeter);

    return 0;
}

float Calculatecircunference(uint32_t radio) {

    float result = 2 * M_PI * radio;
    return result;

}
