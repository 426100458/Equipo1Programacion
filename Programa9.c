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

void Caratula()
{
	puts("\nPrograma 09 - Calculo de Combinaciones.\n");
	
	puts("Este programa calcula cuantos grupos diferentes de 'm' elementos se pueden formar a partir de 'n' elementos. Formula: C = n! / (m! * (n-m)!)\n");
	
	puts("1. Contreras Aviles Jose Raul.\n"
	     "2. Hernandez Tovar Evelyn Ariadna.\n"
		 "3. Rosas Fragoso Leonardo.\n"
		 "4. Rosas Vazquez Eduardo.\n"
		 "5. Zamitiz Carmona Cristian Erasto.\n");
		
	printf("Presiona cualquier tecla para continuar...");
	getchar(); 
	
	system("clear");
}

void PedirValorUsuario(int *n, int *m)
{
    puts("--- CALCULO DE COMBINACIONES---\n");
    printf("Introduce el numero total de elementos enteros positivos disponibles (que seran el valor n) IMPORTANTE EL VALOR DEBE SER <= 20: ");
    scanf("%d", n);

    printf("Introduce el numero de elementos a elegir del total de enteros positivos disponibles (que seran el valor m): ");
    scanf("%d", m);
    
    while (getchar() != '\n');
    
	system("clear");
    
}

unsigned long long CalcularFactorial(int num)
{
    if (num == 0) 
    {
        return 1;
    }

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
        printf("Error: El programa no puede calcular factoriales de numeros mayores a 20 (n=%d).\n", n);
        printf("Por favor, introduce un valor (n) de 20 o menos.\n");
        FuncionPausa();
        return 0;
    }
    else if ((n < 0) || (m < 0))
    {
        printf("Error: Los numeros deben ser enteros positivos o cero.\n");
        FuncionPausa();
        return 0;
    }
    else if  (m > n)
    {
        printf("Error: El numero a elegir (m = %d) no puede ser mayor que el total (n = %d).\n", m, n);
        FuncionPausa();
        return 0;
    }
    else
    {
        return 1;
    }
}

void FuncionPausa()
{
    printf("Presiona enter para continuar...");
    while( getchar() != '\n' );
    system("clear"); 
}

void MostrarResultado(unsigned long long factorialN, unsigned long long factorialM, unsigned long long factorialNM, int n, int m)
{
    unsigned long long combinaciones = factorialN / (factorialM * factorialNM);
    
    printf("Resultado:\n");
    printf("De %d elementos totales, se pueden formar %llu grupos distintos de %d elementos.\n", n, combinaciones, m);
    
    FuncionPausa();
}

int SeguirEjecutando(int *ejecutar)
{
    int seleccion = 0;
    
    puts("Realizar otro calculo?\n");
    printf("Ingrese 1 para 'Si' (o cualquier otra tecla + enter para 'No'): ");
    
    if (scanf("%d", &seleccion) != 1) {
        seleccion = 0; 
    }
    
    while( getchar() != '\n' );
    
    if (seleccion == 1) 
    {
        *ejecutar = 1; 
    } 
    else 
    {
        *ejecutar = 0;
    }

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
