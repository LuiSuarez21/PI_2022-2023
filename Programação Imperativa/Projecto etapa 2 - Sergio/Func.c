#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Header.h"

//Func.c -> Ficheiro que vai contêm algumas funções que vamos utilizar ao longo do projecto;


//Produção de um menu;
void Menu(struct Transportes t1[], struct Pedidos p1[]){
    int opc;
    opc = 0;
    setlocale(LC_ALL, "Portuguese");
    while (opc != 14)
    {
    
    printf("\n------------------------- Menu -------------------------");
    wprintf(L"\n3. Inserção de um novo meio de mobilidade elétrica;");
    wprintf(L"\n4. Remoção de um meio de mobilidade elétrica a partir do seu código;");
    wprintf(L"\n5. Inserção de um novo pedido de utilização;");
    wprintf(L"\n6. Remoção de um pedido de utilização a partir do seu código;");
    wprintf(L"\n7. Listagem dos dados de todos os meios de mobilidade elétrica;");
    wprintf(L"\n8. Listagem de todo os pedidos de utilização;");
    wprintf(L"\n9. Cálculo do custo associado a um pedido de utilização a partir da indicação do seu número de ordem;");
    wprintf(L"\n10. Distribuição dos meios de mobilidade pelos vários utilizadores;");
    wprintf(L"\n11. Listagem do plano de utilização de um determinado meio de mobilidade elétrica;");
    wprintf(L"\n12. Armazenamento dos pedidos de utilização em ficheiro;");
    wprintf(L"\n13. Armazenamento dos meios de mobilidade elétrica em ficheiro;");
    printf("\n14. Sair;");
    wprintf(L"\nDigite a opção que quer ver:");
    scanf("%d",&opc);

    while (opc < 3 || opc > 14){
        printf("\nErro! Introduza um valor entre 3-14;");
        printf("\nDigite a opção que quer ver:");
        scanf("%d",&opc);
    }

    switch (opc)
    {
    case 3:
        Insercao_Dados_Fich2(t1);
        break;
    case 4:
        Eliminar_Fich2(t1);
        break;
    case 5:
        Insercao_Dados_Fich1(p1);
        break;
    case 6:
        Eliminar_Fich1(p1);
        break;
    case 7:
        Listar_Fich2(t1);
        break;
    case 8:
        Listar_Fich1(p1);
        break;
    case 9:
        break;
    case 10:
        break;
    case 11:
        break;
    case 12:
        break;
    case 13:
        break;
    default:
        break;
    }

    }
}


//3. Inserção de um novo meio de mobilidade elétrica;
void Insercao_Dados_Fich2(struct Transportes t1[]){
    int count = 0;
    int verificacao = 1;
    int tipo = 0;
    count = Ler_Fich2(t1);
    FILE *nomeFicheiro = fopen("ficheiro2.txt", "w");
    setlocale(LC_ALL, "Portuguese");
    
    //Exemplo: M_1 Trotinete 0,20 15
    printf("\n---------------------------");
    wprintf(L"\n3. Inserção de um novo meio de mobilidade elétrica;");
    wprintf(L"\nCódigo do transporte: ");
    scanf("%s",t1[count].codigo);
    printf("\nTipo de transporte: ");
    scanf("%s",t1[count].tipo);
    wprintf(L"\nPreço (por minuto): ");
    scanf("%f",&t1[count].preco);
    printf("\nAutonomia: ");
    scanf("%f",&t1[count].autonomia);
    //Guarda no array as novas imformações;
    //Compara código recebido com a struct toda, a ver se existe esse código;
    verificacao = Comparar_Strings(t1[count].codigo,count-1,t1,tipo);
    if (verificacao != 0){
        //No caso de não existir, imprime o novo ficheiro;
        for (int i = 0; i <= (count); i++){
            fprintf(nomeFicheiro,"%s %s %.2f %.2f\n", t1[i].codigo, t1[i].tipo, t1[i].preco, t1[i].autonomia);
        }
        fclose(nomeFicheiro);
    }
    else{
        //Senão, irá escrever o antigo ficheiro, antes da tentativa da inserção de um novo meio de transporte;
        printf("\n\nCodigo ja existente! Ja existem %d codigos. Insira outro por favor;",count);
        for (int i = 0; i <= (count-1); i++){
            fprintf(nomeFicheiro,"%s %s %.2f %.2f\n", t1[i].codigo, t1[i].tipo, t1[i].preco, t1[i].autonomia);
        }
        fclose(nomeFicheiro);
    }
}

