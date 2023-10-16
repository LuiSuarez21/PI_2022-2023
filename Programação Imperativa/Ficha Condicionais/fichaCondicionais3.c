#include <stdio.h>
/*
Bónus de Natal do colaborador
Uma empresa pretende atribuir um Bónus de Natal aos seus empregados, que é função da idade, 
da antiguidade (nº de anos de serviço) e do número de filhos, calculado da seguinte forma:
- 5€ por cada ano acima dos 45 anos de idade
- 10€ por ano de serviço, até 10 anos, e 20€ por cada ano a mais
- 25€ por filho, no máximo até 3 filhos; acima de 3 filhos, receberá sempre 75€
O programa lê a idade, antiguidade e número de filhos de um empregado, e calcula o valor do bónus correspondente.

*/

int main(){

int filhos, anosServicos, idade;
int dinheiro;
filhos = idade = anosServicos = dinheiro = 0;

printf("Introduza o numero de filhos:");
scanf("%d",&filhos);
printf("Introduza a idade:");
scanf("%d",&idade);
printf("Introduza o numero de anos de servico:");
scanf("%d",&anosServicos);


if (idade > 45)dinheiro = dinheiro + (5*(idade-45));
if (anosServicos > 0 && anosServicos <= 10)dinheiro = dinheiro + (10*anosServicos);
if (anosServicos > 10 && anosServicos > 0){
    int anosaux = anosServicos;
    anosaux = anosServicos - 10;
    dinheiro = dinheiro + (10*anosServicos) + (20*anosaux);
}
if(filhos <= 3 && filhos > 0)dinheiro = dinheiro + filhos*25;
if (filhos > 0 && filhos > 3)dinheiro = dinheiro + filhos*75;

printf("O funcionario vai receber bonus igual a %d", dinheiro);

    return 0;
}