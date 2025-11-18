#include <stdio.h>
#include <stdlib.h>

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

void Limpiar() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void Factorial(){
    int factorial, eleccion;
    unsigned long long resultado; 

    do{
        puts("Programa 8 (Factorial)");
        puts("Calcular el factorial de un número entero positivo (no usar recursividad)");
        
        puts("Ingresa el número al que deseas encontrar su factorial (no mayor a 20)): ");
        
        if (scanf("%d", &factorial) != 1) {
            puts("Error: Entrada no válida (debe ser un número entero).");
            Limpiar();
            factorial = -1;
        }
        Limpiar();

        if (factorial < 0){
            puts("El factorial no está definido para números negativos.");
        } else if (factorial > 20){
            puts("El número es demasiado grande, el resultado será incorrecto con unsigned long long (20! es el límite).");
        } else {
            resultado = 1;
            
            if (factorial > 0) {
                for (int i = 1; i <= factorial; i++){
                    resultado *= i;
                }
            }

            printf("El factorial de %d es: %llu\n", factorial, resultado);
        }
        
        puts("Deseas repetir el programa (1=si)?");
        scanf("%d", &eleccion);
        if (eleccion != 1) {
             eleccion = 0;
        }
        Limpiar();

        system("clear");
        
        if(eleccion != 1){
            puts("Fin del programa");
        }
        
    } while (eleccion == 1);
}

int main(){
    Caratula();
    Factorial();
    return 0;
}
