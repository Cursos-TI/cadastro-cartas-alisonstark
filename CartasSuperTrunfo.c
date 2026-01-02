#include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

int main() {

  // Área para definição das variáveis para armazenar as propriedades das cidades
  char estado[50], codigoCarta[10], nomeCidade[50];
  int numPontosTuristicos;
  unsigned long int populacao;
  float area, pib, densPopulacional, pibPerCapita, superPoder;

  // Área de definição de outras variáveis
  // srand(time(NULL));
  // unsigned short numAleatorio = (rand() % 7) + 1;
  unsigned short escolhaJogador;

  // Duplicar variáveis para a segunda carta
  char estado2[50], codigoCarta2[10], nomeCidade2[50];
  int numPontosTuristicos2;
  unsigned long int populacao2;
  float area2, pib2, densPopulacional2, pibPerCapita2, superPoder2;

  // Área para entrada de dados da carta #1
  // Usar " %49[^\n]" para ler strings com espaços, pois %s gerou problemas
  printf("### Cadastro de carta #1 ###\n");
  printf("Digite o estado: ");
  scanf(" %49[^\n]", estado);
  printf("Digite o código da carta: ");
  scanf("%s", codigoCarta);   // Assumindo que o código não terá espaços
  printf("Digite o nome da cidade: ");
  scanf(" %49[^\n]", nomeCidade);
  printf("Digite a população: ");
  scanf("%lu", &populacao);
  printf("Digite a área (km²): ");
  scanf("%f", &area);
  printf("Digite o PIB (bilhões de R$): ");
  scanf("%f", &pib);
  printf("Digite o número de pontos turísticos: ");
  scanf("%d", &numPontosTuristicos);

  // Área para entrada de dados da carta #2
  printf("\n\n### Cadastro de carta #2 ###\n");
  printf("Digite o estado: ");
  scanf(" %49[^\n]", estado2);
  printf("Digite o código da carta: ");
  scanf("%s", codigoCarta2);   // Assumindo que o código não terá espaços
  printf("Digite o nome da cidade: ");
  scanf(" %49[^\n]", nomeCidade2);
  printf("Digite a população: ");
  scanf("%lu", &populacao2);
  printf("Digite a área (km²): ");
  scanf("%f", &area2);
  printf("Digite o PIB (bilhões de R$): ");
  scanf("%f", &pib2);
  printf("Digite o número de pontos turísticos: ");
  scanf("%d", &numPontosTuristicos2);

  // Área para cálculo de variáveis derivadas da carta #1
  pib *= 1000000000; // Converter PIB de bilhões para reais
  densPopulacional = populacao / area;
  pibPerCapita = pib / populacao;
  superPoder = numPontosTuristicos + populacao + area + pib + (1.0 / densPopulacional) + pibPerCapita;  // Potencial perda de precisão se populacao for muito grande

  // Área para cálculo de variáveis derivadas da carta #2
  pib2 *= 1000000000;
  densPopulacional2 = populacao2 / area2;
  pibPerCapita2 = pib2 / populacao2;
  superPoder2 = numPontosTuristicos2 + populacao2 + area2 + pib2 + (1.0 / densPopulacional2) + pibPerCapita2;

  // printf("O número aleatório gerado foi: %u\n", numAleatorio);
  // Área de definição da carta vencedora, em que se compara para cada atributo da carta #1 com a carta #2, por padrão

  printf("\n##### Escolha o atributo da carta para competir nesta rodada #####");
  printf("\n 1. População\n 2. Área\n 3. PIB\n 4. Número de Pontos Turísticos\n 5. Densidade Populacional\n 6. PIB per Capita\n 7. Super Poder\n");
  printf("Digite o número do atributo escolhido: ");
  scanf("%u", escolhaJogador);

  switch (escolhaJogador)
  {
  case 1:
    if(populacao > populacao2){
      printf("A carta 1 vence (%s)!", nomeCidade);
    } else {
      printf("A carta 2 vence (%s)!", nomeCidade2);
    }
    break;
  case 2:
    if(area > area2){
      printf("A carta 1 vence (%s)!", nomeCidade);
    } else {
      printf("A carta 2 vence (%s)!", nomeCidade2);
    }
    break;
  case 3:
    if(pib > pib2){
      printf("A carta 1 vence (%s)!", nomeCidade);
    } else {
      printf("A carta 2 vence (%s)!", nomeCidade2);
    }
    break;
  case 4:
    if(numPontosTuristicos > numPontosTuristicos2){
      printf("A carta 1 vence (%s)!", nomeCidade);
    } else {
      printf("A carta 2 vence (%s)!", nomeCidade2);
    }
    break;
  case 5:
    if(densPopulacional < densPopulacional2){
      printf("A carta 1 vence (%s)!", nomeCidade);
    } else {
      printf("A carta 2 vence (%s)!", nomeCidade2);
    }
    break;
  case 6:
    if(pibPerCapita > pibPerCapita2){
      printf("A carta 1 vence (%s)!", nomeCidade);
    } else {
      printf("A carta 2 vence (%s)!", nomeCidade2);
    }
    break;
  default:
    if(superPoder > superPoder2){
        printf("A carta 1 vence (%s)!", nomeCidade);
    } else {
        printf("A carta 2 vence (%s)!", nomeCidade2);
    }
    break;
  }

  return 0;
} 
