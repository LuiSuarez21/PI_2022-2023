#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Header.h"



//Func2.c -> Criamos este segundo ficheiro para guardar funções,
//           para facilitar a compreensão e o funcionamento do projecto;



//Lê o ficheiro Ficheiro1.txt, guarda os valores na struct e retorna o numero de linhas preenchidas;
int Ler_Fich1(struct Pedidos p1[]){
    FILE *nomeFicheiro2 = fopen("ficheiro1.txt", "r");
    int i = 0;
    if (nomeFicheiro2 == NULL) 
    {   
        wprintf(L"Erro! Não foi encontrado nenhum ficheiro\n"); 
        exit(-1);
    } 

    //O mesmo processo mas agora para outro ficheiro;
    while (!feof(nomeFicheiro2))
    {
        fscanf(nomeFicheiro2,"%d %d %s %f %f\n", &p1[i].ordem, &p1[i].NIF, p1[i].codigo, &p1[i].tempo, &p1[i].distancia);
        i++;
    }
    fclose(nomeFicheiro2);

    return (i);
}


//Lê o ficheiro Ficheiro2.txt, guarda os valores na struct e retorna o numero de linhas preenchidas;
int Ler_Fich2(struct Transportes t1[]){
    FILE *nomeFicheiro2 = fopen("ficheiro2.txt", "r");
    int f = 0;
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

    return (f);
}


//Compara os Códigos que existem no Ficheiro2.txt e uma possível inserção no mesmo;
int Comparar_Strings(char codigo [], int count, struct Transportes t1[], int tipo){
    int i = 0;
    int verificar = 1;
    //No caso de tipo = 0, então a função vai retornar apenas se a palavra existe ou não no array;
    if (tipo == 0){
        for (i = 0; i <= count; i++){
            if (verificar != 0) verificar = strcmp(codigo, t1[i].codigo);
        }
        return verificar;
    }
    //No caso de tipo = 1, vai retornar a linha em que se encontra a palavra repetida;
    else if (tipo == 1){
        int aux = 0;
        for (i = 0; i <= count; i++){
            if (verificar != 0) {
            verificar = strcmp(codigo, t1[i].codigo);
            aux = i;
            //Esvaziar o espaço da struct que contêm os dados que queremos eliminar;
            if(verificar == 0){
                memset(t1[aux].codigo,0,strlen(t1[aux].codigo));
                t1[aux].autonomia = 0;
                t1[aux].preco = 0;
                memset(t1[aux].tipo,0,strlen(t1[aux].tipo));
            }

            }
        }
    return aux;
    }
}



