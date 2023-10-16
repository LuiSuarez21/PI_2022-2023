#include <stdio.h>
/*
Aumento de salário em função do cargo
Uma empresa concederá um aumento de salário aos seus funcionários, 
variável de acordo com o cargo, conforme a tabela abaixo.
Programa que lê o salário e o código do cargo de um funcionário e calcula o novo salário.
Se o cargo do funcionário não estiver na tabela, ele recebe 40% de aumento.
	Código	Cargo	Aumento
	1	gerente	10%
	2	engenheiro	20%
	3	técnico	30%
No final é mostrado o salário antigo, o novo salário e a diferença.

*/

int main (){

int codigo, salario, novoSalario;
codigo = salario = novoSalario = 0;

printf("Introduza o codigo do funcionario: ");
scanf("%d",&codigo);
printf("Introduza o salario actua: ");
scanf("%d",&salario);

if(codigo > 0){

    switch (codigo)
    {
    case 1:
        novoSalario = novoSalario + salario + salario*0.1;
        printf("\n-----------------------------------------");
        printf("\nAntigo salario: %d",salario);
        printf("\nDiferenca salarial: %d", novoSalario - salario);
        printf("\nNovo salario: %d", novoSalario);
        break;
    case 2:
        novoSalario = novoSalario + salario + salario*0.2;
        printf("\n-----------------------------------------");
        printf("\nAntigo salario: %d",salario);
        printf("\nDiferenca salarial: %d", novoSalario - salario);
        printf("\nNovo salario: %d", novoSalario);
        break;
    case 3:
        novoSalario = novoSalario + salario + salario*0.3;
        printf("\n-----------------------------------------");
        printf("\nAntigo salario: %d",salario);
        printf("\nDiferenca salarial: %d", novoSalario - salario);
        printf("\nNovo salario: %d", novoSalario);
        break;
    default:
        novoSalario = novoSalario + salario + salario*0.4;
        printf("\n-----------------------------------------");
        printf("\nAntigo salario: %d",salario);
        printf("\nDiferenca salarial: %d", novoSalario - salario);
        printf("\nNovo salario: %d", novoSalario);
        break;
    }
}

    return 0;
}