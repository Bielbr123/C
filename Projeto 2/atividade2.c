#include <stdio.h>
#include <stdlib.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
// Declarando as variaveis
    int calcularNovamente = 1, tempCalcularNovamente, quantidadeImc = 0, capacidadeImc = 5, saberMedia;
    int pesoValido = 0, alturaValida = 0;
    float peso, altura, imc, mediaImc, somaImc;
    float *todosImc = (float*)malloc(capacidadeImc * sizeof(float));

    // Garantindo que a alocacao dicamica de todosImc seja bem sucedida
    if (todosImc == NULL){
        printf("Erro na alocacao de memoria!\n");
        return 1;
    }
    // Apresentacao do sistema.
    printf("Programa criado por Gabriel Augusto para o calculo do IMC uma ou mais de uma vez(es), alem de retornar a media dos IMCs.\n");

// Repeticao para calcular o IMC quantas vezes o(a) usuario(a) quiser
    while (calcularNovamente == 1)
    {

        // Entre 5 e 150 para garantir que seja possível realizar o IMC até de um bebe
        printf("Insira o peso entre 5 e 150 kg: \n");
        // Tratamento de excecao. Garantindo que o valor e um numero no scanf("%f", &peso) != 1
        // Garantindo que o peso esteja entre os valores 5 e 150 nas duas condicoes subsequentes
        while(!pesoValido)
        {
            // Garantindo que o peso seja um numero
            if(scanf("%f", &peso) != 1)
            {
                printf("Peso invalido. Insira o peso entre 5 e 150 kg: \n");
            }
            // Garantindo que o peso seja maior que 5
            else if(peso < 5){
                printf("Peso invalido. Insira o peso entre 5 e 150 kg: \n");
            }
            // Garantindo que o peso seja menor que 150
            else if(peso > 150)
            {
                printf("Peso invalido. Insira o peso entre 5 e 150 kg: \n");
            }
            // Passa o valor de 1 na variavel para sair do loop, pois 1 != 0, entao retorna True
            else
            {
                pesoValido = 1;
            }
            // Limpando o buffer do teclado
            limparBuffer();
        }
        printf("O valor do peso e %.2f\n", peso);
        // Voltando o valor de pesoValido para 0, assim ele conseguira entrar no loop while cima na proxima
        // iteracao do programa
        pesoValido = 0;

        // Obtendo a altura entre 0.3 e 2.5 m
        // Valores escolhidos para poder calcular o IMC de bebês
        printf("\nDigite a altura entre 0.3 e 2.5 m: \n");
        while(!alturaValida)
        {
            // Garantindo que a altura seja um numero
            if(scanf("%f", &altura) != 1)
            {
                printf("Altura invalida. Insira a altura entre 0.3 e 2.5 m: \n");
            }
            // Garantindo que a altura seja maior que 0.3 m
            else if(altura < 0.3){
                printf("Altura invalida. Insira a altura entre 0.3 e 2.5 m: \n");
            }
            // Garantindo que a altura seja menor que 2.5 m
            else if(altura > 2.5)
            {
                printf("Altura invalida. Insira a altura entre 0.3 e 2.5 m: \n");
            }
            // Retornando 1 caso todas as condicoes estejam satisfeitas
            // Como 1 != de 0, logo o while retornara True e saira do loop
            else
            {
                alturaValida = 1;
            }
            // Limpando o buffer do teclado
            limparBuffer();
        }
        printf("O valor da altura e %.2f\n", altura);
        alturaValida = 0;
        // Calculo do IMC
        imc = (peso/(altura * altura));
        printf("Seu IMC: %.2f\n", imc);

        // Classificacao do IMC
        if ( imc < 18.5)
        {
            printf("Sua classificacao: Abaixo do Peso.\n");

        }
        else if(imc >= 18.5 && imc < 24.9)
        {
             printf("A sua classificacao: Peso Normal.\n");
        }
        else if(imc >= 25 && imc < 29.9)
        {
            printf("A sua classificacao: Sobrepeso.\n");
        }
        else if(imc >= 30 && imc < 34.9)
        {
            printf("A sua classificacao: Obesidade grau I.\n");
        }
        else if (imc >= 30 && imc < 40.0)
        {
            printf("A sua classificacao: Obesidade grau II.\n");
        }
        else
        {
            printf("Obseidade grau III.\n");
        }

        // Assegura que haja espaco disponivel dinamicamente para guardar todos os valores de Imc
        if (quantidadeImc >= capacidadeImc)
        {
            // Se a quantidade de numeros na array alcancar o espaco alocado no momento, dobra esse espaco alocado dinamicamente
            capacidadeImc *= 2;
            // Criando uma variável temporaria para realocar dinamicamente TodosImc
            float *realocadoTodosImc = (float*)realloc(todosImc, capacidadeImc * sizeof(float));
            // Testa se a alocacao funcionou
            if (realocadoTodosImc == NULL){
                printf("Erro de realocacao de memoria.\n");
                return 1;
            }
            // Realocando todosImc
            todosImc = realocadoTodosImc;
        }
        // Adiciona 1 no contador de quantos IMCS foram realizados para utilizar no calculo da media
        quantidadeImc += 1;
        // Adiciona o valor do IMC atualmente calculado na soma de todos os IMCs para calcular a medias
        somaImc += imc;

        // Pergunta e guarda se o usuario quer ou nao que a media seja calculada
        printf("Queres que a media do IMC seja calculada? Aperte '1' para 'Sim' ou qualquer outro carater para 'Nao'.\n");
        scanf("%d", &saberMedia);
        // Limpar o buffer para nao interferir no proximo scanf
        //while ((limparBuffer = getchar()) != '\n' && limparBuffer != EOF);
        limparBuffer();

        // Calcula a media dos IMCs
        if(saberMedia == 1)
        {
            // Calcula a media do IMC e mostra na tela
            mediaImc = (somaImc/quantidadeImc);
            printf("A media e %.2f \n", mediaImc);

        }

        // Pergunta se o usuario quer continuar no programa ou nao
        printf("Quer que o IMC seja calculado novamente? Digite '1' para 'Sim' ou qualquer outro caractere/numero para sair.\n");
        // Se o valor da variavel diferente de 1, retornara calcularNovamente como 0. O loop while inicial saira, pois
        //o valor sera diferente de 1
        if(scanf("%d", &tempCalcularNovamente) != 1)
        {
            // Retorna 0, ou seja, o loop while inicial sera False, saindo do programa
            calcularNovamente = 0;
            exit(0);
        }
        // Caso o valor de tempCalcularNovamente seja 1, colocamos 1 no calcularNovamente
        // Assim, ele ainda esta na condicao "while(calcularNovamente) == 1"
        else
        {
            calcularNovamente == (tempCalcularNovamente == 1);
        }
        // Limpa o buffer do scanf anterior para nao atrapalhar a proxima leitura
        limparBuffer();

        }
    // Limpa a memoria alocada dinamicamente para evitar problemas
    free(todosImc);
    return 0;
}
