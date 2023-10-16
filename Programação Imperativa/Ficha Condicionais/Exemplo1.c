#include <stdio.h>
#include <stdlib.h>

// Hoje demos os símbolos que representam as várias instruções condicionais;
// != ou == ou &&, etc;
int main (){

int anos, filhos, bonus;
anos = filhos = bonus = 0;

printf("\nIntroduza o numero de filhos: ");
scanf("%d", &filhos);
printf("\nIntroduza os anos de servico: ");
scanf("%d", &anos);


if(filhos >= 0)
    if(anos >= 0){
        bonus = filhos*20 + anos*10;
        printf("\nBonus a atribuir %d", bonus);
    }
/*
if(filhos >= 0 && anos >= 0)
    {
        bonus = filhos*20 + anos*10;
        printf("\nBonus a atribuir %d", bonus);
    }
else printf("\nDados invalidos;");
*/
    
else printf("\nDados invalidos;");


    return 0;
}