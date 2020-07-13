/*
ALANIS FLORES ROYER CESAR
8449437 LP
INF-317
PRIMER PARCIAL EJERCICIO 1
CIFRADO DE CESAR CON OPEN MP EN C
EJECUTAR:
cifces.c
gcc cifces.c -fopenmp
gcc cifces.c -o cifces -fopenmp
./cifces
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <omp.h>

void main()
{
  char nombre[25]="ROYER CESAR ALANIS FLORES";
  int i=0;
  #pragma omp critical
  {
      
     for (i=0; i<25; i++){
       printf("%c",nombre[i]);
     }
     printf("\n");
  
     int idomp=0;
    //segun el numero de procesadores se escoge para hacer el cifrado de CESAR
    while(idomp==0){
      #pragma omp parallel
      idomp = omp_get_thread_num();   
    }
    #pragma omp parallel for 
    for(i=0; i<25; i++){
      if(nombre[i]!=32){
        if((nombre[i]+idomp)>90){
          nombre[i]=(64+(nombre[i]+idomp)%90);  
        }
        else{
          nombre[i]=nombre[i]+idomp;
        }
      }   
    }
 
   for (i=0; i<25; i++){
      printf("%c",nombre[i]);
    }
    printf("\n");
    printf("rotacion para descifrar: %d \n",idomp);
  }  
}
