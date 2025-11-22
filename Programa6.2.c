#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592

// Prototipos
float triangulo(float, float);
float triangulo2(float, float, float);
float circulo(float);
float circulo2(float);
float rectangulo(float, float);
float rectangulo2(float, float);
float rombo(float, float);
float rombo2(float, float);
float trapecio(float, float, float);
float trapecio2(float, float, float);
void Limpieza();

// Función área círculo
float circulo(float no) {
	return PI*(no*no);
}

// Función perímetro círculo
float circulo2(float no) {
	return PI*(2*no);
}

// Función área Rectángulo
float rectangulo(float lado, float lado1) {
	return lado*lado1;
}

// Función perímetro rectángulo
float rectangulo2(float lado, float lado1) {
	return (lado*2)+(2*lado1);
}

// Función área triángulo
float triangulo(float base, float altura) {
	return (base*altura)/2;
}

// Función perímetro triángulo
float triangulo2(float base, float lado1t,float lado2t) {
	return base+lado1t+lado2t;
}

// Función área rombo
float rombo(float diametromay, float diametromen) {
	return (diametromay*diametromen)/2;
}

// Función perímetro rombo
float rombo2(float diametromay, float diametromen) {
	float ayuda, help;
	ayuda= diametromay/2;
	help= diametromen/2;
	return 4*(sqrt((pow(ayuda,2))+(pow(help,2))));
}

// Función área trapecio
float trapecio(float basemay, float basemen, float alturatrap) {
	return ((basemay + basemen) * alturatrap) / 2;
}

// Función perímetro trapecio
float trapecio2(float basemay, float basemen, float alturatrap) {
	float need;
	need=((basemay-basemen)/2);
	return basemay+basemen+(2*(sqrt((pow(need,2))+(pow(alturatrap,2)))));
}

// Función limpiar buffer
void Limpieza() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Función carátula
void Caratula(){
puts("Equipo 1\n"
    "Integrantes:\n"
    "1. Contreras Aviles José Raúl.\n"
    "2. Hernández Tovar Evelyn Ariadna.\n"
    "3. Rosas Fragoso Leonardo.\n"
    "4. Rosas Vázquez Eduardo.\n"
    "5. Zamitiz Carmona Cristian Erasto.");
puts("Presiona Enter");
getchar();
system("clear");
}

int main()
{
     Caratula();

	int caso, control = 1;
	int controltri1, controltri2, controltri3;

	do {
		// Menú
		puts("Programa 6\n"
		"Mediante un menú de opciones, calcular el área y perímetro de las siguientes figuras geométricas.\n"
		"Escoge cuál figura deseas calcular su Área y perímetro:");
		do {
			printf("1.-Círculo.\n");
			printf("2.-Rectángulo.\n");
			printf("3.-Triángulo.\n");
			printf("4.-Rombo.\n");
			printf("5.-Trapecio.\n");
			printf("6.-Salir.\n");

			scanf("%d", &caso);
			Limpieza();

			// Repetición del menú
			if (caso<=0||caso>6) {
				puts("\n\nEso no está dentro del menú, seleccione un número dentro del menú (entre 1-6)");
			}
		} while(caso<=0||caso>6);

		system("clear");

		if (caso == 6) {
			control = 0;
			puts("Preparando para salir del programa...");
			break;
		}
		// Elección de casos válidos
		switch (caso){
		case 1:
			// Entrada de datos del círculo
			float radio;
			puts("Inserta el radio del círculo:");
			scanf("%f", &radio);
			Limpieza();
			if (radio<=0) {
				puts("\nNo se puede sacar un área con esa medida.\n");
			}else{
				printf("El área del círculo es %f y el perímetro del círculo es %f.\n",circulo(radio), circulo2(radio));
			}
			break;

		case 2:
			// Entrada de datos del rectángulo
			float lado, lado1;
			puts("Inserta una medida del lado del rectángulo:");
			scanf("%f", &lado);
			Limpieza();
			puts("Inserta una medida de otro lado del rectángulo:");
			scanf("%f", &lado1);
			Limpieza();
			if(lado<=0||lado1<=0) {
				puts("\nNo se puede sacar un área con esa medida.\n");
			}else
			{
				printf("El área del rectángulo es %f y su perímetro es %f.\n",rectangulo(lado, lado1), rectangulo2(lado, lado1));
			}
			break;

		case 3:
			// Entrada de datos del triángulo
			float base, altura, lado1t, lado2t;
			puts("Inserta la medida de la base del triángulo:");
			scanf("%f", &base);
			Limpieza();
			puts("Inserta la medida de un lado del triángulo que no sea de la base:");
			scanf("%f", &lado1t);
			Limpieza();
			puts("Inserta la medida de un lado del triángulo que no sea de la base ni el anterior:");
			scanf("%f", &lado2t);
			Limpieza();
			
			controltri1=base+lado1t;
			controltri2=base+lado2t;
			controltri3=lado1t+lado2t;
			
			puts("Inserta la medida de la altura del triángulo:");
			scanf("%f", &altura);
			Limpieza();
			if((base<=0)||(altura<=0)||(lado1t<=0)||(lado2t<=0)||((controltri1<=lado2t)||(controltri2<=lado1t)||(controltri3<=base))) {
				puts("\nNo se puede sacar un área con esas medidas.\n");
			} else {
				printf("El área del triángulo es %f y su perímetro es %f.\n",triangulo(base, altura), triangulo2(base, lado1t, lado2t));
			}
			break;

		case 4:
			// Entrada de datos del rombo
			float diametromay, diametromen;
			puts("Inserta la medida del diámetro mayor del rombo:");
			scanf("%f", &diametromay);
			Limpieza();
			puts("Inserta la medida del diámetro menor del rombo:");
			scanf("%f", &diametromen);
			Limpieza();
			if ((diametromay<=0)||(diametromen<=0)||(diametromay<diametromen)) {
				puts("\nNo se puede sacar un área con esa medida.\n");
			} else {
				printf("El área del rombo es %f y su perímetro es %f.\n",rombo(diametromay, diametromen), rombo2(diametromay, diametromen));
			}
			break;

		case 5:
			// Entrada de datos del trapecio
			float basemay, basemen, alturatrap;
			puts("Inserta la medida de la base mayor del trapecio:");
			scanf("%f", &basemay);
			Limpieza();
			puts("Inserta la medida de la base menor del trapecio:");
			scanf("%f", &basemen);
			Limpieza();

			puts("Inserta la medida de la altura del trapecio:");
			scanf("%f", &alturatrap);
			Limpieza();
			if ((basemay<=0)||(basemen<=0)||(alturatrap<=0)||(basemay<basemen)) {
				puts("\nNo se puede sacar un área con esas medidas.\n");
			} else {
				printf("El área del trapecio es %f y su perímetro es %f\n",trapecio(basemay, basemen, alturatrap), trapecio2(basemay, basemen, alturatrap));
			}
			break;
		}

		if (caso != 6) {
			puts("\n¿Desea calcular algo más (1=si)? \n");
			
			if (scanf("%d", &control) != 1) {
				control = 0;
			}
			Limpieza();
		}

	} while(control == 1);

	system("clear");
	puts("Fin del programa");
	
	return 0;
}
