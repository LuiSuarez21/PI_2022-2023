#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Transportes
{
    char codigo[5];
    char tipo[20];
    float preco;
    float autonomia;
};

int main (){
struct Transportes t1[100];  // cria um vetor de 100 pedidos.
FILE *nomeFicheiro2 = fopen("ficheiro2.txt", "r");
int f = 0;
setlocale(LC_ALL, "Portuguese");

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

Insercao_Dados_Fich2(f,t1);

    return 0;
}

//3. InserÃ§Ã£o de um novo meio de mobilidade elÃ©trica;
void Insercao_Dados_Fich2(int count, struct Transportes t1[]){

    FILE *nomeFicheiro = fopen("ficheiro2.txt", "w");
    setlocale(LC_ALL, "Portuguese");
    int verificacao = 0;
    //Exemplo: M_1 Trotinete 0,20 15
    printf("\n---------------------------");
    wprintf(L"\n3. Inserção de um novo meio de mobilidade elétrica;");
    wprintf(L"\nCódigo do transporte: ");
    scanf("%s",t1[count].codigo);
    printf("\nTipo de transporte: ");
    scanf("%s",t1[count].tipo);
    wprintf(L"\nPreçoo: ");
    scanf("%f",&t1[count].preco);
    printf("\nAutonomia: ");
    scanf("%f",&t1[count].autonomia);
    verificacao = Verifica(t1[count].codigo,t1,count+1);
    if (verificacao == 0){
        for (int i = 0; i <= (count); i++){
            fprintf(nomeFicheiro,"%s %s %.2f %.2f\n", t1[i].codigo, t1[i].tipo, t1[i].preco, t1[i].autonomia);
        }
        fclose(nomeFicheiro);
    }
    else{printf("\n\nCodigo ja existente! Insira outro por favor;");}
}


int Verifica(char Codigo[],struct Transportes t1[], int count){
    int i = 0;
    for (int f = 0; f <= count; f++){
        if(t1[f].codigo == Codigo)return 1;
    }
    return 0;
}
