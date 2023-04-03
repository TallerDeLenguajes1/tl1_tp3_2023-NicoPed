#include <stdio.h>
#include <stdlib.h>

#define CANT_NOMBRES 5
#define MAX 15

int main(){
    char *pNombres[CANT_NOMBRES];
    for (int i = 0; i < CANT_NOMBRES; i++)
    {
        pNombres[i] = (char *) malloc(sizeof (char *) * MAX);
        printf("Ingrese un nombre: ");
        gets(pNombres[i]);
    }
    for (int i = 0; i < CANT_NOMBRES; i++)
    {
        printf("Nombre %d : ",i);
        puts(pNombres[i]);
        //printf("Nombre %d : %s \n",i,pNombres[i]);
        free(pNombres[i]);
    }

    return 0;    
}