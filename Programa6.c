#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592


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


float circulo(float no) {
	return PI*(no*no);
}

float circulo2(float no) {
	return PI*(2*no);
}

float rectangulo(float lado, float lado1) {
	return lado*lado1;
}

float rectangulo2(float lado, float lado1) {
	return (lado*2)+(2*lado1);
}

float triangulo(float base, float altura) {
	return (base*altura)/2;
}

float triangulo2(float base, float lado1t,float lado2t) {
	return base+lado1t+lado2t;
}

float rombo(float diametromay, float diametromen) {
	return (diametromay*diametromen)/2;
}

float rombo2(float diametromay, float diametromen) {
	float ayuda, help;
	ayuda= diametromay/2;
	help= diametromen/2;
	return 4*(sqrt((pow(ayuda,2))+(pow(help,2))));
}

float trapecio(float basemay, float basemen, float alturatrap) {
	return (basemay*basemen*alturatrap)/2;
}

float trapecio2(float basemay, float basemen, float alturatrap) {
	float need;
	need=((basemay-basemen)/2);
	return basemay+basemen+(2*(sqrt((pow(need,2))+(pow(alturatrap,2)))));
}

void Caratula(){
    puts("Equipo 1\n"
         "Integrantes:\n"
         "1. Contreras Aviles José Raúl.\n"
         "2. Hernández Tovar Evelyn Ariadna.\n"
         "3. Rosas Fragoso Leonardo.\n"
         "4. Rosas Vázquez Eduardo.\n"
         "5. Zamitiz Carmona Cristian Erasto.\n");
    puts("Presiona Enter");
    getchar();
    system("clear");
}

int main()
{
    caratula();
    
	int caso, control, control1, controltri1, controltri2, controltri3;

	do {
		puts("\nEscoge cual figura deseas calcular su C!rea y perC-metro:\n");
		do {
			printf("1.-Circulo.\n");
			printf("2.-Rectangulo.\n");
			printf("3.-Triangulo.\n");
			printf("4.-Rombo.\n");
			printf("5.-Trapecio.\n\n");
			printf("6.-Salir.\n\n");

			scanf("%d", &caso);

			if (caso<=0||caso>6) {
				puts("\n\nEso no estC! dentro del menC:, selecciC3ne un nC:mero dentro del menC: (entre 1-5)");
			}
		} while(caso<=0||caso>6);

		getchar();
		system("clear");

		switch (caso){
		case 1:
			float radio;
				puts("\nInserta el radio del cC-rculo:\n");
			scanf("%f", &radio);
			if (radio<=0) {
				puts("\nNo se puede  sacar un C!rea con es medida.\n");
			}else{
				printf("El area del circulo es %f y el perC-metro del cC-rculo es %f.\n",circulo(radio), circulo2(radio));
				control=1;
			}
			break;

		case 2:
			float lado, lado1;
			puts("\nInserta una medida del lado del rectangulo:\n");
			scanf("%f", &lado);
			puts("\nInserta una medida de otro lado del rectangulo:\n");
			scanf("%f", &lado1);
			if(lado<=0||lado1<=0) {
				puts("\nNo se puede  sacar un C!rea con es medida.\n");
			}else
			{
				printf("El area del rectangulo es %f y su perC-metro es %f.\n",rectangulo(lado, lado1), rectangulo2(lado, lado1));
				control=1;
			}
			break;

		case 3:
			float base, altura, lado1t, lado2t;
			puts("\nInserta la medida de la base del triangulo:\n");
			scanf("%f", &base);
			puts("\nInserta la medida de un lado del triangulo que no sea de la base:\n");
			scanf("%f", &lado1t);
			puts("\nInserta la medida de un lado del triangulo que no sea de la base ni el anterior:\n");
			scanf("%f", &lado2t);
			//control de triangulos
			controltri1=base+lado1t;
			controltri2=base+lado2t;
			controltri3=lado1t+lado2t;
			puts("\nInserta la medida de la altura del triangulo:\n");
			scanf("%f", &altura);
			if((base<=0)||(altura<=0)||(lado1t<=0)||(lado2t<=0)||((controltri1<=lado2t)||(controltri2<=lado1t)||(controltri3<=base))) {
				puts("\nNo se puede  sacar un C!rea con esas medidas.\n");
			} else {
				printf("El area del triangulo es %f y su perC-metro es %f.\n",triangulo(base, altura), triangulo2(base, lado1t, lado2t));
				control=1;
			}
			break;

		case 4:
			float diametromay, diametromen;
			puts("\nInserta la medida del diametro mayor del rombo:\n");
			scanf("%f", &diametromay);
			puts("Inserta la medida del diametro menor del rombo:\n");
			scanf("%f", &diametromen);
			if ((diametromay<=0)||(diametromen<=0)||(diametromay<diametromen)) {
				puts("\nNo se puede  sacar un C!rea con es medida.\n");
			} else {
				printf("El area del rombo es %f y su perC-metro es %f.\n",rombo(diametromay, diametromen), rombo2(diametromay, diametromen));
				control=1;
			}
			break;

		case 5:
			float basemay, basemen, alturatrap;
			puts("\nInserta la medida de la base mayor del trapecio:\n");
			scanf("%f", &basemay);
			puts("Inserta la medida de la base menor del trapecio:\n");
			scanf("%f", &basemen);

			puts("Inserta la medida de la altura del trapecio:\n");
			scanf("%f", &alturatrap);
			if ((basemay<=0)||(basemen<=0)||(alturatrap<=0)||(basemay<basemen)) {
				puts("\nNo se puede  sacar un C!rea con esas medidas.\n");
			} else {
				printf("El area del trapecio es %f y su perC-metro es %f\n",trapecio(basemay, basemen, altura), trapecio2(basemay, basemen, altura));
				control=1;
			}
			break;

		default:
			puts("preparando para salir del programa...\n");
			control=2;
			getchar();
			break;
		}

		if (control!=2) {
			puts("\nDesea calcular algo mÃ¡s? (SI = 1, NO = 2): \n");
			scanf("%d", &control);
		}

	} while(control!=2);

	if (control==2) {
		system("clear");
		puts("Saliendo del programa...\n");
		getchar();
		puts("\nSe ha salido del programa con Ã©xito.\n");
	}
	return 0;
}
