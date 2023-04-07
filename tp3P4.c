#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


int precioProd(Producto *prod);

int main(){
    char aux[60];
    int cantClientes,indiceAuxTipoDeProducto;
    do
    {
    fflush(stdin);
    printf("\nIngrese la cantidad de Clientes que visito: ");
    scanf("%d",&cantClientes);
    } while (cantClientes > 5 || cantClientes < 1 );

    Cliente *mtzClientes = (Cliente *) malloc(sizeof(Cliente)*cantClientes);

    printf("\n===== A continuación ingrese los datos del cliente =====");

    for (int i = 0; i < cantClientes; i++)
    {  
        fflush(stdin); 
        printf("\nIngrese el nombre del usuario: ");
        gets(aux);
        mtzClientes[i].NombreCliente = (char *) malloc( sizeof (char) * strlen(aux));
        strcpy(mtzClientes[i].NombreCliente, aux);
        mtzClientes[i].ClienteID = i;
        mtzClientes[i].CantidadProductosAPedir= 1+rand()%5;
        mtzClientes[i].Productos = (Producto *) malloc(sizeof(Producto) * mtzClientes[i].CantidadProductosAPedir);
        for (int j = 0; j < mtzClientes[i].CantidadProductosAPedir; j++)
        {
          mtzClientes[i].Productos[j].ProductoID = j;
          mtzClientes[i].Productos[j].Cantidad = 1 + rand() % 10;
          indiceAuxTipoDeProducto = rand()%4;
          mtzClientes[i].Productos[j].TipoProducto = (char *) malloc(sizeof(char) * strlen(TiposProductos[indiceAuxTipoDeProducto]));
          strcpy(mtzClientes[i].Productos[j].TipoProducto,TiposProductos[indiceAuxTipoDeProducto]);
          mtzClientes[i].Productos[j].PrecioUnitario = 10 + rand() % 91;
        }
        
    }
    float totalPagarCliente=0;
    for (int i = 0; i < cantClientes; i++)
    {
        printf("\nNombre: %s",mtzClientes->NombreCliente);
        printf("\nId: %d",mtzClientes->ClienteID);
        printf("\nCant Prod: %d",mtzClientes->CantidadProductosAPedir);
        printf("\n=== Detalle de los productos ===");
        for (int j = 0; j < mtzClientes->CantidadProductosAPedir; j++)
        {
            printf("\n---------------------------------------------------");
            printf("\nTipo de Producto: %s", mtzClientes->Productos->TipoProducto);
            printf("\nProductoID: %d", mtzClientes->Productos->ProductoID);
            printf("\nCantidad = %d",mtzClientes->Productos->Cantidad);
            printf("\nPrecio Unitario= %.2f ",mtzClientes->Productos->PrecioUnitario);
            totalPagarCliente += precioProd(mtzClientes->Productos);
            mtzClientes->Productos ++;
        }
        printf("\n---------------------------------------------------");    
        printf("\nTotal a Pagar del cliente Nro %d : %.2f", i, totalPagarCliente);
        printf("\n---------------------------------------------------");
        printf("\n---------------------------------------------------");                        
        totalPagarCliente = 0;
        mtzClientes ++;
    }
    return 0;
}

int precioProd(Producto *prod){

    return (prod->Cantidad * prod->PrecioUnitario);
}