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
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
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
