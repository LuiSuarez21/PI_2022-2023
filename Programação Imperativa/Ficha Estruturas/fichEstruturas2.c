#include <stdio.h>
/*
1. 	Somatório de inteiros
Pretende-se um programa em C capaz de ler uma sequência de 20 números 
inteiros positivos e de calcular a soma dos números menores do que 10.

*/
int main (){

int numeros [5];
int i, soma;
i = soma = 0;

for (i=0; i<5; i++){
    printf("Escreva o %d numero:", i+1);
    scanf("%d",&numeros[i]);
    if(numeros[i] < 10) soma = soma + numeros[i];
}
printf("\nSoma dos numeros menores que 10: %d", soma);
    return 0;
}