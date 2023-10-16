#include <stdio.h>
/*
Nota final do aluno
Programa que lê os seguintes dados de um aluno:
- o número de identificação do aluno
- 3 notas do aluno
- a média dos exercícios que fazem parte da avaliação (numa escala inteira de 0 a 20 valores).
Calcula a média de aproveitamento, usando a fórmula: MA = ( N1 + 2 x N2 + 3x N3 + ME ) / 7
A avaliação final é expressa em função de MA da seguinte forma:
 >= 17 (A), >= 14 e < 17 (B), >= 10 e < 14 (C), >= 8 e < 10 (D), menor que 8 (E).
*/
int main (){

int numero, notaA, notaB, notaC, media;
numero = notaA = notaB = notaC = media = 0;

//Aqui sã introduzidas as notas;
printf("Introduza o numero do aluno:");
scanf("%d",&numero);
printf("Introduza a primeira nota:");
scanf("%d",&notaA);
printf("Introduza a segunda nota:");
scanf("%d",&notaB);
printf("Introduza a terceira nota:");
scanf("%d",&notaC);
printf("Introduza a media (em inteiro):");
scanf("%d",&media);

float ma;
ma = ((notaA + 2 * notaB + 3*notaC + media)/7);

int notafinal = 0;
if (ma >= 17)notafinal = 1; //significa A
if (ma >= 14 && ma < 17)notafinal = 2; //significa B
if (ma >= 10 && ma < 14)notafinal = 3; //significa C
if (ma >= 8 && ma < 10)notafinal = 4; //significa D
if (ma < 8)notafinal = 5; //significa E
switch (notafinal)
{
case (1):
    printf("O aluno tirou A!");
    break;

case (2):
    printf("O aluno tirou B!");
    break;

case (3):
    printf("O aluno tirou C!");
    break;

case (4):
    printf("O aluno tirou D!");
    break;

case (5):
    printf("O aluno tirou E!");
    break;

default:
    printf("Erro!");
    break;
}



    return 0;
}