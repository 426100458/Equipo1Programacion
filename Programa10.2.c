#include <stdio.h>
#include <stdlib.h>

void Caratula();
void ObtenerDivisores(int);

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

void ObtenerDivisores(int n) {
	printf("Sus divisores de %d son: ", n);

	if (n > 0) {
		for(int i = 1; i <= n; i++) {
			if(n % i == 0) {
				printf("%d ", i);
			}
		}
	} else {
		for(int i = n; i <= -n; i++) {
			if(i != 0 && n % i == 0) {
				printf("%d ", i);
			}
		}
	}
	printf("\n");
}

int main()
{
	int num, repetir;
	Caratula();
	do {
	    puts("Programa 10 (Divisores).");
	    puts("Obtener todos los divisores de un número entero N.\n"
	    "El programa debe contener una función que se llame 'ObtenerDivisores' que reciba como parámetro un número entero y que imprima los divisores encontrados de ese número.");
		printf("Ingrese un número: ");
		scanf("%d", &num);
		if(num != 0) {
			ObtenerDivisores(num);
		} else {
			printf("El número 0 no tiene divisores.\n");
		}
		printf("¿Desea realizar otra operación? 1. Sí, (Cualquier otro número).- No\n");
		scanf("%d", &repetir);
		if(repetir==1) {
			system("clear");
		}
		else {
			printf("\nSaliendo...\n");
		}
	} while(repetir==1);
	return 0;
}
