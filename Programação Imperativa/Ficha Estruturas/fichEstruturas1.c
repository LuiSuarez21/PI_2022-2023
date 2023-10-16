#include <stdio.h>
#include <stdlib.h>

/*
1. 	Operações sobre as notas de 80 alunos
Programa que lê as notas de um conjunto de 80 alunos, armazena-as num array e calcula:
•	a média das notas e o número de notas acima da média
•	a maior nota e a quantidade de alunos que tiveram a maior nota
•	a menor nota e os índices (posição do array) dos alunos que tiveram a menor nota
•	o número de alunos com nota negativa (<10)

*/
int main (){

float notas [5];
int opc, nMaiorMedia, i, n;
opc = nMaiorMedia = i = n =  0;
float media, total, maiorNota;
media = total = maiorNota  = 0;
while (opc != 5)
{
system("cls");
printf("\n-----------------------------------");
printf("\nResultados:");
printf("\nMaior nota: %2.f",maiorNota);
printf("\nNumero: %d",n);
printf("\nMedia: %2.f", media);
printf("\nNotas a cima da media: %d", nMaiorMedia);
printf("\nNumero de notas negativas: %d", n);
printf("\n-----------------------------------");
printf("\n1)A media das notas e o numero de notas acima da media;");
printf("\n2)A maior nota e a quantidade de alunos que tiveram a maior nota;");
printf("\n3)A menor nota e os indices (posicao do array) dos alunos que tiveram a menor nota;");
printf("\n4)O numero de alunos com nota negativa (<10);");
printf("\n5)Sair;");
scanf("%d",&opc);

switch (opc)
{
case 1:
    for (i = 0; i < 5; i++){
    printf("\nInsira a nota %d:", i+1);
    scanf("%f",&notas[i]);
    total = total + notas[i];
    }
    media = total/5;
    for (i = 0; i < 5; i++){
    if (notas[i] > media)nMaiorMedia++;
    }
    
    break;
case 2:
    for (i = 0; i < 5; i++){
        if (i==0)maiorNota = notas[i];
        else if(i!=0 && maiorNota < notas[i])maiorNota = notas[i];
    }
    for (i=0; i<5; i++){
        if(notas[i]==maiorNota)n++;
    }
    
    break;
case 4:
    n = 0;
    for(i=0; i<5; i++){
        if(notas[i] < 10)n++;
    }
    break;
default:
    break;
}

}

    return 0;
}