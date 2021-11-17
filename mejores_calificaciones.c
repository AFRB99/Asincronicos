#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int mejores_calificaciones)
{
 int a[10]={10,9,8,7,6,5,4,3,2,1};
 int resultado[10]={9, 4, 6, 1, 3, 11, 12, 18, 5, 7};
 int res;
//scanf("%i\n",&res);
int i,j, k,temp;
int longitud =(sizeof resultado)/(sizeof *resultado);
for(i=0;i<longitud;i++)
 {
 for(j=0;j<longitud;j++)
 {
if(resultado[j]<resultado[j+1])
{
 temp=resultado[j+1];
resultado[j+1]=resultado[j];
resultado[j]=temp;
}
 }
 }
for(k=0; k<longitud;k++)
{

printf("Las mejores diez calificaciones son" " #%i:\n", a[k]);
printf("\t %i\n", resultado[k]);
}
printf("\t \t ¡Gracias por jugar!\n");
return 0;
}