//4. Remoção de um meio de mobilidade elétrica a partir do seu código;
void Eliminar_Fich2(struct Transportes t1[]){
    int count = 0;
    int verificar = 1;
    int aux = 0;
    char str [5];
    count = Ler_Fich2(t1);
    setlocale(LC_ALL, "Portuguese");
    printf("\n---------------------------");
    wprintf(L"\n4. Remoção de um meio de mobilidade elétrica a partir do seu código;");
    wprintf(L"\nInsira o código do transporte:");
    scanf("%s",str);
    verificar = Comparar_Strings(str,count,t1,0);

    if(verificar == 0){
        count = Ler_Fich2(t1);
        aux = Comparar_Strings(str,count,t1,1);
        FILE *nomeFicheiro = fopen("ficheiro2.txt", "w");
        if (nomeFicheiro == NULL) 
        {   
            wprintf(L"\nErro! Não foi encontrado nenhum ficheiro\n"); 
            exit(-1);
        }
        else{
            for(int i = 0; i < (count); i++){
                if(i != aux && t1[i].autonomia != 0) fprintf(nomeFicheiro,"%s %s %.2f %.2f\n", t1[i].codigo, t1[i].tipo, t1[i].preco, t1[i].autonomia);
            }
            wprintf(L"\nEliminação completa!");
            fclose(nomeFicheiro);
        } 
    }
    else{wprintf(L"\nCódigo não encontrado!");}

}


//5. Inserção de um novo pedido de utilização;
void Insercao_Dados_Fich1(struct Pedidos p1[]){
    int count = 0;
    count = Ler_Fich1(p1);
    FILE *nomeFicheiro = fopen("ficheiro1.txt", "w");
    setlocale(LC_ALL, "Portuguese");
    //Exemplo: 7 44448888 M_3 50 100
    printf("\n---------------------------");
    wprintf(L"\n5. Inserção de um novo pedido de utilização;");
    p1[count].ordem = count+1;
    wprintf(L"\nNIF:");
    scanf("%d",&p1[count].NIF);
    wprintf(L"\nCódigo de transporte:");
    scanf("%s",p1[count].codigo);
    wprintf(L"\nTempo de utilização:");
    scanf("%f",&p1[count].tempo);
    wprintf(L"\nDistância a percorrer (em km):");
    scanf("%f",&p1[count].distancia);

        for (int i = 0; i <= (count); i++){
            fprintf(nomeFicheiro,"%d %d %s %.2f %.2f\n", p1[i].ordem, p1[i].NIF, p1[i].codigo, p1[i].tempo, p1[i].distancia);
        }
        fclose(nomeFicheiro);
        wprintf(L"\nInserção completa!");

}


//6. Remoção de um pedido de utilização a partir do seu código;
void Eliminar_Fich1(struct Pedidos p1[]){
int i, count, ordem, verificar;
i = count = ordem  = 0;
verificar = 1;
setlocale(LC_ALL,"Portuguese");
count = Ler_Fich1(p1);

printf("\n---------------------------");
wprintf(L"\n6. Remoção de um pedido de utilização a partir do seu código;\n");
for(i = 0; i < count; i++){
    printf("%d %d %s %.2f %.2f\n", p1[i].ordem, p1[i].NIF, p1[i].codigo, p1[i].tempo, p1[i].distancia);
}
wprintf(L"Digite o código da ordem que deseja remover:");
scanf("%d",&ordem);

    for(i = 0 ;i < count; i++){
        if(p1[i].ordem == ordem){
            verificar = 0;
        }
    }
    if (verificar == 0)
    {
        FILE *nomeFicheiro = fopen("ficheiro1.txt", "w");
        for (i = 0; i < (count); i++){
            if(p1[i].ordem != ordem) fprintf(nomeFicheiro,"%d %d %s %.2f %.2f\n", p1[i].ordem, p1[i].NIF, p1[i].codigo, p1[i].tempo, p1[i].distancia);
        }
        fclose(nomeFicheiro);
        wprintf(L"\nRemoção completa!");
    }
    else{wprintf(L"\nOrdem não encontrada!");}
}


//7. Listagem dos dados de todos os meios de mobilidade elétrica;;
void Listar_Fich2(struct Transportes t1[])
{
    int count = Ler_Fich2(t1);
    setlocale(LC_ALL, "Portuguese");
    printf("\n---------------------------");
    wprintf(L"\n7. Listagem dos dados de todos os meios de mobilidade elétrica;\n");
    wprintf(L"\nCódigo  Tipo  Custo(por minuto)  Autonomia\n");
    if (count != 0) {
        for (int i = 0; i < count; i++)
        {
            printf("%s %s %.2f %.2f\n", t1[i].codigo, t1[i].tipo, t1[i].preco, t1[i].autonomia);
        }
    }
    else { printf("Erro! Não existem itens para lista"); }
}

//8. Listagem de todo os pedidos de utilização;;
void Listar_Fich1(struct Pedidos p1[]) {
    int count = Ler_Fich1(p1);
    setlocale(LC_ALL, "Portuguese");
    printf("\n---------------------------");
    wprintf(L"\n8. Listagem de todo os pedidos de utilização;\n");
    wprintf(L"\nOrdem  NIF  Código  Tempo(minutos)  Distância(km)\n");
    if (count != 0) {
        for (int i = 0; i < count; i++)
        {
            printf("%d %d %s %.2f %.2f\n", p1[i].ordem, p1[i].NIF, p1[i].codigo, p1[i].tempo, p1[i].distancia);
        }
    }
    else { printf("Erro! Não existem itens para lista"); }
}
