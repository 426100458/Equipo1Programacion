#include <stdio.h>
#include <stdlib.h>

void Caratula();
void Primos(int);

void Caratula()
{
	
	puts("Equipo 1\n"
	     "Integrantes:\n"
	     "1. Contreras Aviles José Raúl.\n"
	     "2. Hernández Tovar Evelyn Ariadna.\n"
	     "3. Rosas Fregoso Leonardo.\n"
	     "4. Rosas Vázquez Eduardo.\n"
	     "5. Zamitiz Carmona Cristian Erasto.");
	printf("Presiona Enter");
	getchar();
	system("clear");
}

void Primos(int numero) {
	int contador;
	for(int i = 1; i <= numero; i++) {
		contador = 0;
		for(int j = 1; j <= i; j++) {
			if(i % j == 0) {
				contador += 1;
			}
		}
		if(contador == 2) {
			printf("El número %d es número primo\n", i);
		}
		else {
			printf("El número %d no es un número primo\n", i);
		}
	}
}

int main(){
	int num, repetir;
	Caratula();
	do{
	    puts("Programa 11 - Primos.");
	    puts("Este programa determina si un número N, entero positivo, es primo\n");
		puts("Ingresa el límite superior de números que quieras analizar para saber si son números primos o no:");
		scanf("%d", &num);
		if(num <= 0){
			printf("Ingresa un valor mayor a 0\n");
		}else{
			Primos(num);
			printf("\n¿Desea realizar otra operación? 1.- Sí, (Cualquier número).- No\n");
			scanf("%d", &repetir);
			if(repetir == 1){
				system("clear");
			}
			else{
				printf("\nSaliendo...\n");
				
			}
		}
	} while (num <= 0 || repetir == 1);
	
	return 0;
}
