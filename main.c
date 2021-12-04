#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ahorcado.h"

// Funciones en el main
int menu(void);

//Funcion principal
int main()
{
    menu();
    return 0; 
}

int menu()
{
    int num;
    PRANKING ranking = NULL;
    while(1){
        printf("\n\t\tHola!, bienvenido al juego del ahorcado\n");  
        printf("\n\t\tSeleccione una opción\n");
        printf("\t1. Iniciar un juego nuevo\n");
        printf("\t2. Historial de mejores puntuaciones\n");
        printf("\t3. Salir\n\n");
        scanf("%i", &num);

        if (num == 1){
            PRANKING nuevo = juego();
            rankear(&ranking, nuevo);
        }
        else if (num == 2){
            imprimir_ranking(ranking);    
        }
        else {
            exit(0);
        }
    }
}