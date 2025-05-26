#include <stdio.h>
#include <stdint.h>
#include <conio.h>
#include <synchapi.h>
int main (){
    char password_1 = '9' , password_2 = '8' ,password_3 = '7', password_4 = '6' , password_5 = '5';
    char character_1,character_2,character_3,character_4,character_5;
    uint32_t trying = 0;

    while (trying < 3) {
    printf("Introduzca contrase%ca de cinco digitos:\n" ,164);
    character_1 = getch();
    printf("*");
    character_2 = getch ();
    printf("*");
    character_3 = getch ();
    printf("*");
    character_4 = getch();
    printf("*");
    character_5 = getch();
    printf("*\n" );

    if (password_1 == character_1 && password_2 == character_2 && password_3 == character_3 && password_4 == character_4 && password_5 == character_5 ){
        printf ("La contrase%ca introducida es correcta, puerta abierta\n",164);
        break;
    }else{ // si no se mostrara un mensaje de que la contraseña es incorrecta y que sepuede volver a intentar
        printf("La contrase%ca introducida es incorrecta,vuelva a intentarlo... \n\n",164);
        trying ++; // Sumamaos un intento a la variable trying
    }
    if (trying == 3) { // Cuando trying sea igual que 3 el usuario tendra que esperar el tiempo estipulado
        printf("Se ha equivocado demasiadas veces,espere... \n\n");
        Sleep (3000);
        trying = 0;
    }
    }
    return 0;
}





