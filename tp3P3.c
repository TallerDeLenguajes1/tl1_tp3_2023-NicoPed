#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT_NOMBRES 5
#define MAX 15

int main(){
    char Aux[60];
    char *pNombres[CANT_NOMBRES];
    for (int i = 0; i < CANT_NOMBRES; i++)
    {
        printf("Ingrese un nombre: ");
        gets(Aux);
        pNombres[i] = (char *) malloc(sizeof (char *) * strlen(Aux));
        strcpy(pNombres[i],Aux);
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