// LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// PROTOTIPOS
void caratula();
double calcularPI(int t);
void imprimirResultado(int t, double valorPI);

// FUNCIÓN PRINCIPAL
int main()
{
    caratula();

    int t, continuar;

    // Bucle para repetir el programa si el usuario lo desea
    do
    {
        puts("¿Cuántos términos de PI desea utilizar?");
        scanf("%d", &t);
        // Validación de número positivo
        if (t <= 0)
        {
            printf("Por favor ingrese un número positivo mayor a 0\n");
            t = 1; // Asignar un valor válido para evitar cálculos innecesarios
        }
        else
        {
            // Cálculo de PI
            double valor = calcularPI(t);

            imprimirResultado(t, valor);

            // Opción para repetir el programa
            puts("Presione 0 para finalizar / cualquier otro número para repetir");
            scanf("%d", &continuar);
            // Limpieza de pantalla o salida
            if (continuar != 0)
            {
                system("clear");
            }
            else
            {
                printf("\nSaliendo...\n");
            }
        }
    } while (continuar != 0);

    return 0;
}

// FUNCIONES
void caratula()
{
    // Titulo
    puts("\nPrograma 11 - VALORES DE PI.\n");

    // Descripción
    puts(" DESCRIPCION: Un programa que obtiene el valor de PI. El programa le pregunta al usuario\ncuántos términos desea utilizar de la sucesionutilizar π/4 = 1 - 1/3 + 1/5 − 1/7 + 1/9−...\n ");

    // Integrantes
    puts("Equipo 01\n"
         "Integrantes:\n"
         "1. Contreras Aviles José Raúl.\n"
         "2. Hernández Tovar Evelyn Ariadna.\n"
         "3. Rosas Fregoso Leonardo.\n"
         "4. Rosas Vázquez Eduardo.\n"
         "5. Zamitiz Carmona Cristian Erasto.\n");

    // Pausa para ver la carátula
    printf("Presiona ENTER Para continuar...");
    getchar();
    system("clear");
}

// Cálculo de PI usando la serie de Leibniz
double calcularPI(int t)
{
    double suma = 0.0;

    // En la serie original:  π/4 = 1 - 1/3 + 1/5 - 1/7 + ... Cada término sigue el patrón: termino = (-1)^i / (2i + 1)
    for (int i = 0; i < t; i++)
        suma = suma + pow(-1, i) / (2.0 * i + 1.0);

    // La serie da π/4, por eso se multiplica por 4 para que nos de π
    return suma * 4.0;
}

void imprimirResultado(int t, double valorPI)
{
    // Mostrar el resultado
    printf("Valor de PI con %d términos: %.10f\n", t, valorPI);
}