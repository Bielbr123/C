#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("Programa 'Indices de Chuva' por matrizes criado por Gabriel Augusto.\n");
    printf("O programa ira mostrar a quantidade de precipitacao de um dia em um determinado bairro\n");
    printf("Ele possui 7 dias e 2 bairros.\n");
    printf("Espero que voce goste da experiencia!\n\n");
    // Serao 7 dias e 2 bairros
    // Linhas serao os dias e os bairros serao as colunas
    char dias[7][10];
    char bairros[2][20];
    int indiceBairroMaisChuvoso = 0, indiceDiaMaisChuvoso = 0;
    float diaMaisChuvoso = 0, totalChuvaPorBairro = 0, mediaChuvaPorBairro = 0;
    float indicesChuva[7][2] =
    {
        {10, 20},
        {5, 10},
        {7, 12},
        {8, 2},
        {1, 15},
        {10, 13},
        {4, 18}
    };


    // Alocando as strings nos vetores
    strcpy(bairros[0], "Mangabeiras");
    strcpy(bairros[1], "Jatiuca");
    strcpy(dias[0], "Segunda");
    strcpy(dias[1], "Terca");
    strcpy(dias[2], "Quarta");
    strcpy(dias[3], "Quinta");
    strcpy(dias[4], "Sexta");
    strcpy(dias[5], "Sabado");
    strcpy(dias[6], "Domingo");

/*
    for(int i = 0; i < 7; i++){
        printf("Os valores do vetor dias sao dias[%d] = %s\n", i, dias[i]);}
 */

    // Inicializando os dados de

    for(int i=0; i<7; i++)
    {
        for(int j=0;  j<2; j++)
        {
            printf("O valor do dia %s, no bairro %s e %.2f mm.\n", dias[i], bairros[j], indicesChuva[i][j]);
            if (indicesChuva[i][j] > diaMaisChuvoso)
            {
                diaMaisChuvoso = indicesChuva[i][j];
                indiceBairroMaisChuvoso = j;
                indiceDiaMaisChuvoso = i;
            }

        }

        //printf("O valor total de chuva do bairro e: %f\n", chuvaTotalPorBairro);
    }

    for(int j = 0; j < 2; j++)
    {
        for(int i = 0; i < 7; i++)
        {
            totalChuvaPorBairro += indicesChuva[i][j];
        }
        mediaChuvaPorBairro = totalChuvaPorBairro/2;
        printf("\nA quantidade de chuva total do bairro %s e %.2f mm.\n", bairros[j], totalChuvaPorBairro);
        printf("A media de chuva do bairro %s e %.2f.\n", bairros[j], mediaChuvaPorBairro);
    }


    printf("\nMaior chuva:%.2f,no bairro %s, no dia de %s.\n", diaMaisChuvoso, bairros[indiceBairroMaisChuvoso], dias[indiceDiaMaisChuvoso] );
    //printf("Bairros 1: %s\n", bairros[0]);


    return 0;
}
