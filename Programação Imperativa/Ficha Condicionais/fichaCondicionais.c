#include <stdio.h>
/*
Verifica se divisível por 3
Programa que lê um número inteiro e verifica se este é divisível por 3

*/
int main(){

int numero, resultado;


printf ("Escreva o numero:");
scanf("%d", &numero);
resultado = numero%3; // resto da divisao entre numero e 3;

if (numero > 0 && resultado == 0)printf("O numero e divisivel por 3.");
else printf("O numero nao e divisivel por 3.");

    return 0;
}