#include <stdio.h>
/*
Maior de dois números
Programa que lê dois números inteiros e escreve na consola qual o maior.
No caso de serem iguais, deve escrever “Os números são iguais!!”.
*/

int main (){

int numero, numeros;

printf("Escreva o primeiro numero:");
scanf("%d",&numero);
printf("Escreva o segundo numero:");
scanf("%d",&numeros);

if (numero > numeros && numero > 0)
    printf("O primeiro numero e maior!");

else if(numeros > 0 && numeros > numero)
    printf("O segundo numero e maior!");



    return 0;
}
