//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

//PROTOTIPOS
void Caratula();
void Divisores(int);

//FUNCIONES
void Caratula() {
	//Titulo
	puts("\nPrograma 10 - Divisores.\n");

	//Descripccion
	puts("Este programa obtiene todos los divisores de un número entero N.\n");

	//Integrantes
	puts("1. Contreras Aviles José Raúl.\n"
	     "2. Hernández Tovar Evelyn Ariadna.\n"
	     "3. Rosas Fragoso Leonardo.\n"
	     "4. Rosas Vázquez Eduardo.\n"
	     "5. Zamitiz Carmona Cristian Erasto.\n");

	//Pausa
	printf("Presiona cualquier tecla para continuar...");
	getchar();

	//Limpiar consola
	system("clear");

}
void Divisores(int n) {
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
//FUNCIÓN PRINCIPAL

int main()
{
	int num, repetir;
	Caratula();
	do {
		printf("Ingrese un número: ");
		scanf("%d", &num);
		if(num != 0) {
			Divisores(num);
		} else {
			printf("El número 0 no tiene divisores.\n");
		}
		printf("¿Desea realizar otra operación? 1. Si, (Cualquier número).- No\n");
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
