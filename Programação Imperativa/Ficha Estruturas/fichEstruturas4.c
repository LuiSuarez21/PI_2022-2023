#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
/*
1. 	Dados de atleta e calculo do IMC 
Pretende-se registar e processar um conjunto de dados relativos aos atletas
de determinado clube desportivo.
Para cada atleta deve ser considerada a seguinte informação: 
codigo, nome, altura, peso, índice de massa corporal (IMC)
Notas:
Deve utilizar um array de registos.
Como não sabemos de quantos atletas se trata, deve usar uma sentinela na leitura dos dados.
Métodos a implementar:
Leitura e armazenamento da informação relativa a um ou mais atletas, 
armazenando também o IMC de cada atleta - IMC = peso / (altura * altura) 
Consulta da informação relativa a um atleta a partir do seu codigo, 
com a apresentação do conteúdo de todos os campos do registo.
Listagem com o codigo, nome, altura, peso e IMC de todos os atletas.
Listagem com o codigo, nome, altura, peso e IMC de todos os atletas 
cujo IMC é superior ao IMC médio do conjunto. 
*/

typedef struct 
{
    int codigo;
    char nome[20];
    float peso;
    float altura;
    float IMC;
}Atleta;

int main (){

Atleta a[100];  // cria um vetor de 100 pessoas.
int i, opc, aux, codigo, sinalizador;
float mediaImc, aux2;
i = opc = aux = codigo = sinalizador = 0;
mediaImc = aux2 = 0;

while (opc != 1)
{
    printf("\nInserir dados dos atletas;");
    printf("\nAtleta %d",aux+1);
    printf("\nNome:");
    scanf("%s",a[aux].nome);
    printf("\nCodigo:");
    scanf("%d",&a[aux].codigo);
    printf("\nPeso:");
    scanf("%f",&a[aux].peso);
    printf("\nAltura:");
    scanf("%f",&a[aux].altura);
    a[aux].IMC = a[aux].peso / (a[aux].altura * a[aux].altura);
    mediaImc = mediaImc + a[aux].IMC;
    printf("\n------------------------------------------");
    printf("\nDeseja inserir outro atleta? (1-Nao|Qualquer outro numero-Sim):\n");
    scanf("%d",&opc);
    aux++;
}
opc = 0;
aux = aux - 1;
aux2 = aux;
mediaImc = mediaImc/aux2;
while (opc != 4)
{
    sinalizador = 0;
    printf("\n-------------------------------------");
    printf("\n1)Procurar por um atleta;");
    printf("\n2)Listagem de todos os atletas;");
    printf("\n3)Todos os atletas cujo IMC e superior ao IMC medio do conjunto");
    printf("\n4)Sair;");
    printf("\nDigite a opcao que quer:");
    scanf("%d",&opc);
    switch (opc)
    {
    case 1:
        printf("\n-------------------------------------------");
        printf("\nDigite o codigo do atleta que procura:");
        scanf("%d",&codigo);
        for (i=0;i<=aux;i++){
            if(a[i].codigo == codigo){
                printf("\nAtleta encontrado!");
                printf("\nNome: %s",a[i].nome);
                printf("\nCodigo: %d",a[i].codigo);
                printf("\nAltura: %2.f",a[i].altura);
                printf("\nPeso: %2.f",a[i].peso);
                printf("\nIMC: %2.f",a[i].IMC); 
                sinalizador++;               
            }
            else if (sinalizador == 0 && aux == i){
                printf("Atleta nao encontrado!");
            }
        }
        break;
    case 2:
        for (i=0; i<=aux; i++){
            printf("\n-------------------------------------------");
            printf("\nImformacao do atleta %d",i+1);
            printf("\nNome: %s",a[i].nome);
            printf("\nCodigo: %d",a[i].codigo);
            printf("\nAltura: %2.f",a[i].altura);
            printf("\nPeso: %2.f",a[i].peso);
            printf("\nIMC: %2.f",a[i].IMC); 
        }
        break;
    case 3:
        
        for (i=0; i<=aux; i++){
            if (a[i].IMC > mediaImc){
            printf("\n-------------------------------------------");
            printf("\nImformacao do atleta %d com IMC mais alto que a media;",i+1);
            printf("\nNome: %s",a[i].nome);
            printf("\nCodigo: %d",a[i].codigo);
            printf("\nAltura: %2.f",a[i].altura);
            printf("\nPeso: %2.f",a[i].peso);
            printf("\nIMC: %2.f",a[i].IMC);
            sinalizador++; 
            }
            else if(sinalizador == 0 && i == aux)printf("\nNenhum atleta tem o IMC mais alto que a media!");
        }
        break;
    default:
        break;
    }
}


    return 0;
}