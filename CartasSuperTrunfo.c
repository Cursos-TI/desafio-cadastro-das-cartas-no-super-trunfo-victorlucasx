#include <stdio.h>

typedef struct {
    char estado[21];
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
} Carta;

// Função para calcular os dados derivados da carta
void calcularDados(Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000000) / carta->populacao;  // PIB em reais
    carta->superPoder = (float)carta->populacao + carta->area + (carta->pib * 1000000000) +
                        carta->pontosTuristicos + carta->pibPerCapita + (1.0f / carta->densidadePopulacional);
}

// Função para imprimir uma carta
void imprimirCarta(Carta carta, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

int main() {
    Carta carta1, carta2;

    // Entrada de dados
    printf("Cadastro da Carta 1:\n");
    printf("Estado: "); scanf("%20s", carta1.estado);
    printf("Código: "); scanf("%3s", carta1.codigo);
    printf("Cidade: "); scanf("%49s", carta1.nomeCidade);
    printf("População: "); scanf("%lu", &carta1.populacao);
    printf("Área: "); scanf("%f", &carta1.area);
    printf("PIB (em bilhões): "); scanf("%f", &carta1.pib);
    printf("Pontos Turísticos: "); scanf("%d", &carta1.pontosTuristicos);

    printf("\nCadastro da Carta 2:\n");
    printf("Estado: "); scanf("%20s", carta2.estado);
    printf("Código: "); scanf("%3s", carta2.codigo);
    printf("Cidade: "); scanf("%49s", carta2.nomeCidade);
    printf("População: "); scanf("%lu", &carta2.populacao);
    printf("Área: "); scanf("%f", &carta2.area);
    printf("PIB (em bilhões): "); scanf("%f", &carta2.pib);
    printf("Pontos Turísticos: "); scanf("%d", &carta2.pontosTuristicos);

    // Cálculos
    calcularDados(&carta1);
    calcularDados(&carta2);

    // Exibir cartas
    imprimirCarta(carta1, 1);
    imprimirCarta(carta2, 2);

    // Comparações
    printf("\nComparação de Cartas:\n");

    printf("População: Carta %d venceu (%d)\n",
           carta1.populacao > carta2.populacao ? 1 : 2,
           carta1.populacao > carta2.populacao ? 1 : 2);

    printf("Área: Carta %d venceu (%d)\n",
           carta1.area > carta2.area ? 1 : 2,
           carta1.area > carta2.area ? 1 : 2);

    printf("PIB: Carta %d venceu (%d)\n",
           carta1.pib > carta2.pib ? 1 : 2,
           carta1.pib > carta2.pib ? 1 : 2);

    printf("Pontos Turísticos: Carta %d venceu (%d)\n",
           carta1.pontosTuristicos > carta2.pontosTuristicos ? 1 : 2,
           carta1.pontosTuristicos > carta2.pontosTuristicos ? 1 : 2);

    printf("Densidade Populacional: Carta %d venceu (%d)\n",
           carta1.densidadePopulacional < carta2.densidadePopulacional ? 1 : 2,
           carta1.densidadePopulacional < carta2.densidadePopulacional ? 1 : 2);

    printf("PIB per Capita: Carta %d venceu (%d)\n",
           carta1.pibPerCapita > carta2.pibPerCapita ? 1 : 2,
           carta1.pibPerCapita > carta2.pibPerCapita ? 1 : 2);

    printf("Super Poder: Carta %d venceu (%d)\n",
           carta1.superPoder > carta2.superPoder ? 1 : 2,
           carta1.superPoder > carta2.superPoder ? 1 : 2);

    return 0;
}
