//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

//PROTOTTIPOS
void Caratula();
void Primos(int);

//FUNCIONES
void Caratula()
{
	//Titulo
	puts("\nPrograma 11 - Primos.\n");

	//Descripccion
	puts("Este programa determina si un nC:mero N, entero positivo, es primo\n");

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

void Primos(int numero) {
	int contador=0;
	for(int i=1; i<= numero; i++) {
		contador=0;
		for(int j=1; j<= i; j++) {
			if(i%j==0) {
				contador+= 1;
			}
		}
		if(contador == 2) {
			printf("El numero %d es numero primo\n", i);
		}
		else {
			printf("El numero %d no es un numero primo\n", i);
		}
	}
}
//FUNCION PRINCIPAL
int main(){
	int num, repetir;
	Caratula();
	do{
		printf("\nIngresa el limite superior de números que quieras analizar para saber si son números primos o no:\n");
		scanf("%d", &num);
		if(num<=0){
			printf("Ingresa un valor mayor a 0\n");
		}else{
			Primos(num);
			printf("\n¿Desea realizar otra operación? 1.- Si, (Cualquier numero).- No\n");
			scanf("%d", &repetir);
			if(repetir==1){
				system("clear");
			}
			else{
				printf("\nSaliendo...\n");
				
			}
		}
	} while (num <= 0 || repetir==1);
	
	return 0;
}
