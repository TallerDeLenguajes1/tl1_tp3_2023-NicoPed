#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
//CON LISTA ENLAZADA
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

typedef struct nodo
{
    Cliente cliente;
    struct nodo *siguiente;
}sNodo;

float precioProd(Producto prod);
float totalPagarCliente(Cliente cliente);

sNodo* crearListaVacia();
Cliente crearCliente(int id, char* buffer, int cantidadProductos);
Producto crearProducto(int id);
sNodo* crearNodo(Cliente nuevoCliente);
void mostrarCliente(Cliente cliente);
void mostrarProductos(Producto * productos, int cantidad);

void insertarNodo(sNodo** lista, sNodo* nuevoNodo);

int main(){
    char buffer[60];
    int indiceAuxTipoDeProducto, cantProductos,respuesta, clienteID = 0;
    float totalAPagar;
    sNodo* nuevoNodo,* auxMostrar;
    Cliente nuevoCliente;
    sNodo* cabecera;
    cabecera = crearListaVacia();
    
    do
    {
        printf("\n1- Ingresar cliente nuevo");
        printf("\n2- Mostrar Clientes y el total a pagar de cada uno");
        printf("\n10- Salir");    
        printf("\nIgrese una opcion: ");
        
        fflush(stdin);
        scanf("%d", &respuesta);
//printf("\n");
        switch (respuesta)
        {
        case 1:
            printf("\nIngrese el nombre del cliente: ");
            fflush(stdin);
            gets(buffer);
            do
            {
            printf("\nIngrese la cantidad de productos (por razones operativas debe ser menor a 10): ");
            scanf("%d",&cantProductos);
            } while (cantProductos < 1 || cantProductos >10);
            clienteID ++;
            nuevoCliente = crearCliente(clienteID,buffer,cantProductos);
            nuevoNodo = crearNodo(nuevoCliente);
            insertarNodo(&cabecera,nuevoNodo);
            break;
        case 2:
            auxMostrar = cabecera;
            while (auxMostrar != NULL)
            {
                mostrarCliente(auxMostrar->cliente);
                totalAPagar = totalPagarCliente(auxMostrar->cliente);
                printf("\nEl total a pagar del cliente %s es: %.2f",auxMostrar->cliente.NombreCliente, totalAPagar);
                auxMostrar = auxMostrar->siguiente;
                printf("\n================================");
            }
            

            break;
        case 10:
            printf("");
            break;
        default:
            printf("\nIngrese una opción valida");
            break;
        }
    } while (respuesta != 10);
    free(cabecera);

    return 0;
}

float precioProd(Producto prod){

    return (prod.Cantidad * prod.PrecioUnitario);
}

sNodo* crearListaVacia(){
    return NULL;
}

void insertarNodo(sNodo** lista, sNodo* nuevoNodo){
    nuevoNodo->siguiente = *lista;
    *lista = nuevoNodo;
}

Cliente crearCliente(int id, char* buffer, int cantidadProductos){
    Cliente nuevo;
    nuevo.ClienteID = id;
    nuevo.NombreCliente = (char *) malloc(sizeof(char) * strlen(buffer) + 1);
    strcpy(nuevo.NombreCliente,buffer);
    nuevo.CantidadProductosAPedir = cantidadProductos;
    nuevo.Productos = (Producto *) malloc(sizeof(Producto)*cantidadProductos);
    for (int i = 0; i < cantidadProductos; i++)
    {
        nuevo.Productos[i] = crearProducto(i);
    }
    return nuevo;
}
Producto crearProducto(int id){
    Producto nuevo;
    int indice;
    nuevo.ProductoID = id;
    nuevo.Cantidad = 1+ rand()%11;
    indice = rand()%5;
    nuevo.TipoProducto = (char *) malloc(sizeof(char) * strlen(TiposProductos[indice]));
    strcpy(nuevo.TipoProducto,TiposProductos[indice]);
    nuevo.PrecioUnitario = (float) (1000 + rand()%901) / 100;
    return nuevo;
}
sNodo* crearNodo(Cliente nuevoCliente){
    sNodo * nuevoNodo = (sNodo *) malloc(sizeof(sNodo));
    nuevoNodo->cliente.ClienteID = nuevoCliente.ClienteID;
    nuevoNodo->cliente.CantidadProductosAPedir = nuevoCliente.CantidadProductosAPedir;
    nuevoNodo->cliente.NombreCliente = (char *) malloc(sizeof(char) * strlen(nuevoCliente.NombreCliente) + 1);
    strcpy(nuevoNodo->cliente.NombreCliente, nuevoCliente.NombreCliente);
    nuevoNodo->cliente.Productos = nuevoCliente.Productos;
    return nuevoNodo; 
}

void mostrarCliente(Cliente cliente){
    printf("\n================================");
    printf ("\nID: %d",cliente.ClienteID);
    printf("\nNombre del cliente: %s",cliente.NombreCliente);
    printf("\nCantidad de Productos que pidio: %d",cliente.CantidadProductosAPedir);
    printf("\n--- Detalle de los productos ---");
    mostrarProductos(cliente.Productos, cliente.CantidadProductosAPedir);
    printf("\n================================");

}
void mostrarProductos(Producto * productos, int cantidad){
    printf("\n---------------------------");
    for (int i = 0; i < cantidad; i++)
    {
        printf("\nId Producto: %d",productos[i].ProductoID);
        printf("\nCantidad: %d ", productos[i].Cantidad);
        printf("\nTipo: %s",productos[i].TipoProducto);
        printf("\nPrecio unitario: %.2f",productos[i].PrecioUnitario);
        printf("\n---------------------------");
        productos[i];
    }
}
float totalPagarCliente(Cliente cliente){
    float total = 0.0;
    for (int i = 0; i < cliente.CantidadProductosAPedir ; i++)
    {
        total += precioProd(cliente.Productos[i]);
    }
    return total;
}
/*
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
        gets(buffer);
        mtzClientes[i].NombreCliente = (char *) malloc( sizeof (char) * strlen(buffer));
        strcpy(mtzClientes[i].NombreCliente, buffer);
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
    free(mtzClientes->Productos);
    free(mtzClientes);
*/