#include <stdio.h>
#include <stdlib.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct{
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
}typedef Producto;

struct {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos ;//El tamaño de este arreglo depende de la variable
                    // “CantidadProductosAPedir”
}typedef Cliente;

int main(){

    int cantClientes;
    do
    {
    printf("\nIngrese la cantidad de Clientes que visito: ");
    scanf("%d",&cantClientes);
    } while (cantClientes > 5 || cantClientes < 1 );

    Cliente *mtzClientes = (Cliente *) malloc(sizeof(Cliente)*cantClientes);

    printf("\nA continuación ingrese los datos del cliente");

    for (int i = 0; i < cantClientes; i++)
    {   
    printf("\nIngrese el nombre del usuario: ");
    gets(mtzClientes->NombreCliente);
    mtzClientes->ClienteID = i;
    mtzClientes->CantidadProductosAPedir= 1+rand()%5;
    mtzClientes ++;    
    }

    return 0;
}