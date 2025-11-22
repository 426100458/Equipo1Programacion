#include <stdio.h>
#include <stdlib.h>

// Prototipos
void Caratula();
void PedirValorUsuario(int *n, int *m);
unsigned long long CalcularFactorial(int num);
int ComprobarValorUsuario(int n, int m);
void FuncionPausa();
void MostrarResultado(unsigned long long factorialN, unsigned long long factorialM, unsigned long long factorialNM, int n, int m);
int SeguirEjecutando(int *ejecutar);

// Función de Carátula
void Caratula()
{
    puts("Programa 9 (Cálculo de Combinaciones).\nEste programa calcula cuantos grupos diferentes de 'm' elementos \nse pueden formar a partir de 'n' elementos. Fórmula: C = n! / (m! * (n-m)!)");
    puts("Equipo 1\n"
         "Integrantes:\n"
         "1. Contreras Aviles José Raúl.\n"
         "2. Hernández Tovar Evelyn Ariadna.\n"
         "3. Rosas Fragoso Leonardo.\n"
         "4. Rosas Vázquez Eduardo.\n"
         "5. Zamitiz Carmona Cristian Erasto.");
    printf("Presiona Enter");
    getchar();
    system("clear");
}

// Función para pedir valores al usuario
void PedirValorUsuario(int *n, int *m)
{
    puts("Introduce el número total de elementos enteros positivos disponibles (un número menor a 20):");
    scanf("%d", n);

    printf("Introduce el número de elementos a elegir (m): ");
    scanf("%d", m);

    while (getchar() != '\n'); // Limpieza de buffer

    system("clear");
}

// Función para calcular el factorial
unsigned long long CalcularFactorial(int num)
{
    if (num == 0) return 1;

    unsigned long long resultado = 1;
    for (int i = 2; i <= num; ++i)
    {
        resultado *= i;
    }

    return resultado;
}

// Función para validar los valores del usuario
int ComprobarValorUsuario(int n, int m)
{
    if (n > 20)
    {
    printf("Error: No se pueden calcular factoriales mayores a 20 (n=%d).\n", n);
    FuncionPausa();
    return 0;
    }
    else if (n < 0 || m < 0)
    {
    printf("Error: Los números deben ser enteros positivos o cero.\n");
    FuncionPausa();
    return 0;
    }
    else if (m > n)
    {
    printf("Error: m (%d) no puede ser mayor que n (%d).\n", m, n);
    FuncionPausa();
    return 0;
    }

    return 1;
}

// Función pausa
void FuncionPausa()
{
    printf("Presiona enter para continuar...");
    while (getchar() != '\n'); // Limpieza de buffer
    system("clear");
}

// Función para mostrar el resultado
void MostrarResultado(unsigned long long factorialN, unsigned long long factorialM, unsigned long long factorialNM, int n, int m)
{
    unsigned long long combinaciones = factorialN / (factorialM * factorialNM);

    printf("Resultado:\n");
    printf("De %d elementos totales, se pueden formar %llu grupos distintos de %d elementos.\n",
    n, combinaciones, m);

    FuncionPausa();
}

// Función para repetir el programa
int SeguirEjecutando(int *ejecutar)
{
    int seleccion = 0;

    puts("¿Realizar otro cálculo?");
    printf("Ingrese 1 para 'Sí' (enter para 'No'): ");

    if (scanf("%d", &seleccion) != 1)
    {
        seleccion = 0;
    }

    while (getchar() != '\n'); // Limpieza de buffer

    *ejecutar = (seleccion == 1);

    system("clear");
    return *ejecutar;
}

int main()
{
    Caratula();

    int m, n, ejecutar = 1;
    unsigned long long factorialN, factorialM, factorialNM;

    do
    {
        do
        {
          PedirValorUsuario(&n, &m);
        } while (ComprobarValorUsuario(n, m) == 0);

        factorialN = CalcularFactorial(n);
        factorialM = CalcularFactorial(m);
        factorialNM = CalcularFactorial(n - m);

        MostrarResultado(factorialN, factorialM, factorialNM, n, m);

        SeguirEjecutando(&ejecutar);

    } while (ejecutar == 1);

    return 0;
}
