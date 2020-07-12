/*
ALANIS FLORES ROYER CESAR
8449437 LP
INF-317
Primer Parcial Ejercicio 3
Ecuacion resuelta mediane metodo de jacobi,
ejercicio predeterminado, se puede modificar 
para cualquier tipo de ecuacion
EJECUTAR:
jacobi.c
gcc jacobi.c -fopenmp
gcc jacobi.c -o jacobi -fopenmp
*/
*/

#include<stdio.h>
#include<stdbool.h>
#include <omp.h>
int main(){
  float matriz[3][3+1];
  float valores[3];
  float aux[3];
  //matriz de ecuacion
  matriz[0][0]=4;
  matriz[0][1]=-1;
  matriz[0][2]=0;
  matriz[0][3]=2;
  matriz[1][0]=-1;
  matriz[1][1]=4;
  matriz[1][2]=-1;
  matriz[1][3]=6;
  matriz[2][0]=0;
  matriz[2][1]=-1;
  matriz[2][2]=4;
  matriz[2][3]=2;
  /*
  ECUACION:
  4x-y    =2
  -x+4y-z =6
     -y+4z=2
  RESULTADO:
  x=1
  y=2
  z=1
  */
  aux[0]=aux[1]=aux[2]=0;
  bool sw=true;
  int c=0;
#pragma omp critical
{ 
  c=0;
  while(sw){
   c++;
   int i;
   int j;
   #pragma omp parallel for
   for (i = 0; i < 3; i++) {
    valores[i]=aux[i];
   }
//operaciones utilizadas para el metodo de jacobi
   #pragma omp parallel for
   for (i = 0; i < 3; i++) {
    aux[i]=matriz[i][3];
   #pragma omp parallel for
   for (j = 0; j < 3; j++) {
     if(i!=j) {
      aux[i]=aux[i]-(valores[j]*matriz[i][j]);
     }
    }
    aux[i]=aux[i]/matriz[i][i];
   }
   sw=false;
   #pragma omp parallel for 
   for (i = 0; i < 3; i++) {
//    printf("%d %f \n",c,aux[i]);//muestra el vector x con re
                //sultados parciales y la iteracion
    if(aux[i]!=valores[i]) {
     sw=true;
    }
   }
  }
//resulado final 
  printf("*******************\n");
  printf("Resultado final en %d iteraciones \n",c);
  #pragma omp criticall
  for (int i = 0; i < 3; i++) {
   printf("%f \n",aux[i]);
  }
}
}
