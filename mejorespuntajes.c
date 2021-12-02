#include <stdio.h>
#include <stdlib.h>
 
struct players //llamado a la estructura players
{
  char nombre[30];
  int puntaje;
};

int main()
{
struct players jug[10];
int e, numerojugador, pmayor, pmenor;
int mayor=0, menor=1200; // puntaje mínimo y máximo para obtener durante el juego
printf("Introduzca la cantidad de mejores calificaciones que quisiera ver: ");
scanf("%d", &numerojugador);

  for(e=0; e<numerojugador; e++)
  {
    printf("\n");
    printf("Nombre[%d]:", e+1); //imprime el nombre del jugador
   //scanf("%d", &jug[e].nombre);
    printf("\n");
    printf("Puntaje[%d]:", e+1); //imprime el puntaje de cada jugador
    //scanf("%d",&jug[e].puntaje);
  }
if(jug[e].puntaje>mayor)
{
  mayor=jug[e].puntaje;
  pmayor=e;
}
if (jug[e].puntaje<menor)
{
  menor=jug[e].puntaje;
  pmenor=e;
}

 
printf("\n \n %s es el jugador con el puntaje más alto", jug[pmayor].nombre); //imprime el nombre del jugador con el mejor puntaje

printf("\n \n %s es el jugador con el puntaje más bajo", jug[pmenor].nombre); //imprime el nombre del jugador con el peor puntaje

return 0;
}

//Notas:
//este código permite decidir cuántas calificaciones de máximos puntajes puede revisar.
//El usuario escribe la cantidad de máximas calificaciones que decide ver y en pantalla aparecen los nombres de los usuarios y sus puntajes guardados. Al final se muestra el nombre con el puntaje más alto y el usuario con el puntaje más bajo.