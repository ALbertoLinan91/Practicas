#include <stdio.h>
#include <stdint.h>
#include <math.h>
float convert_kmh_to_ms(float kmh);

int main() {
    float speed;
    printf("Introduce la velocidad en kilometros por hora: ");
    scanf("%f", &speed);
    float ms = convert_kmh_to_ms(speed);
    printf("La velocidad en m/s: %f", ms);

    return 0;
}

float convert_kmh_to_ms(float kmh) {

    float result = kmh *1000 / 3600;
    return result;

}
