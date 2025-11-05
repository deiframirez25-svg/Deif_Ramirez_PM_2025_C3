#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOMBRE_ARCHIVO "inventario.txt"

typedef struct
{
    int id;
    char nombre[50];
    float precio;
    int cantidad;
} Producto;

int contarProductos();
Producto* cargarInventario(int *n);
void imprimirInventario(Producto *inventario, int n);
void agregarProducto();
void guardarProducto(Producto nuevo);
void limpiarBuffer();

int main()
{
    int opcion;
    int n = 0;
    Producto *inventario = NULL;

    // Cargar inventario desde archivo
    inventario = cargarInventario(&n);

    printf("Inventario cargado con %d productos.\n", n);

    printf("\n¿Desea agregar un nuevo producto al inventario? (1=Sí / 0=No): ");
    scanf("%d", &opcion);
    limpiarBuffer();

    if (opcion == 1)
    {
        agregarProducto();
        free(inventario); // liberamos la memoria antes de recargar
        inventario = cargarInventario(&n);
    }

    printf("\n¿Desea imprimir el inventario actual? (1=Sí / 0=No): ");
    scanf("%d", &opcion);

    if (opcion == 1)
    {
        imprimirInventario(inventario, n);
    }

    free(inventario);
    printf("\nPrograma finalizado.\n");
    return 0;
}

//----------------------------------------------------

int contarProductos()
{
    FILE *archivo = fopen(NOMBRE_ARCHIVO, "r");
    if (!archivo) return 0;

    int count = 0;
    char linea[128];
    while (fgets(linea, sizeof(linea), archivo))
    {
        count++;
    }
    fclose(archivo);
    return count;
}

Producto* cargarInventario(int *n)
{
    *n = contarProductos();
    if (*n == 0)
    {
        printf("No hay productos en el inventario.\n");
        return NULL;
    }

    Producto *inventario = (Producto*) malloc((*n) * sizeof(Producto));
    if (!inventario)
    {
        printf("Error: no se pudo asignar memoria.\n");
        exit(1);
    }

    FILE *archivo = fopen(NOMBRE_ARCHIVO, "r");
    if (!archivo)
    {
        printf("Error al abrir el archivo.\n");
        free(inventario);
        exit(1);
    }

    for (int i = 0; i < *n; i++)
    {
        fscanf(archivo, "%d %s %f %d",
               &inventario[i].id,
               inventario[i].nombre,
               &inventario[i].precio,
               &inventario[i].cantidad);
    }

    fclose(archivo);
    return inventario;
}

void imprimirInventario(Producto *inventario, int n)
{
    if (inventario == NULL || n == 0)
    {
        printf("No hay productos para mostrar.\n");
        return;
    }

    printf("\n--- Inventario de Productos ---\n");
    for (int i = 0; i < n; i++)
    {
        printf("ID: %d | Nombre: %s | Precio: %.2f | Cantidad: %d\n",
               inventario[i].id,
               inventario[i].nombre,
               inventario[i].precio,
               inventario[i].cantidad);
    }
    printf("-------------------------------\n");
}

void agregarProducto()
{
    Producto nuevo;
    printf("\nIngrese los datos del nuevo producto:\n");
    printf("ID: ");
    scanf("%d", &nuevo.id);
    limpiarBuffer();
    printf("Nombre: ");
    fgets(nuevo.nombre, sizeof(nuevo.nombre), stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = '\0'; // eliminar salto de línea
    printf("Precio: ");
    scanf("%f", &nuevo.precio);
    printf("Cantidad: ");
    scanf("%d", &nuevo.cantidad);

    guardarProducto(nuevo);
    printf("Producto agregado correctamente.\n");
}

void guardarProducto(Producto nuevo)
{
    FILE *archivo = fopen(NOMBRE_ARCHIVO, "a");
    if (!archivo)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }
    fprintf(archivo, "%d %s %.2f %d\n", nuevo.id, nuevo.nombre, nuevo.precio, nuevo.cantidad);
    fclose(archivo);
}

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

