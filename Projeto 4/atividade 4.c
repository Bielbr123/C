#include <stdio.h>
#include <stdlib.h>

int main(){
    // Criando o vetor desordenado com as temperaturas
    float temperatura[10] = {10, 2, 7, 9, 3, 1, 4, 5, 8, 6};
    // Variavel temporaria para guardar o menor numero do Bubble Sort
    float temporario = 0;
    // Acessando o vetor para mostra-lo na tela com formatacao correta
    printf("O vetor escolhido possui os valores: ");
    for(int i = 0; i <= 9; i++)
    {
        // Mostra o ";" se nao for o ultimo
        if(i!= 9)
        {
            printf("%.2f,  ", temperatura[i]);
        }
        else
        {
        // Mostra o "." no ultimo elemento
            printf("%.2f.", temperatura[i]);
        }
    }
    printf("\n\n");
    // Iteracao sobre primeiro numero para utilizar o Bubble Sort
    for(int i = 0; i <= 10; i++)
    {
    // Iteracao sobre segundo numero para comparar com o primeiro
        for(int j = 0; j <= 9; j++)
        {
    // Comparando se o primeiro numero e maior que o segundo
            if(temperatura[j] > temperatura[j+1])
            {
    // Se sim, iguala o primeiro numero a um temporario
                temporario = temperatura[j];
    // Faz com que o primeiro numero possua o valor do segundo
                temperatura[j] = temperatura[j+1];
    // Utiliza o valor do primeiro numero guardado em temporario no segundo numero
    // Completando, assim, a troca de posicao dos dois numeros
                temperatura[j+1] = temporario;
            }
        }
    }

    printf("Vetor temperatura com ordenacao crescente: ");
    for(int i = 0; i <= 9; i++)
    {
    // Mostra o ";" se nao for o ultimo
        if(i!= 9)
        {
            printf("%.2f,  ", temperatura[i]);
        }
    // Mostra o "." no ultimo elemento
        else
        {
            printf("%.2f.", temperatura[i]);
        }
    }

    // Iteracao sobre primeiro numero para utilizar o Bubble Sort
    for(int i = 0; i <= 10; i++)
    {
    // Iteracao sobre segundo numero para comparar com o primeiro
        for(int j = 0; j <= 9; j++)
        {
   // Comparando se o primeiro numero e menor que o segundo
            if(temperatura[j] < temperatura[j+1])
            {
    // Se sim, iguala o primeiro numero a um temporario
                temporario = temperatura[j];
    // Faz com que o primeiro numero possua o valor do segundo
                temperatura[j] = temperatura[j+1];
    // Utiliza o valor do primeiro numero guardado em temporario no segundo numero
    // Completando, assim, a troca de posicao dos dois numeros
                temperatura[j+1] = temporario;
            }
        }
    }
    printf("\n\n");
    printf("Vetor temperatura com ordenacao decrescente: ");
    // Acessando o vetor temperatura
    for(int i = 0; i <= 9; i++)
    {
    // Mostra o ";" se nao for o ultimo
        if(i!= 9)
        {
            printf("%.2f,  ", temperatura[i]);
        }
    // Mostra o "." no ultimo elemento
        else
        {
            printf("%.2f.", temperatura[i]);
        }
    }

    exit(0);
    return 0;
}
