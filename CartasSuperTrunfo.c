#include <stdio.h>   
#include <string.h> 

// 1. DEFINIÇÃO DA ESTRUTURA DE DADOS PARA A CARTA (PAÍS)
typedef struct {
    int codigo;
    char nome[50];
    long long populacao;
    double area; // 
    double pib; // 
    int num_pontos_turisticos;
    double densidade_demografica; 
} CartaPais; 

void exibirDetalhesCarta(CartaPais carta) {
    printf("--- Detalhes de %s ---\n", carta.nome);
    printf("Código: %d\n", carta.codigo);
    printf("Populacao: %lld\n", carta.populacao);
    printf("Area: %.2lf km²\n", carta.area);
    printf("PIB: %.2lf\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.num_pontos_turisticos);
    printf("Densidade Demografica: %.2lf hab/km²\n", carta.densidade_demografica);
    printf("----------------------------------\n");
}

int main() {
    // 2. DEFINIÇÃO DE DUAS CARTAS (HARDCODED)
    CartaPais carta1; 
    CartaPais carta2; 

    // Preenchendo os dados da Carta 1 (Exemplo: Brasil)
    carta1.codigo = 1;
    strcpy(carta1.nome, "Brasil"); // Usamos strcpy para atribuir valores a strings
    carta1.populacao = 215000000;
    carta1.area = 8515767.0; // Area em km²
    carta1.pib = 1.8; // Em trilhões de USD
    carta1.num_pontos_turisticos = 100;

    // Preenchendo os dados da Carta 2 (Exemplo: Canadá)
    carta2.codigo = 2;
    strcpy(carta2.nome, "Canada");
    carta2.populacao = 38000000;
    carta2.area = 9984670.0;
    carta2.pib = 2.2;
    carta2.num_pontos_turisticos = 80;


    // 3. CÁLCULO DA DENSIDADE DEMOGRÁFICA
    if (carta1.area > 0) {
        carta1.densidade_demografica = (double)carta1.populacao / carta1.area;
    } else {
        carta1.densidade_demografica = 0.0; 
    }

    if (carta2.area > 0) {
        carta2.densidade_demografica = (double)carta2.populacao / carta2.area;
    } else {
        carta2.densidade_demografica = 0.0;
    }

    // Exibe os detalhes das cartas para o jogador antes da escolha do atributo
    printf("\n--- Cartas em Jogo ---\n");
    exibirDetalhesCarta(carta1);
    exibirDetalhesCarta(carta2);

     // 4. MENU INTERATIVO
    int escolha_atributo; 
    printf("--- Super Trunfo: Batalha de Paises ---\n");
    printf("Escolha o atributo para comparar entre %s e %s:\n", carta1.nome, carta2.nome);
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Numero de Pontos Turisticos\n");
    printf("5. Densidade Demografica\n");
    printf("--------------------------------------\n");
    printf("Digite o numero do atributo: ");
    scanf("%d", &escolha_atributo); 

    // Variáveis auxiliares para armazenar o nome do atributo e os valores para exibição
    char nome_atributo[50]; 
    double valor1 = 0;
    double valor2 = 0;
    char *vencedor = "";

    // 5. LÓGICA DE COMPARAÇÃO COM SWITCH E IF-ELSE ANINHADOS
    switch (escolha_atributo) {
        case 1: // POPULAÇÃO
            strcpy(nome_atributo, "Populacao");
            valor1 = (double)carta1.populacao;
            valor2 = (double)carta2.populacao;
            if (carta1.populacao > carta2.populacao) {
                vencedor = carta1.nome;
            } else if (carta2.populacao > carta1.populacao) {
                vencedor = carta2.nome;
            } else {
                vencedor = "Empate!";
            }
            break;

        case 2: // ÁREA
            strcpy(nome_atributo, "Area");
            valor1 = carta1.area;
            valor2 = carta2.area;
            if (carta1.area > carta2.area) {
                vencedor = carta1.nome;
            } else if (carta2.area > carta1.area) {
                vencedor = carta2.nome;
            } else {
                vencedor = "Empate!";
            }
            break;

        case 3: // PIB
            strcpy(nome_atributo, "PIB");
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            if (carta1.pib > carta2.pib) {
                vencedor = carta1.nome;
            } else if (carta2.pib > carta1.pib) {
                vencedor = carta2.nome;
            } else {
                vencedor = "Empate!";
            }
            break;

        case 4: // NÚMERO DE PONTOS TURÍSTICOS
            strcpy(nome_atributo, "Numero de Pontos Turisticos");
            valor1 = (double)carta1.num_pontos_turisticos;
            valor2 = (double)carta2.num_pontos_turisticos;
            if (carta1.num_pontos_turisticos > carta2.num_pontos_turisticos) {
                vencedor = carta1.nome;
            } else if (carta2.num_pontos_turisticos > carta1.num_pontos_turisticos) {
                vencedor = carta2.nome;
            } else {
                vencedor = "Empate!";
            }
            break;

        case 5: // DENSIDADE DEMOGRÁFICA (REGRA INVERTIDA!)
            strcpy(nome_atributo, "Densidade Demografica");
            valor1 = carta1.densidade_demografica;
            valor2 = carta2.densidade_demografica;
            // REGRA INVERTIDA: VENCE A CARTA COM O MENOR VALOR!
            if (carta1.densidade_demografica < carta2.densidade_demografica) { // Menor valor vence
                vencedor = carta1.nome;
            } else if (carta2.densidade_demografica < carta1.densidade_demografica) { // Menor valor vence
                vencedor = carta2.nome;
            } else {
                vencedor = "Empate!";
            }
            break;

        default: // Tratamento para escolha inválida
            printf("Opcao invalida! Por favor, escolha um numero entre 1 e 5.\n");
            return 1; // Retorna 1 para indicar que o programa terminou com erro
    }

    // 6. EXIBIÇÃO DO RESULTADO (APENAS SE A OPÇÃO FOR VÁLIDA)
    if (strcmp(vencedor, "") != 0) {
        printf("\n--- Resultado da Comparacao ---\n");
        printf("Atributo Escolhido: %s\n", nome_atributo);
        printf("%s (%s): %.2lf\n", carta1.nome, nome_atributo, valor1);
        printf("%s (%s): %.2lf\n", carta2.nome, nome_atributo, valor2);

        if (strcmp(vencedor, "Empate!") == 0) { 
        } else {
            printf("\nO vencedor é: %s!\n", vencedor);
        }
        printf("-------------------------------\n");
    }

    return 0; 
}