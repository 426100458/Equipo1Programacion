// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

// PROTOTIPOS
void Caratula();
void Primos(int);

// FUNCIÓN PRINCIPAL
int main()
{
	int num, repetir;
	Caratula();
	do
	{
		printf("Ingrese un número entero positivo: \n");
		scanf("%d", &num);
		// Validación de número positivo
		if (num <= 0)
		{
			printf("Ingresa un valor mayor a 0\n");
		}
		else
		{
			// Llamada a la función de primos
			Primos(num);
			// Opción para repetir el programa
			printf("\n¿Desea realizar otra operación? 1.- Sí, (Cualquier número).- No\n");
			scanf("%d", &repetir);
			// Limpieza de pantalla o salida
			if (repetir == 1)
			{
				system("clear");
			}
			else
			{
				printf("\nSaliendo...\n");
			}
		}
	} while (num <= 0 || repetir == 1);

	return 0;
}

// FUNCIONES
void Caratula()
{
	// Titulo
	puts("Programa 11 - Primos.\n");

	// Descripción
	puts("Este programa determina si un número N, entero positivo, es primo\n");

	// Integrantes
	puts("Equipo 01\n"
		 "Integrantes:\n"
		 "1. Contreras Aviles José Raúl.\n"
		 "2. Hernández Tovar Evelyn Ariadna.\n"
		 "3. Rosas Fregoso Leonardo.\n"
		 "4. Rosas Vázquez Eduardo.\n"
		 "5. Zamitiz Carmona Cristian Erasto.\n");
	printf("Presiona Enter");
	// Pausa para leer la carátula
	getchar();
	system("clear");
}

void Primos(int numero)
{
	int contador;
	// Bucle para revisar cada número desde 1 hasta el número ingresado
	for (int i = 1; i <= numero; i++)
	{
		contador = 0;
		for (int j = 1; j <= i; j++)
		{
			// Verificar si i es divisible por j
			if (i % j == 0)
			{
				// Incrementar el contador de divisores
				contador += 1;
			}
		}
	}
	// Si el contador es 2, entonces i es primo
	if (contador == 2)
	{
		printf("El número %d es primo\n", numero);
	}
	// Si el contador nes mayor 2, entonces i no es primo
	else
	{
		printf("El número %d no es un primo\n", numero);
	}
}