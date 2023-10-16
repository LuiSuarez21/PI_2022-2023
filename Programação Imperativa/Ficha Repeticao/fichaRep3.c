#include <stdio.h>
#include <stdlib.h>
/*
17. 	Factorial
Programa que calcula o fatorial de um valor inteiro positivo
Ex: 0!=1; 1!=1; 5!=1x2x3x4x5= 120; 6!=1x2x3x4x5x6= 720

*/
int main (){

int i, num, fact, resultado;
i = num = fact = 0;
resultado = 1;

printf("Introduza o numero: ");
scanf("%d",&num);

if (num != 0 && num != 1){
    do
    {
        resultado = resultado * num;
        num = num - 1;

    } while (num > 1);

printf("\n\nResultado : %d", resultado);

}

else{
        if (num == 0)
        {
            resultado = 1;
            printf("\n\nResultado : %d", resultado);
        }
        if (num == 1)
        {
            resultado = 1;
            printf("\n\nResultado : %d", resultado);
        }
}


    return 0;
}