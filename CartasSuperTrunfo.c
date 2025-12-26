#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

int main() {
  // Área para definição das variáveis para armazenar as propriedades das cidades
  char estado[50], codigoCarta[10], nomeCidade[50];
  int populacao, numPontosTuristicos;
  float area, pib;

  // Área para entrada de dados
  printf("Digite o código da carta: ");
  scanf("%s", codigoCarta);
  printf("Digite o nome da cidade: ");
  scanf("%s", nomeCidade);
  printf("Digite o estado: ");
  scanf("%s", estado);
  printf("Digite a população: ");
  scanf("%d", &populacao);
  printf("Digite o número de pontos turísticos: ");
  scanf("%d", &numPontosTuristicos);
  printf("Digite a área (km²): ");
  scanf("%f", &area);
  printf("Digite o PIB (R$): ");
  scanf("%f", &pib);

  // Área para exibição dos dados da cidade
  printf("\n### Confirmação de Dados da Carta ###\n");
  printf("Código da carta: %s\n", codigoCarta);
  printf("Nome da cidade: %s\n", nomeCidade);
  printf("Estado: %s\n", estado);
  printf("População: %d\n", populacao);
  printf("Número de pontos turísticos: %d\n", numPontosTuristicos);
  printf("Área (km²): %.2f\n", area);
  printf("PIB (R$): %.2f\n", pib);

return 0;
} 
