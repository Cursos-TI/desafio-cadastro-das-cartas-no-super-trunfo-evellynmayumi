#include <stdio.h>

int main() {
    // Desafio Super Trunfo - Países
    // Tema 1 - Cadastro das Cartas

    // Sugestão: Defina variáveis separadas para cada atributo do país.
    // Exemplos de atributos: código do país, nome, população, área, PIB, número de pontos turísticos.

    // DECLARAÇÃO DE VARIÁVEIS
    int codigo;
    char nome[50]; // Espaço para 49 caracteres + o terminador nulo '\0'
    long long populacao;
    double area;
    double pib; 
    int num_pontos_turisticos;

    // CADASTRO DAS CARTAS:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada país.

    printf("Cadastro de Nova Carta (País)\n");

    printf("Digite o código do país: ");
    scanf("%d", &codigo);

    // Limpa o buffer de entrada para evitar problemas com a leitura da string 'nome'
    // (Especialmente ao misturar scanf de números com scanf de strings)
    fflush(stdin);

    printf("Digite o nome do país (max 49 caracteres): ");
    scanf("%49[^\n]", nome); // Lê a string, incluindo espaços, até 49 caracteres ou uma quebra de linha

    printf("Digite a populacao do pais: ");
    scanf("%lld", &populacao);

    printf("Digite a area do pais (em km²): ");
    scanf("%lf", &area);

    printf("Digite o PIB do pais: ");
    scanf("%lf", &pib);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &num_pontos_turisticos);

    printf("\nCarta cadastrada com sucesso!\n\n");

    // EXIBIÇÃO DOS DADOS DAS CARTAS:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo do país, um por linha.

    printf("Detalhes da Carta Cadastrada\n");
    printf("Código: %d\n", codigo);
    printf("Nome: %s\n", nome);
    printf("Populacao: %lld\n", populacao);
    printf("Area: %.2lf km²\n", area); // %.2lf formata o double para 2 casas decimais
    printf("PIB: %.2lf\n", pib);
    printf("Pontos Turisticos: %d\n", num_pontos_turisticos);
    printf("------------------------------------\n");

    return 0; 
}