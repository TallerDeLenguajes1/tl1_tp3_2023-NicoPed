#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

int main(){
    char Buffer[60];
    int CANT_NOMBRES;
    printf("\nIngrese la cantidad de nombres a ingresar: ");
    scanf("%d",&CANT_NOMBRES);
    char **pNombres;
    pNombres = (char **) malloc(sizeof(char) * CANT_NOMBRES);
    for (int i = 0; i < CANT_NOMBRES; i++)
    {
        fflush(stdin);
        printf("Ingrese el nombre: ");
        gets(Buffer);
        pNombres[i] = (char * ) malloc(sizeof(char) * strlen(Buffer) + 1);
        strcpy(pNombres[i], Buffer);
    }
    for (int j = 0; j < CANT_NOMBRES; j++)
    {
        printf("\nNombre Nro %d: %s",j,pNombres[j]);
        free(pNombres[j]);
    }

    return 0;    
}