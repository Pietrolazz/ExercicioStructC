#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define NUM_CARTAS 52
#define NUM_JOGADORES 2
#define CARTAS_POR_JOGADOR 5

typedef struct {
    char naipe[10];
    char valor[3];
} Carta;

void criarBaralho(Carta baralho[]) {
    const char* naipes[] = {"Copas", "Ouros", "Espadas", "Paus"};
    const char* valores[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    int index = 0;
    int i;
    int j;
    for ( i = 0; i < 4; i++) {
        for ( j = 0; j < 13; j++) {
            strcpy(baralho[index].naipe, naipes[i]);
            strcpy(baralho[index].valor, valores[j]);
            index++;
        }
    }
}

void embaralharBaralho(Carta baralho[]) {
	int i;
	int j;
    for ( i = 0; i < NUM_CARTAS; i++) {
         j = rand() % NUM_CARTAS;
        Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

void distribuirCartas(Carta baralho[], Carta mao[][CARTAS_POR_JOGADOR]) {
	int i; 
	int j;
    for ( i = 0; i < NUM_JOGADORES; i++) {
        for ( j = 0; j < CARTAS_POR_JOGADOR; j++) {
            mao[i][j] = baralho[i * CARTAS_POR_JOGADOR + j];
        }
    }
}

void exibirMaos(Carta mao[][CARTAS_POR_JOGADOR]) {
	int i; 
	int j;
    for ( i = 0; i < NUM_JOGADORES; i++) {
        printf("Jogador %d:\n", i + 1);
        for ( j = 0; j < CARTAS_POR_JOGADOR; j++) {
            printf("%s de %s\n", mao[i][j].valor, mao[i][j].naipe);
        }
        printf("\n");
    }
}

int main() {
	setlocale (LC_ALL, "Portuguese");
    Carta baralho[NUM_CARTAS];
    Carta mao[NUM_JOGADORES][CARTAS_POR_JOGADOR];

    srand(time(NULL));
    criarBaralho(baralho);
    embaralharBaralho(baralho);
    distribuirCartas(baralho, mao);
    exibirMaos(mao);

    return 0;
}
