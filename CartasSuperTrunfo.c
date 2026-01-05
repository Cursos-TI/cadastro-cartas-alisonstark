#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 3 - Lógica completa do jogo
// Objetivo: Desenvolver a lógica completa do jogo de cartas Super Trunfo, permitindo que dois jogadores cadastrem suas cartas com propriedades específicas de cidades e comparem atributos para determinar a carta vencedora.

int main() {

  // Área para definição das variáveis para armazenar as propriedades das cidades
  char estado[50], codigoCarta[10], nomeCidade[50];
  char resultadoPrimeiroEmbate[100] = "", resultadoSegundoEmbate[100] = "";
  int numPontosTuristicos;
  unsigned long int populacao;
  float area, pib, densPopulacional, pibPerCapita, acc1, acc2;

  // Área de definição de outras variáveis
  // srand(time(NULL));
  // unsigned short numAleatorio = (rand() % 7) + 1;
  unsigned int escolha1Jogador, escolha2Jogador; 
  unsigned short numVitoriasCarta1 = 0, numVitoriasCarta2 = 0;

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

  // Área para cálculo de variáveis derivadas da carta #2
  pib2 *= 1000000000;
  densPopulacional2 = populacao2 / area2;
  pibPerCapita2 = pib2 / populacao2;
  superPoder2 = numPontosTuristicos2 + populacao2 + area2 + pib2 + (1.0 / densPopulacional2) + pibPerCapita2;

  // printf("O número aleatório gerado foi: %u\n", numAleatorio);
  // Área de definição da carta vencedora, em que se compara para cada atributo da carta #1 com a carta #2, por padrão

  printf("###############\n### Início do Jogo ###\n###############\n");
  printf("\n 1. População\n 2. Área\n 3. PIB\n 4. Número de Pontos Turísticos\n 5. Densidade Populacional\n 6. PIB per Capita\n");
  printf("Digite o número de 1 atributo para competir nesta rodada: ");
  scanf("%u", &escolha1Jogador);

  if (escolha1Jogador < 1 || escolha1Jogador > 6){ 
    printf("Valor inválido! Escolha um número entre 1 e 6.\n");
    printf("Saindo do jogo ......\n");
    
    return 1;
  }

  // Comparação dos atributos escolhidos para o primeiro embate
  // Foi usada a função strcat para concatenar strings e ultoa/itoa/ftoa para converter números em strings
  switch (escolha1Jogador){
  case 1:
    if (populacao > populacao2) { 
      sprintf(resultadoPrimeiroEmbate, "%lu (População da Carta #1)", populacao);
      numVitoriasCarta1++;

    } else {
      sprintf(resultadoPrimeiroEmbate, "%lu (População da Carta #2)", populacao2);
      numVitoriasCarta2++;
    }

    acc1 = populacao;
    acc2 = populacao2;
    break;

  case 2:
    if(area > area2){
      sprintf(resultadoPrimeiroEmbate, "%.2f (Área da Carta #1)", area);
      numVitoriasCarta1++;

    } else {
      sprintf(resultadoPrimeiroEmbate, "%.2f (Área da Carta #2)", area2);
      numVitoriasCarta2++;
    }

    acc1 = area;
    acc2 = area2;
    break;

  case 3:
    if(pib > pib2){
      sprintf(resultadoPrimeiroEmbate, "%.2f (PIB da Carta #1)", pib/1000000000);
      numVitoriasCarta1++;
    } else {
      sprintf(resultadoPrimeiroEmbate, "%.2f (PIB da Carta #2)", pib2/1000000000);
      numVitoriasCarta2++;
    }

    acc1 = pib*1000000000;
    acc2 = pib2*1000000000;
    break;

  case 4:
    if(numPontosTuristicos > numPontosTuristicos2){
      sprintf(resultadoPrimeiroEmbate, "%d (Número de Pontos Turísticos da Carta #1)", numPontosTuristicos);
      numVitoriasCarta1++;
    } else {
      sprintf(resultadoPrimeiroEmbate, "%d (Número de Pontos Turísticos da Carta #2)", numPontosTuristicos2);
      numVitoriasCarta2++;
    }

    acc1 = numPontosTuristicos;
    acc2 = numPontosTuristicos2;
    break;

  case 5:
    if(densPopulacional < densPopulacional2){
      sprintf(resultadoPrimeiroEmbate, "%.2f (Densidade Populacional da Carta #1)", densPopulacional);
      numVitoriasCarta1++;
    } else {
      sprintf(resultadoPrimeiroEmbate, "%.2f (Densidade Populacional da Carta #2)", densPopulacional2);
      numVitoriasCarta2++;
    }

    acc1 = densPopulacional;
    acc2 = densPopulacional2;
    break;

  default:
    if(pibPerCapita > pibPerCapita2){
      sprintf(resultadoPrimeiroEmbate, "%.2f (PIB per Capita da Carta #1)", pibPerCapita/1000000000);
      numVitoriasCarta1++;
    } else {
      sprintf(resultadoPrimeiroEmbate, "%.2f (PIB per Capita da Carta #2)", pibPerCapita2/1000000000);
      numVitoriasCarta2++;
    }

    acc1 = pibPerCapita*1000000000;
    acc2 = pibPerCapita2*1000000000;
    break;
  }

  // Implementação da dinâmica do menu de seleção para a escolha do segundo atributo
  switch(escolha1Jogador){
    case 1:
      printf("\n##### Escolha do segundo atributo #####\n");
      printf("\n2. Área\n 3. PIB\n 4. Número de Pontos Turísticos\n 5. Densidade Populacional\n 6. PIB per Capita\n");
      printf("Digite o número de mais 1 atributo para competir nesta rodada: ");
      scanf("%u", &escolha2Jogador);

      if(escolha2Jogador == escolha1Jogador || (escolha2Jogador < 1 || escolha2Jogador > 6)){
        printf("\nValor inválido! Escolha um número entre 1 e 6, diferente do primeiro atributo escolhido.\n");
        printf("Saindo do jogo ......\n");
        
        return 1;
      }
      break;

    case 2:
      printf("\n##### Escolha do segundo atributo #####\n");
      printf("\n 1. População\n 3. PIB\n 4. Número de Pontos Turísticos\n 5. Densidade Populacional\n 6. PIB per Capita\n");
      printf("Digite o número de mais 1 atributo para competir nesta rodada: ");
      scanf("%u", &escolha2Jogador);

      if(escolha2Jogador == escolha1Jogador || (escolha2Jogador < 1 || escolha2Jogador > 6)){
        printf("Valor inválido! Escolha um número entre 1 e 6, diferente do primeiro atributo escolhido.\n");
        printf("Saindo do jogo ......\n");
        
        return 1;
      }
      break;

    case 3:
      printf("\n##### Escolha do segundo atributo #####\n");
      printf("\n 1. População\n 2. Área\n 4. Número de Pontos Turísticos\n 5. Densidade Populacional\n 6. PIB per Capita\n");
      printf("Digite o número de mais 1 atributo para competir nesta rodada: ");
      scanf("%u", &escolha2Jogador);

      if(escolha2Jogador == escolha1Jogador || (escolha2Jogador < 1 || escolha2Jogador > 6)){
        printf("Valor inválido! Escolha um número entre 1 e 6, diferente do primeiro atributo escolhido.\n");
        printf("Saindo do jogo ......\n");
        
        return 1;
      }
      break;

    case 4:
      printf("\n##### Escolha do segundo atributo #####\n");
      printf("\n 1. População\n 2. Área\n 3. PIB\n 5. Densidade Populacional\n 6. PIB per Capita\n");
      printf("Digite o número de mais 1 atributo para competir nesta rodada: ");
      scanf("%u", &escolha2Jogador);

      if(escolha2Jogador == escolha1Jogador || (escolha2Jogador < 1 || escolha2Jogador > 6)){
        printf("Valor inválido! Escolha um número entre 1 e 6, diferente do primeiro atributo escolhido.\n");
        printf("Saindo do jogo ......\n");
        
        return 1;
      }
      break;
    
    case 5:
      printf("\n##### Escolha do segundo atributo #####\n");
      printf("\n 1. População\n 2. Área\n 3. PIB\n 4. Número de Pontos Turísticos\n 6. PIB per Capita\n");
      printf("Digite o número de mais 1 atributo para competir nesta rodada: ");
      scanf("%u", &escolha2Jogador);

      if(escolha2Jogador == escolha1Jogador || (escolha2Jogador < 1 || escolha2Jogador > 6)){
        printf("Valor inválido! Escolha um número entre 1 e 6, diferente do primeiro atributo escolhido.\n");
        printf("Saindo do jogo ......\n");
        
        return 1;
      }
    break;

    default:
      printf("\n##### Escolha do segundo atributo #####\n");
      printf("\n 1. População\n 2. Área\n 3. PIB\n 4. Número de Pontos Turísticos\n 5. Densidade Populacional\n");
      printf("Digite o número de mais 1 atributo para competir nesta rodada: ");
      scanf("%u", &escolha2Jogador);

      if(escolha2Jogador == escolha1Jogador || (escolha2Jogador < 1 || escolha2Jogador > 6)){
        printf("Valor inválido! Escolha um número entre 1 e 6, diferente do primeiro atributo escolhido.\n");
        printf("Saindo do jogo ......\n");
        
        return 1;
      }
    break;
  }

  // Comparação dos atributos escolhidos para o segundo embate
  switch (escolha2Jogador)
  {
  case 1:
    if (populacao > populacao2) { 
      sprintf(resultadoSegundoEmbate, "%lu (População da Carta #1)", populacao);
      numVitoriasCarta1++;

    } else {
      sprintf(resultadoSegundoEmbate, "%lu (População da Carta #2)", populacao2);
      numVitoriasCarta2++;
    }

    acc1 += populacao;
    acc2 += populacao2;
    break;

  case 2:
    if(area > area2){
      sprintf(resultadoSegundoEmbate, "%.2f (Área da Carta #1)", area);
      numVitoriasCarta1++;
    } else {
      sprintf(resultadoSegundoEmbate, "%.2f (Área da Carta #2)", area2);
      numVitoriasCarta2++;
    }

    acc1 += area;
    acc2 += area2;
    break;

  case 3:
    if(pib > pib2){
      sprintf(resultadoSegundoEmbate, "%.2f (PIB da Carta #1)", pib/1000000000);
      numVitoriasCarta1++;

    } else {
      sprintf(resultadoSegundoEmbate, "%.2f (PIB da Carta #2)", pib2);
      numVitoriasCarta2++;
    }

    acc1 += pib*1000000000;
    acc2 += pib2*1000000000;
    break;

  case 4:
    if(numPontosTuristicos > numPontosTuristicos2){
      sprintf(resultadoSegundoEmbate, "%d (Número de Pontos Turísticos da Carta #1)", numPontosTuristicos);
      numVitoriasCarta1++;

    } else {
      sprintf(resultadoSegundoEmbate, "%d (Número de Pontos Turísticos da Carta #2)", numPontosTuristicos2);
      numVitoriasCarta2++;
    }

    acc1 += numPontosTuristicos;
    acc2 += numPontosTuristicos2;
    break;

  case 5:
    if(densPopulacional < densPopulacional2){
      sprintf(resultadoSegundoEmbate, "%.2f (Densidade Populacional da Carta #1)", densPopulacional);
      numVitoriasCarta1++;

    } else {
      sprintf(resultadoSegundoEmbate, "%.2f (Densidade Populacional da Carta #2)", densPopulacional2);
      numVitoriasCarta2++;
    }

    acc1 += densPopulacional;
    acc2 += densPopulacional2;
    break;

  default:
    if(pibPerCapita > pibPerCapita2){
      sprintf(resultadoSegundoEmbate, "%.2f (PIB per Capita da Carta #1)", pibPerCapita/1000000000);
      numVitoriasCarta1++;

    } else {
      sprintf(resultadoSegundoEmbate, "%.2f (PIB per Capita da Carta #2)", pibPerCapita2/1000000000);
      numVitoriasCarta2++;
    }

    acc1 += pibPerCapita*1000000000;
    acc2 += pibPerCapita2*1000000000;
    break;
  }

  // Apresentação dos resultados dos embates, considerando empates (anunciar empate se houver), quais atributos foram escolhidos e o número de vitórias de cada carta
  printf("\n##### Resultados dos embates #####\n");
  switch(escolha1Jogador){
    case 1:
      printf("Atributo escolhido no primeiro embate: População\n");
      break;
    case 2:
      printf("Atributo escolhido no primeiro embate: Área\n");
      break;
    case 3:
      printf("Atributo escolhido no primeiro embate: PIB\n");
      break;
    case 4:
      printf("Atributo escolhido no primeiro embate: Número de Pontos Turísticos\n");
      break;
    case 5:
      printf("Atributo escolhido no primeiro embate: Densidade Populacional\n");
      break;
    default:
      printf("Atributo escolhido no primeiro embate: PIB per Capita\n");
      break;
  }
  printf("Vencedor: %s\n", resultadoPrimeiroEmbate);

  switch(escolha2Jogador){
    case 1:
      printf("Atributo escolhido no segundo embate: População\n");
      break;
    case 2:
      printf("Atributo escolhido no segundo embate: Área\n");
      break;
    case 3:
      printf("Atributo escolhido no segundo embate: PIB\n");
      break;
    case 4:
      printf("Atributo escolhido no segundo embate: Número de Pontos Turísticos\n");
      break;
    case 5:
      printf("Atributo escolhido no segundo embate: Densidade Populacional\n");
      break;
    default:
      printf("Atributo escolhido no segundo embate: PIB per Capita\n");
      break;
  } 
  printf("Vencedor: %s\n", resultadoSegundoEmbate);

  if(acc1 > acc2){
    numVitoriasCarta1++;
  } else {
    numVitoriasCarta2++;
  }

  // Apresentação do resultado final, considerando o número de vitórias de cada carta e o acumulado dos atributos comparados
  if(numVitoriasCarta1 > numVitoriasCarta2){
    printf("\n##### Resultado Final Acumulado #####\n");
    printf("Vencedora: Carta #1 (%s - %s)\n", codigoCarta, nomeCidade);
  } else if (numVitoriasCarta2 > numVitoriasCarta1){
    printf("\n##### Resultado Final Acumulado #####\n");
    printf("Vencedora: Carta #2 (%s - %s)\n", codigoCarta2, nomeCidade2);
  } else {
    printf("\n##### Resultado Final Acumulado #####\n");
    printf("Empate entre as cartas!\n");
  }

  return 0;
} 
