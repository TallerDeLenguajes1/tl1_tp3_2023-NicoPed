#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int CANT_NOMBRES;
    char Aux[60];
    printf("\nIngrese la cantidad de nombres a ingresar: ");
    scanf("%d",&CANT_NOMBRES);
    char *pNombres[CANT_NOMBRES];
    for (int i = 0; i < CANT_NOMBRES; i++)
    {
        fflush(stdin);
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