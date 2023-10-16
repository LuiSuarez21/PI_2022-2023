
/*

7. 	Temperaturas 
Durante trinta dias foram recolhidas as temperaturas (em graus celsius) 
médias diárias de uma determinada região. Define um algoritmo para calcular 
e informar a temperatura média do mês, assim como a temperatura mais alta do mês.

*/
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

float media, graus, maisAlta;
int i;
    setlocale(LC_ALL, "portuguese");

media = graus = maisAlta = 0;
i = 0;

for (i = 0; i < 30; i++){
    wprintf(L"\nInsira a temperatura media do %dº dia : ",i+1);
    scanf("%f",&graus);
    if (graus >= maisAlta)maisAlta = graus;
    media = media + graus;
}

media = media/30;
printf("\n\n-------------------------------------------------------");
printf("\n\nTemperatura mais alta do mes: %.2f", maisAlta);
printf("\nA media da temperatura mensal: %.2f", media);

    return 0;

}
