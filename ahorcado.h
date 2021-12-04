#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
// #include <unistd.h>
#include <curses.h> 

typedef struct ranking 
{
    int puntos;
    char *nombre;
    struct ranking *siguiente;
}RANKING,*PRANKING;

PRANKING juego();
void rankear(PRANKING *lista_ranking, PRANKING actual);
void imprimir_ranking(PRANKING lista_ranking);
void dibujo_ahorcado (int intentos);


char lista [17][15] = {"sandia","melon","papaya","limon","manzana", 
"pera", "fresa", "mora","arandano", "piña", "uva", "jocote", 
"mango","guanabana", "carambola", "cas", "banano" 
};

//Funcion con la lista de palabras que se le mostraran al usuario

//Funcion con el algoritmo principal del juego
PRANKING juego(){

    printf("\nINGRESE SU NOMBRE:\n");
    char nombre[20];
    scanf("%s",nombre);
    fflush(stdin);

    PRANKING actual = (PRANKING)malloc(sizeof(RANKING));
    actual->nombre=(char*)malloc(sizeof(char)*15);
    strcpy (actual->nombre, nombre);
    //Definicion de variables
    char letra;
    int x,y,z,random,largo,espacio;
    int puntos = 1200;
    int correcto = 0;
    int intentos = 0;
    int gana = 0;
    srand(time(NULL));

    //Se obtienen un numero aleatorio para selecionar una palabra de la lista
    random = rand() % 17; 
    //SE ALMACENA LA LONGITUD DE LA PALABRA 
    largo = strlen(lista[random]); 
    char escogida[largo];

    //Guiones para espacios de las tletras por completar
    for(x = 0; x < largo; x++){
    escogida[x] = '_';      
    }

    do{
        correcto = 0;
        printf("\n\t\t\t\tJUEGO DEL AHORCADO\n\n");
        printf(" \nIntentos Disponibles: %i\t\tPuntuacion: %i\n",6-intentos,puntos);
        fflush(stdout);
        dibujo_ahorcado(intentos);
        fflush(stdout);

        //Imprime el array con los caracteres de escogida
        printf("\n\n\n");
        for(x = 0; x < largo; x++){
            printf("%c",escogida[x]);
        }

        //Indicador de derrota
        if (intentos == 6){
            printf("\n\n LO SENTIMOS, PERDISTE!!\n");
            printf("\n\n LA PALABRA CORRECTA ERA: %s\n\n",lista[random]);
            actual->puntos = puntos;
            break;
        }

    //Comprobacion de palabra correcta
        espacio = 0;

        for (x = 0; x < largo; x++){
            if (escogida[x] == '_')
                espacio++;
        }



        if (espacio == 0){
            printf("\n\n FELICIDADES HAS GANADO!!!\n\n");
            actual->puntos = puntos; 
            break;
        }
    
        printf("\n\n Digite una letra: \n");
        scanf(" %c",&letra);
        fflush(stdin);

        //PROCESO QUE VERIFICA SI LA LETRA INGRESADA EXISTE EN LA PALABRA, SI ESTO ES VERDADERO, SE REEMPLAZA EL CARACTER GUION BAJO POR LA LETRA INGRESADA 
        for (y = 0; y < largo; y++){
            if (letra == lista[random][y]){
                escogida[y] = letra;
                correcto++;
            }
        }

        if (correcto == 0){
            intentos++;
            puntos -= 200;
    }

    }while(intentos != 7);
    printf("\n\n");
    return actual   ;
}


void rankear(PRANKING *lista_ranking, PRANKING actual) {

    if (*lista_ranking == NULL){
        *lista_ranking = actual;
        return;

    }
    PRANKING pivote2 = NULL;
    for (PRANKING pivote = *lista_ranking; pivote != NULL; pivote = pivote->siguiente){
        if (actual->puntos > pivote->puntos){
            if(pivote2 == NULL){
                actual->siguiente = pivote; 
                *lista_ranking = actual; 
            }
            else {
                pivote2->siguiente = actual;
                actual->siguiente = pivote;
            }
            break;
        }

        else if (pivote->siguiente == NULL){
            pivote->siguiente = actual;
            break;
        }
        pivote2 = pivote; 
    }

}

void imprimir_ranking(PRANKING lista_ranking){
    int entero = 0;
    
    if (lista_ranking == NULL){
        fflush(stdout);
    }
    for (PRANKING pivote = lista_ranking; pivote != NULL; pivote = pivote->siguiente){
        if (entero == 10)
            break;
        printf("\nJugador: %s Puntos: %i\n", pivote->nombre, pivote->puntos);
        entero++; 
    }


}

    //Funcion para imprimir el dibujo en pantalla
void dibujo_ahorcado (int intentos) {
    switch(intentos){
        case 0:
            printf("\n _______\n |\n |\n |\n |\n |\n |\n |\n -----------");
            break;
        case 1:
            printf("|\n _______\n |  |\n |\n |\n |\n |\n -----------");
            break;
        case 2:    
            printf("|\n _______\n |  |\n |  O\n | \n |\n |\n |\n -----------");
            break;
        case 3:
            printf("|\n _______\n |  |\n |  O\n | /|\n |\n |\n |\n -----------");
            break;
        case 4:
            printf("|\n _______\n |  |\n |  O\n | /|\\ \n |\n |\n |\n -----------");
            break;
        case 5:
            printf("|\n _______\n |  |\n |  O\n | /|\\ \n | /\n |\n |\n |\n |\n -----------");
            break;
        case 6:
            printf("|\n _______\n |  |\n |  O\n | /|\\ \n | / \\ \n |\n |\n -----------");
            break;
    }
}

