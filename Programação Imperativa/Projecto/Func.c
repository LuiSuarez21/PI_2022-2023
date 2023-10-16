#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Header.h"

//Func.c -> Ficheiro que vai contêm algumas funções que vamos utilizar ao longo do projecto;


//Produção de um menu;
void Menu(struct Transportes t1[], struct Pedidos p1[], struct Utilizacao u1[]){
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
        Calculo_Custo(p1, t1);
        break;
    case 10:
        Distribuir_Pedidos(p1,t1,u1);
        break;
    case 11:
        Listar_Fich3(u1);
        break;
    case 12:
        Save_Fich1(p1);
        break;
    case 13:
        Save_Fich2(t1);
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


//9. Cálculo do custo associado a um pedido de utilização a partir da indicação do seu número de ordem;
void Calculo_Custo(struct Pedidos p1[], struct Transportes t1[]) {
    int count = Ler_Fich1(p1);
    int count2 = Ler_Fich2(t1);
    int i, ordem, aux;
    i = ordem = aux = 0;
    float calculo = 0;
    setlocale(LC_ALL, "Portuguese");
    printf("\n---------------------------");
    wprintf(L"\n9. Cálculo do custo associado a um pedido de utilização a partir da indicação do seu número de ordem;\n");
    wprintf(L"Digite a ordem que quer saber o custo:");
    scanf("%d", &ordem);
    if (ordem > 0 && ordem <= count) {
        for (i = 0; i < count; i++) {
            if (p1[i].ordem == ordem)aux = i;
        }
        for (i = 0; i < count2; i++) {
            if ((strcmp(p1[aux].codigo, t1[i].codigo)) == 0) {
                calculo = t1[i].preco * p1[aux].tempo;
            }
        }
        if (calculo > 0)wprintf(L"Preço da ordem %d: %2.f euros", p1[aux].ordem, calculo);
    }
    else { wprintf(L"\nErro! Ordem não existente!"); }
}


//10. Distribuição dos meios de mobilidade pelos vários utilizadores;
void Distribuir_Pedidos(struct Pedidos p1[], struct Transportes t1[], struct Utilizacao u1[])
{
    int i, aux, aux2, verifica;
    i = aux = aux2 = verifica = 0;
    setlocale(LC_ALL, "Portuguese");
    int count = Ler_Fich1(p1);
    int count2 = Ler_Fich2(t1);
    int count3 = Ler_Fich3(u1);
    printf("\n---------------------------");
    wprintf(L"\n10. Distribuição dos meios de mobilidade pelos vários utilizadores;\n");
    for (i = 0; i < count; i++) {
        for (int f = 0; f < count2; f++)
        {
            if (((strcmp(p1[i].codigo, t1[f].codigo)) == 0) && (p1[i].distancia <= t1[f].autonomia)) {
                if (i == 0) {
                    u1[i].ordem = p1[i].ordem;
                    u1[i].NIF = p1[i].NIF;
                    u1[i].tempoInicio = 0;
                    u1[i].tempoFim = p1[i].tempo;
                    u1[i].autonomiaInicial = t1[f].autonomia;
                    strcpy(u1[i].codigo, t1[f].codigo);
                    t1[f].autonomia = t1[f].autonomia - p1[i].distancia;

                    FILE* nomeFicheiro2 = fopen("ficheiro2.txt", "w");
                    for (int j = 0; j < count2; j++) {
                        fprintf(nomeFicheiro2, "%s %s %.2f %.2f\n", t1[j].codigo, t1[j].tipo, t1[j].preco, t1[j].autonomia);
                    }
                    fclose(nomeFicheiro2);
                    aux++;
                }
                else {
                    int k = i;
                    u1[k].ordem = p1[i].ordem;
                    u1[k].NIF = p1[i].NIF;
                    count3 = Ler_Fich3(u1);
                    for (int y = 0; y < count3; y++) {
                        if ((strcmp(p1[i].codigo, u1[y].codigo)) == 0)
                        {
                            aux2 = y;
                            verifica = 1;
                        }
                        if ((y == (count3 - 1)) && verifica == 0)aux2 = -1;
                    }
                    if (aux2 != -1) {
                        u1[k].tempoInicio = u1[aux2].tempoFim;
                        u1[k].tempoFim = u1[k].tempoInicio  + p1[i].tempo;
                    }
                    else
                    {
                        u1[k].tempoInicio = 0;
                        u1[k].tempoFim = p1[i].tempo;
                    }
                 
                    u1[k].autonomiaInicial = t1[f].autonomia;
                    strcpy(u1[k].codigo, t1[f].codigo);
                    t1[f].autonomia = t1[f].autonomia - p1[i].distancia;
                    FILE* nomeFicheiro2 = fopen("ficheiro2.txt", "w");
                    for (int j = 0; j < count2; j++) {
                        fprintf(nomeFicheiro2, "%s %s %.2f %.2f\n", t1[j].codigo, t1[j].tipo, t1[j].preco, t1[j].autonomia);
                    }
                    fclose(nomeFicheiro2);
                    aux++;
                }
            }
        }
    }
    FILE* nomeFicheiro3 = fopen("ficheiro3.txt", "w");
    for (i = 0; i < aux; i++) {
        fprintf(nomeFicheiro3, "%d %d %d %d %d %s\n", u1[i].ordem, u1[i].NIF, u1[i].tempoInicio, u1[i].tempoFim, u1[i].autonomiaInicial, u1[i].codigo);
    }
    fclose(nomeFicheiro3);
    count3 = Ler_Fich3(u1);
    count = Ler_Fich1(p1);
    if (count3 != count) {
        wprintf(L"\nErro na distribuição dos transportes!\n");
    }
    else { wprintf(L"\nDistribuição dos transportes completa!\n"); }

}


//11. Listagem do plano de utilização de um determinado meio de mobilidade elétrica;
void Listar_Fich3(struct Utilizacao u1[]){
    int i;
    i = 0;
    char codigo[5];
    setlocale(LC_ALL, "Portuguese");
    printf("\n---------------------------");
    wprintf(L"\n11. Listagem do plano de utilização de um determinado meio de mobilidade elétrica;\n");
    wprintf(L"Digite o código que deseja comfirmar as distribuições:");
    scanf("%s",codigo);
    int count = Ler_Fich3(u1);
    if (count == 0)wprintf(L"\n\nErro! Não existe conteúdo no ficheiro 3! Necessita de fazer a opção 10 do menu primeiro!");
    else if (count > 0){
        wprintf(L"\nOrdem  NIF  T.Início  T.Final  Autonomia(Inicial)  Código\n");
        for (i = 0; i < count; i ++){
            if ((strcmp(codigo, u1[i].codigo)) == 0){
                printf("%d %d %d %d %d %s\n", u1[i].ordem, u1[i].NIF, u1[i].tempoInicio, u1[i].tempoFim, u1[i].autonomiaInicial, u1[i].codigo);
            }
        }
        printf("\n\nListagem completa!");
    }
}

//12. Armazenamento dos pedidos de utilização em ficheiro;
void Save_Fich1(struct Pedidos p1[]) {
    int i, aux;
    i = aux = 0;
    aux = Ler_Fich1(p1);
    setlocale(LC_ALL, "Portuguese");
    printf("\n---------------------------");
    wprintf(L"\n12. Armazenamento dos pedidos de utilização em ficheiro;\n");
    FILE* nomeFicheiro = fopen("ficheiro1.txt", "wt");
    if (nomeFicheiro == NULL)
    {
        wprintf(L"Erro! Não foi encontrado nenhum ficheiro\n");
        exit(-1);
    }
    while (p1[i].ordem != 0)
    {
        fprintf(nomeFicheiro, "%d %d %s %.2f %.2f\n", p1[i].ordem, p1[i].NIF, p1[i].codigo, p1[i].tempo, p1[i].distancia);
        i++;
    }
    fclose(nomeFicheiro);
    printf("\nFicheiro guardado!");

}


//13. Armazenamento dos meios de mobilidade elétrica em ficheiro;
void Save_Fich2(struct Transportes t1[]) {
    int i, aux;
    i = aux = 0;
    aux = Ler_Fich2(t1);
    setlocale(LC_ALL, "Portuguese");
    printf("\n---------------------------");
    wprintf(L"\n13. Armazenamento dos meios de mobilidade elétrica em ficheiro;\n");
    FILE* nomeFicheiro = fopen("ficheiro2.txt", "wt");
    if (nomeFicheiro == NULL)
    {
        wprintf(L"Erro! Não foi encontrado nenhum ficheiro\n");
        exit(-1);
    }
    while (t1[i].autonomia != 0)
    {
        fprintf(nomeFicheiro, "%s %s %.2f %.2f\n", t1[i].codigo, t1[i].tipo, t1[i].preco, t1[i].autonomia);
        i++;
    }
    fclose(nomeFicheiro);
    printf("\nFicheiro guardado!");
}





