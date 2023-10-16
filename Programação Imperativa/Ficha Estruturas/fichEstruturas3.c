#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

/*
2. 	Problema dos Parafusos
Numa fábrica de parafusos recolheu-se uma amostra de 1000 parafusos para medição e pesagem.
O programa permite:
•	ler os valores do peso e do comprimento de cada parafuso da amostra
•	calcular o peso médio e o comprimento médio dos parafusos da amostra
•	calcular a percentagem de parafusos com peso superior à média da amostra
•	calcular a diferença entre o parafuso mais comprido e o mais curto
*/

float calculoPesoSuperior(float peso[5][2], float media){
    float percentagem = 0;
    float total = 0;
    for (int i = 0; i < 5; i++){
        for(int f=0; f<2; f++){
            if(peso[i][f] > media && f == 1)total++;
        }
    }
    percentagem = (total/5)*100;
    return percentagem;
}

float diferencaComprimento (float comprimento[5][2]){
    float diferenca = 0;
    float menor, maior;
    maior = menor = 0;
    for (int i=0; i <5; i++){
        for(int f=0; f<2; f++){
            if(i==0 && f == 0){
                maior = menor = comprimento[i][f];
            }
            else{
                if(f==0 && comprimento[i][f] > maior) maior = comprimento[i][f];
                else if (f==0 && comprimento[i][f] < menor) menor = comprimento[i][f];
            }
        }
    }
    diferenca = maior - menor;
    return diferenca;
}

int main (){
//Indice 0 para o comprimento e 1 para o peso;
float parafusos[5][2];
float pesoMedia, comprimentoMedia, total, total2, percentagemMaior, diferenca;
pesoMedia = comprimentoMedia = total = total2 = percentagemMaior = diferenca = 0; 
int i, f;
i = f = 0;
setlocale(LC_ALL, "Portuguese");

for (i=0; i<5; i++){
    for(f=0; f<2; f++){
        if (f==0){
            wprintf(L"Digite o comprimento do %dº parafuso:",i+1);
            scanf("%f",&parafusos[i][f]);
            total = total + parafusos[i][f];
        }
        else{
            wprintf(L"Digite o peso do %dº parafuso:",i+1);
            scanf("%f",&parafusos[i][f]);
            total2 = total2 + parafusos[i][f];
        }
    }
}
pesoMedia = total2/5;
comprimentoMedia = total/5;
printf("\n----------------------------------------");
printf("\nMedia do peso dos parafusos: %2.f",pesoMedia);
printf("\nMedia do comprimento dos parafusos: %2.f",comprimentoMedia);
percentagemMaior = calculoPesoSuperior(parafusos,pesoMedia);
printf("\nPercentagem maior: %2.f", percentagemMaior);
diferenca = diferencaComprimento(parafusos);
printf("\nDiferenca entre o maior e o menor parafuso: %2.f", diferenca);

    return 0;
}