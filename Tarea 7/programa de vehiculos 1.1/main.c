#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// ============================================================
/// 2️⃣ PROPIEDADES DE LOS Vehiculo/// ============================================================

typedef struct
{
    char marca[50];
    char modelo[50];
    int anio;
    int id;
    char placa[20];
    float consumo_ciudad;       // L/100Km
    float consumo_carretera;    // L/100Km
    float costo_seguro_anual;
    float costo_mantenimiento_km;
    int tiempo_depreciacion;    // anios
    float costo_vehiculo;
    float km_promedio_anual;
    float costo_limpieza;
    float costo_combustible;    // precio del litro
} Vehiculo;

/// ============================================================
/// VARIABLES GLOBALES
/// ============================================================
Vehiculo vehiculos[10];
int totalVehiculos = 0;

/// ============================================================
/// FUNCIONES DEL APARTADO 1️⃣ - MENU PRINCIPAL
/// ============================================================

void menu();
void agregarVehiculo();
void listarVehiculos();
void modificarVehiculo();
void agregarCombustible();
void modificarCombustible();
void listarCombustible();
void calcularViaje();

/// ============================================================
/// FUNCIONES AUXILIARES
/// ============================================================
void limpiarPantalla()
{
    system("cls"); // en Windows; usa "clear" en Linux o Mac
}

/// ============================================================
/// 1️⃣ SISTEMA CALCULO DE COSTO DE VIAJE
/// ============================================================

int main()
{
    int opcion;
    do
    {
        menu();
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion)
        {
        case 1:
            agregarVehiculo();
            break;
        case 2:
            listarVehiculos();
            break;
        case 3:
            modificarVehiculo();
            break;
        case 4:
            agregarCombustible();
            break;
        case 5:
            modificarCombustible();
            break;
        case 6:
            listarCombustible();
            break;
        case 7:
            calcularViaje();
            break;
        case 0:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opcion invalida.\n");
        }

        printf("\nPresione ENTER para continuar...");
        getchar();
        limpiarPantalla();

    }
    while(opcion != 0);

    return 0;
}

/// ============================================================
/// MENU PRINCIPAL
/// ============================================================
void menu()
{
    printf("\n====== SISTEMA DE CALCULO DE COSTO DE VIAJE ======\n");
    printf("1. Agregar Vehiculo\n");
    printf("2. Lista Vehiculos\n");
    printf("3. Modificar Vehiculo\n");
    printf("4. Agregar Combustible\n");
    printf("5. Modificar Combustible\n");
    printf("6. Lista Combustible\n");
    printf("7. Calcular Viaje\n");
    printf("0. Salir\n");
    printf("==================================================\n");
}

/// ============================================================
/// FUNCIONES DE Vehiculo/// ============================================================
void agregarVehiculo()
{
    if (totalVehiculos >= 10)
    {
        printf("No se pueden agregar mas vehiculos.\n");
        return;
    }

    Vehiculo v;
    v.id = totalVehiculos + 1;

    printf("\n--- AGREGAR VEHICULO ---\n");
    printf("Marca: ");
    gets(v.marca);
    printf("Modelo: ");
    gets(v.modelo);
    printf("Anio: ");
    scanf("%d", &v.anio);
    getchar();
    printf("Placa: ");
    gets(v.placa);
    printf("Consumo ciudad (L/100Km): ");
    scanf("%f", &v.consumo_ciudad);
    printf("Consumo carretera (L/100Km): ");
    scanf("%f", &v.consumo_carretera);
    printf("Costo seguro anual: ");
    scanf("%f", &v.costo_seguro_anual);
    printf("Costo mantenimiento por Km: ");
    scanf("%f", &v.costo_mantenimiento_km);
    printf("Tiempo de depreciacion (anios): ");
    scanf("%d", &v.tiempo_depreciacion);
    printf("Costo del vehiculo: ");
    scanf("%f", &v.costo_vehiculo);
    printf("Km promedio anual: ");
    scanf("%f", &v.km_promedio_anual);
    printf("Costo limpieza: ");
    scanf("%f", &v.costo_limpieza);
    v.costo_combustible = 0.0; // por defecto

    vehiculos[totalVehiculos++] = v;
    printf("Vehiculo agregado correctamente.\n");
}

void listarVehiculos()
{
    printf("\n--- LISTA DE VEHICULOS ---\n");
    for (int i = 0; i < totalVehiculos; i++)
    {
        printf("[%d] %s %s (%d) - Placa: %s\n",
               vehiculos[i].id,
               vehiculos[i].marca,
               vehiculos[i].modelo,
               vehiculos[i].anio,
               vehiculos[i].placa);
    }
}

