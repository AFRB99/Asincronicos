//proyecto Final de plataformas abiertas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{

char nombre[20];

printf("\n \t \t \t Hola!, bienvenido al juego del ahorcado\n\n");
printf("\n \t \t \t Usuario, por favor escriba su nombre:\n");
scanf("%c",&nombre);
printf("%c",nombre);
// elegircategoria();
printf("%s,Por favor seleccione una categoria: \n", nombre );

return 0;
}

// void elegircategoria()

// // int a;
// {
// printf("\n \t \t \t %s Las categorías disponibles son:\n",nombre);
// printf("1-animal\n");
// printf("2-fruta \n");
// printf("3-pais\n");
// printf("4-cosa\n");
// printf("Por favor seleccione una categoria: \n");
// // scanf(%i, &a);
// }