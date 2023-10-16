#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Header.h"
#define TAMANHO 100  // Definição da constante TAMANHO com valor 100

//Main.c -> Main do nosso projecto;

int main (){

//Inicialização de algumas varíaveis;
FILE *nomeFicheiro = fopen("ficheiro1.txt", "r");
struct Pedidos p1[TAMANHO];  // cria um vetor de 100 pedidos.
struct Transportes t1[TAMANHO]; // cria um vetor de 100 transportes.
struct Utilizacao u1[TAMANHO];
int i, f;
i = f = 0;
setlocale(LC_ALL, "Portuguese");

if (nomeFicheiro == NULL) 
{   
    wprintf(L"Erro! Não foi encontrado nenhum ficheiro\n"); 
    exit(-1);
} 

//Leitura e inserção dos dados na struct;
while (!feof(nomeFicheiro))
{
    fscanf(nomeFicheiro,"%d %d %s %f %f\n", &p1[i].ordem, &p1[i].NIF, p1[i].codigo, &p1[i].tempo, &p1[i].distancia);
    i++;
}
fclose(nomeFicheiro);

FILE *nomeFicheiro2 = fopen("ficheiro2.txt", "r");
if (nomeFicheiro2 == NULL) 
{   
    wprintf(L"Erro! Não foi encontrado nenhum ficheiro\n"); 
    exit(-1);
} 

//O mesmo processo mas agora para outro ficheiro;
while (!feof(nomeFicheiro2))
{
    fscanf(nomeFicheiro2,"%s %s %f %f\n", t1[f].codigo, t1[f].tipo, &t1[f].preco, &t1[f].autonomia);
    f++;
}
fclose(nomeFicheiro2);

//Menu que vai ter todas as opções que o projecto pede;
//Aqui vamos dar a opção de o utilizador inserir a opção que quer, depois, é claro, de ler os ficheiros de texto;
Menu(t1,p1,u1);

    return 0;
}
