#include <stdio.h>
#include <stdlib.h>

/*
8. 	Temperaturas – com sentinela
Refaça o Programa anterior, considerando um 
número indeterminado de dias (sugestão: utilizar uma condição especial 
– Sentinela - para paragem da leitura, baseada na variável Temperatura por ex. 
Temperatura < 100, pois supõe-se que a Temperatura a ler nunca atinge este valor).
*/

int main (){

int i = 0;
float media, tempMax, tempMin, temp, total;
media = tempMax = tempMin = temp = total = 0;


while (temp > -100 && temp < 100)
{
    
    printf("\nTemperatura do dia %d:", i+1);
    scanf("%f",&temp);
    if (temp >= tempMax &&  temp > -100 && temp < 100)tempMax = temp;
    if (temp <= tempMin && temp > -100 && temp < 100)tempMin = temp;
    if (i == 0  &&  temp > -100 && temp < 100)tempMin = temp;
    
    if (temp > -100 && temp < 100){
        total = total + temp;
        media = total / (i+1);
        printf("\nMedia: %2.f", media);
        printf("\nTemperatura max: %2.f", tempMax);
        printf("\nTemperatura minima: %2.f", tempMin);
        i++;
        printf("\n-----------------------------------");
    }
    
}



    return 0;
}