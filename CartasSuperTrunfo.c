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
  // Usar " %49[^\n]" para ler strings com espaços, pois %s gerou problemas
  printf("Digite o estado: ");
  scanf(" %49[^\n]", estado);
  printf("Digite o código da carta: ");
  scanf("%s", codigoCarta);
  printf("Digite o nome da cidade: ");
  scanf(" %49[^\n]", nomeCidade);
  printf("Digite a população: ");
  scanf("%d", &populacao);
  printf("Digite a área (km²): ");
  scanf("%f", &area);
  printf("Digite o PIB (R$): ");
  scanf("%f", &pib);
  printf("Digite o número de pontos turísticos: ");
  scanf("%d", &numPontosTuristicos);

  // Área para exibição dos dados da cidade
  printf("\n### Confirmação de Dados da Carta ###\n");
  printf("Estado: %s\n", estado);
  printf("Código da carta: %s\n", codigoCarta);
  printf("Nome da cidade: %s\n", nomeCidade);
  printf("População: %d\n", populacao);
  printf("Área (km²): %.2f\n", area);
  printf("PIB (R$): %.2f\n", pib);
  printf("Número de pontos turísticos: %d\n", numPontosTuristicos);

return 0;
} 