void modificarVehiculo()
{
    int id;
    listarVehiculos();
    printf("\nIngrese el ID del vehiculo a modificar: ");
    scanf("%d", &id);

    if (id < 1 || id > totalVehiculos)
    {
        printf("ID invalido.\n");
        return;
    }

    Vehiculo *v = &vehiculos[id - 1];
    printf("Modificar consumo ciudad (actual %.2f): ", v->consumo_ciudad);
    scanf("%f", &v->consumo_ciudad);
    printf("Modificar consumo carretera (actual %.2f): ", v->consumo_carretera);
    scanf("%f", &v->consumo_carretera);

    printf("Vehiculo modificado correctamente.\n");
}

/// ============================================================
/// FUNCIONES DE COMBUSTIBLE
/// ============================================================
void agregarCombustible()
{
    int id;
    listarVehiculos();
    printf("\nSeleccione el ID del vehiculo: ");
    scanf("%d", &id);

    if (id < 1 || id > totalVehiculos)
    {
        printf("ID invalido.\n");
        return;
    }

    printf("Ingrese el costo por litro de combustible: ");
    scanf("%f", &vehiculos[id - 1].costo_combustible);

    printf("Costo de combustible agregado.\n");
}

void modificarCombustible()
{
    int id;
    listarVehiculos();
    printf("\nSeleccione el ID del vehiculo para modificar combustible: ");
    scanf("%d", &id);

    if (id < 1 || id > totalVehiculos)
    {
        printf("ID invalido.\n");
        return;
    }

    printf("Costo actual: %.2f\n", vehiculos[id - 1].costo_combustible);
    printf("Nuevo costo por litro: ");
    scanf("%f", &vehiculos[id - 1].costo_combustible);

    printf("Costo de combustible modificado.\n");
}

void listarCombustible()
{
    printf("\n--- COSTO DE COMBUSTIBLE POR VEHICULO ---\n");
    for (int i = 0; i < totalVehiculos; i++)
    {
        printf("[%d] %s %s - Combustible: %.2f\n",
               vehiculos[i].id,
               vehiculos[i].marca,
               vehiculos[i].modelo,
               vehiculos[i].costo_combustible);
    }
}

/// ============================================================
/// 3️⃣ CALCULO DE SALIDAS (COSTO TOTAL Y COSTO POR KM)
/// ============================================================
void calcularViaje()
{
    if (totalVehiculos == 0)
    {
        printf("No hay vehiculos registrados.\n");
        return;
    }

    listarVehiculos();
    int id;
    printf("\nSeleccione el ID del vehiculo para calcular viaje: ");
    scanf("%d", &id);

    if (id < 1 || id > totalVehiculos)
    {
        printf("ID invalido.\n");
        return;
    }

    float kmTotales, porcentajeCiudad;
    printf("Cantidad de KM del viaje: ");
    scanf("%f", &kmTotales);
    printf("%% KM en ciudad: ");
    scanf("%f", &porcentajeCiudad);

    Vehiculo v = vehiculos[id - 1];

    float kmCiudad = kmTotales * (porcentajeCiudad / 100.0);
    float kmCarretera = kmTotales - kmCiudad;

    float litrosCiudad = (v.consumo_ciudad / 100.0) * kmCiudad;
    float litrosCarretera = (v.consumo_carretera / 100.0) * kmCarretera;
    float litrosTotales = litrosCiudad + litrosCarretera;

    float costoCombustible = litrosTotales * v.costo_combustible;
    float costoSeguro = (v.costo_seguro_anual / v.km_promedio_anual) * kmTotales;
    float costoDepreciacion = (v.costo_vehiculo / (v.tiempo_depreciacion * v.km_promedio_anual)) * kmTotales;
    float costoMantenimiento = v.costo_mantenimiento_km * kmTotales;
    float costoLimpieza = v.costo_limpieza;

    float costoTotal = costoCombustible + costoSeguro + costoDepreciacion + costoMantenimiento + costoLimpieza;
    float costoPorKm = costoTotal / kmTotales;

    printf("\n--- RESULTADOS DEL VIAJE ---\n");
    printf("Costo combustible: %.2f\n", costoCombustible);
    printf("Costo seguro: %.2f\n", costoSeguro);
    printf("Costo depreciacion: %.2f\n", costoDepreciacion);
    printf("Costo mantenimiento: %.2f\n", costoMantenimiento);
    printf("Costo limpieza: %.2f\n", costoLimpieza);
    printf("----------------------------\n");
    printf("COSTO TOTAL: %.2f\n", costoTotal);
    printf("COSTO POR KM: %.2f\n", costoPorKm);
}

