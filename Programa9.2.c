#include <stdio.h>
#include <stdlib.h>

void Caratula();
void PedirValorUsuario(int *n, int *m);
unsigned long long CalcularFactorial(int num);
int ComprobarValorUsuario(int n, int m);
void FuncionPausa();
void MostrarResultado(unsigned long long factorialN, unsigned long long factorialM, unsigned long long factorialNM, int n, int m);
int SeguirEjecutando(int *ejecutar);

void Caratula()
{
    puts("Equipo 1\n"
        "Integrantes:\n"
        "1. Contreras Aviles Jose Raul.\n"
         "2. Hernandez Tovar Evelyn Ariadna.\n"
         "3. Rosas Fragoso Leonardo.\n"
         "4. Rosas Vazquez Eduardo.\n"
         "5. Zamitiz Carmona Cristian Erasto.");
    printf("Presiona Enter");
    getchar();
    system("clear");
}

void PedirValorUsuario(int *n, int *m)
{
    puts("Programa 9 (Calculo de Combinaciones).");
    puts("Este programa calcula cuantos grupos diferentes de 'm' elementos se pueden formar a partir de 'n' elementos. Formula: C = n! / (m! * (n-m)!)");
    puts("Introduce el numero total de elementos enteros positivos disponibles (un numero menor a 20):");
    scanf("%d", n);

    printf("Introduce el numero de elementos a elegir (m): ");
    scanf("%d", m);

    while (getchar() != '\n');

    system("clear");
}

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
        printf("Error: Los numeros deben ser enteros positivos o cero.\n");
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

void FuncionPausa()
{
    printf("Presiona enter para continuar...");
    while (getchar() != '\n');
    system("clear");
}

void MostrarResultado(unsigned long long factorialN, unsigned long long factorialM, unsigned long long factorialNM, int n, int m)
{
    unsigned long long combinaciones = factorialN / (factorialM * factorialNM);

    printf("Resultado:\n");
    printf("De %d elementos totales, se pueden formar %llu grupos distintos de %d elementos.\n",
           n, combinaciones, m);

    FuncionPausa();
}

int SeguirEjecutando(int *ejecutar)
{
    int seleccion = 0;

    puts("Realizar otro calculo?\n");
    printf("Ingrese 1 para 'Si' (enter para 'No'): ");

    if (scanf("%d", &seleccion) != 1)
    {
        seleccion = 0;
    }

    while (getchar() != '\n');

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

