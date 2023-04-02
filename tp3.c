#include <stdio.h>
#include <stdlib.h>

#define FILAS 5
#define COLUMNAS 12
#define MAX 15
int main (){

float mtzProduccion [FILAS][COLUMNAS];
char meses[12][MAX] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
// a. Cargue dicha matriz con valores aleatorios entre 10000 y 50000.

for (int i = 0; i < FILAS; i++)
{
    for (int j = 0; j < COLUMNAS; j++)
    {
        mtzProduccion[i][j] = rand()% 40001 + 10000;
    }  

}
//b. Muestre por pantalla los valores cargados
//printf("Año|Enero|Febrero|Marzo|Abril|Mayo|Junio|Julio|Agosto|Septiembre|Octubre|Noviembre|Diciembre");
printf("\n-------------Punto b--------------\n");

for (int i = 0; i < FILAS; i++)
{
   // printf(" %d ",i);
    for (int j = 0; j < COLUMNAS; j++)
    {
        printf("%.2f  ",mtzProduccion[i][j]);
    }
    printf("\n");
}
/*c. Saque el promedio de ganancia por año y muestrelos por pantalla

d. Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de cuándo ocurrió.*/

float promedio = 0;
int anioMax=0,mesMax=0,anioMin=0,mesMin=0;
float max= 0,min= 9999999999999;
printf("\n-------------Punto c--------------");

for (int i = 0; i < FILAS; i++)
{
    for (int j = 0; j < COLUMNAS; j++)
    {
        promedio += mtzProduccion[i][j];
        if (max <= mtzProduccion[i][j])
        {
            anioMax = i;
            mesMax = j;
            max = mtzProduccion[i][j];
        }
        if (min >= mtzProduccion[i][j])
        {
            anioMin = i;
            mesMin = j;     
            min = mtzProduccion[i][j];
        } 
    }
    promedio = promedio/COLUMNAS;
    printf("\nPromedio Año %d : %.2f", i + 1, promedio); 
}
    printf("\n------------Punto d---------------");
    printf("\nEl valor maximo es: %.2f ocurrido en el año %d en el mes %s",max, anioMax+1, meses[mesMax]);
    printf("\nEl valor minimo es: %.2f ocurrido en el año %d en el mes %s",min, anioMin+1, meses[mesMin]);
//promedio = promedio + mtzProduccion[i][j];



    return 0;
}