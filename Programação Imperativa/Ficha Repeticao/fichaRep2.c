#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
/*
18. 	Escrever sequência por ordem inversa
Ler uma sequência de 20 números inteiros positivos
 e de escrevê-la pela ordem inversa da sua leitura.

*/
int main (){

int i, num;
i = num = 0;
int numContra[20];

for (i = 0; i < 20; i++){
    printf("Numero %d: ",i+1);
    scanf("%d",&num);
    numContra[i] = num;
}

printf("\n\n------------------------------------\n");
for (i = 19; i >= 0 ; i--)
{
    printf("\n%d;", numContra[i]);
}


    return 0;
}